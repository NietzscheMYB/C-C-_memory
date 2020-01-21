#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;

//��׮ ���Դ���
//�����Ļ����ȡһ�������Ķ����thread cache
//size_t CentralCache::FetchRangeObj(void*&start,void*&end,size_t n,size_t bytes)
//{
//	start = malloc(bytes*n);
//	end = (char*)start + bytes*(n - 1);
//	void* cur = start;
//	while (cur < end)
//	{
//		void* next = (char*)cur + bytes;
//		NEXT_OBJ(cur) = next;
//		cur = next;
//	}
//	NEXT_OBJ(end) = nullptr;
//	return n;
//}

Span* CentralCache::GetOneSpan(SpanList* spanlist, size_t bytes)
{
	Span* span = spanlist->begin();
	while (span != spanlist->end())
	{
		if (span->_objlist != nullptr)
		{
			return span;
		}
		span = span->_next;
	}

	//˵������cacheû����Ҫ��pagecache����
	//��pagecache����һ���µĺ��ʴ�С��span
	size_t npage = ClassSize::NumMovePage(bytes);
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	//��span�ڴ��и��һ����bytes��С�Ķ��������
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);
	char* end = start + (newspan->_npage << PAGE_SHIFT);
	char* cur = start;
	char* next = cur + bytes;

	while (next < end)
	{
		NEXT_OBJ(cur) = next;
		cur = next;
		next = cur + bytes;
	}
	NEXT_OBJ(cur) = nullptr;
	newspan->_objlist = start;
	newspan->_objsize = bytes;
	newspan->_usecount = 0;

	//��newspan���뵽spanlist��
	spanlist->PushFront(newspan);
	return newspan;

}


size_t CentralCache::FetchRangeObj(void*&start, void*&end, size_t n, size_t bytes)
{
	size_t index = ClassSize::Index(bytes);
	SpanList* spanlist = &_spanlist[index];

	//�Ե�ǰͰ���м��� RAII˼�룬   ����һ�п�ʼ��Ϊ�˼��������ܶ�
	std::unique_lock<std::mutex> lock(spanlist->_mtx);

	Span* span = GetOneSpan(spanlist, bytes);

	void* cur = span->_objlist;
	void* prev = cur;

	size_t fetchnum = 0;
	while (cur != nullptr&&fetchnum < n)  //һ�����cur����ѭ�����ڶ������fetech�˳�ѭ��
	{
		prev = cur;
		cur = NEXT_OBJ(cur);
		fetchnum++;
	}
	//��span��objlist����
	start = span->_objlist;
	end = prev;
	NEXT_OBJ(end) = nullptr;

	//����󣬶�span��objlist�����޸�
	span->_objlist = cur;
	span->_usecount += fetchnum;

	//��һ��spanΪ��ʱ����span�ƶ���β�ϣ���߲���Ч��
	if (span->_objlist == nullptr)
	{
		spanlist->Erase(span);
		spanlist->PushBack(span);
	}
	return fetchnum;
}


//��һ�������Ķ����ͷŵ�span�����
void CentralCache::ReleaseListToSpans(void* start, size_t byte)
{
	size_t index = ClassSize::Index(byte);
	SpanList* spanlist = &_spanlist[index];

	std::unique_lock<std::mutex> lock(spanlist->_mtx);
	while (start)
	{
		void* next = NEXT_OBJ(start);
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);
		
		//���ͷŶ���ص��յ�span���ѿյ�span�ƶ���ͷ�ϣ���߲���Ч��
		if (span->_objlist == nullptr)
		{
			spanlist->Erase(span);
			spanlist->PushFront(span);
		}
	
		//ͷ��
		NEXT_OBJ(start) = span->_objlist;
		span->_objlist = start;
		//span usecount=0��ʾspan�г�ȥ�Ķ��󶼻�������
		//�ͷ�span�ص�pagecache���кϲ�
		if (--span->_usecount == 0)
		{
			spanlist->Erase(span);
			span->_objlist = nullptr;
			span->_objsize = 0;
			span->_prev = nullptr;
			span->_next = nullptr;

			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}
		start = next;	
	}

}