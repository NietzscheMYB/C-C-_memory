#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;

////打桩 测试代码
////从中心缓存获取一定数量的对象给thread cache
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

	//走到这里说明，spanlist没有span，需要像pagecache申请
	//向pagecache申请一个新的合适大小的span
	size_t npage = ClasssSize::NumMovePage(bytes);
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	//将span内存切割成一个个bytes大小的对象挂起来
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);//相当于除
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

	//将newspan插入到spanlist中
	spanlist->PushFront(newspan);

	return newspan;
}

//从中心缓存获取一定数量的对象给thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*&end, size_t num, size_t bytes)
{
	//先对齐！！
	size_t index = ClasssSize::Index(bytes);
	SpanList* spanlist = &_spanlist[index];

	//对当前桶进行加锁RAII思想
	std::unique_lock<std::mutex> lock(spanlist->_mtx);

	//获取一个span
	Span* span = GetOneSpan(spanlist, bytes);

	void* cur = span->_objlist;
	void* prev = cur;

	size_t fetchnum = 0;
	
	//类比 我要10个，但现在只有9个，我当然还是也要9个
	while (cur != nullptr&&fetchnum < num) //一种情况cur跳出循环，第二种情况fetech退出循环
	{
		prev = cur;
		cur = NEXT_OBJ(cur);
		++fetchnum;
	}
	start = span->_objlist;
	end = prev;
	NEXT_OBJ(end) = nullptr;

	//修改span的oblist
	span->_objlist = cur;
	//已经用了fetchnum对象
	span->_usecount += fetchnum;

	return fetchnum;
}