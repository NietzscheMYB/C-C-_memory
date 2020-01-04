#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;

////��׮ ���Դ���
////�����Ļ����ȡһ�������Ķ����thread cache
//size_t CentralCache::FetchRangeObj(void*& start, void*&end, size_t n, size_t bytes)
//{
//	start = malloc(bytes*n);
//	end = (char*)start + bytes*(n - 1);
//	void* cur = start;
//	while (cur <= end)
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
	Span* span = spanlist->begin();//��ȡ��ͷ˫��ѭ������ͷ�ڵ����һ���ڵ�

	while (span != spanlist->end()) //ѭ����һ���ж����span
	{
		if (span->_objlist != nullptr)
		{
			return span;
		}
		span = span->_next;
	}

	//�ߵ�����˵����spanlistû��span����Ҫ��pagecache����
	//��pagecache����һ���µĺ��ʴ�С��span
	size_t npage = ClasssSize::NumMovePage(bytes);
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	//��span�ڴ��и��һ����bytes��С�Ķ��������
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);//��ȡ�����span�Ŀ�ʼ�ĵ�ַ
	char* end = start + (newspan->_npage << PAGE_SHIFT);//��ȡ�����span�Ľ�����λ��
	char* cur = start;
	char* next = cur + bytes;

	while (next < end)       //�������span����byte��С�ֿ���ͨ��ָ��������
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

//�����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*&end, size_t num, size_t bytes)
{
	//�ȶ��룡��
	size_t index = ClasssSize::Index(bytes);
	SpanList* spanlist = &_spanlist[index];//�ҵ��ô�С�ڴ��Ӧ���������λ��

	//�Ե�ǰͰ���м���RAII˼��
	std::unique_lock<std::mutex> lock(spanlist->_mtx);

	//��ȡһ��span
	Span* span = GetOneSpan(spanlist, bytes);

	void* cur = span->_objlist;
	void* prev = cur;

	size_t fetchnum = 0;
	
	//��� ��Ҫ10����������ֻ��9�����ҵ�Ȼ����ҲҪ9��
	while (cur != nullptr&&fetchnum < num) //һ�����cur����ѭ�����ڶ������fetech�˳�ѭ��
	{                                      //�ڶ�Ӧ��span���Ҷ���������ȡnum������
										   //�������num��������ȫ��ȡ��
		prev = cur;
		cur = NEXT_OBJ(cur);
		++fetchnum;
	}
	start = span->_objlist;
	end = prev;
	NEXT_OBJ(end) = nullptr;

	//�޸�span��oblist��span��_objlistָ��ʣ�����
	span->_objlist = cur;
	//�Ѿ�����fetchnum����ʹ�ü�������
	span->_usecount += fetchnum;

	return fetchnum;
}


void CentralCache::ReleaseListToSpans(void* start,size_t bytes)
{
	size_t index = ClasssSize::Index(bytes);
	SpanList* spanlist = &_spanlist[index];

	//std::unique_lock<std::mutex> _lock(_mtx);

	while (start)
	{
		void* next = NEXT_OBJ(start);

		//�ҵ�start�ڴ���Ӧ��ҳ��ӳ���span
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);
		NEXT_OBJ(start) = span->_objlist;//��start�ڴ��ҵ���Ӧ��span��
		span->_objlist = start;

		//usecount==0 ��ʾspan�г��Ķ���ȫ���ջ�
		//�ͷ�span�ص�PageCache���кϲ�
		if (--span->_usecount == 0)
		{
			spanlist->Erase(span);//��span��spanlist������ȥ��

			span->_next = nullptr;
			span->_prev = nullptr;
			span->_objsize = 0;
			span->_objlist = nullptr;

			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}
		start = next;
	}

}