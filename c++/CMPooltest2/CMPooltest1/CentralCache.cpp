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
	Span* span = spanlist->begin();
	while (span != spanlist->end())
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
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);//�൱�ڳ�
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

//�����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*&end, size_t num, size_t bytes)
{
	//�ȶ��룡��
	size_t index = ClasssSize::Index(bytes);
	SpanList* spanlist = &_spanlist[index];

	//�Ե�ǰͰ���м���RAII˼��
	std::unique_lock<std::mutex> lock(spanlist->_mtx);

	//��ȡһ��span
	Span* span = GetOneSpan(spanlist, bytes);

	void* cur = span->_objlist;
	void* prev = cur;

	size_t fetchnum = 0;
	
	//��� ��Ҫ10����������ֻ��9�����ҵ�Ȼ����ҲҪ9��
	while (cur != nullptr&&fetchnum < num) //һ�����cur����ѭ�����ڶ������fetech�˳�ѭ��
	{
		prev = cur;
		cur = NEXT_OBJ(cur);
		++fetchnum;
	}
	start = span->_objlist;
	end = prev;
	NEXT_OBJ(end) = nullptr;

	//�޸�span��oblist
	span->_objlist = cur;
	//�Ѿ�����fetchnum����
	span->_usecount += fetchnum;

	return fetchnum;
}