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
	Span* span = spanlist->begin();//获取带头双向循环链表头节点的下一个节点

	while (span != spanlist->end()) //循环找一个有对象的span
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
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);//获取申请的span的开始的地址
	char* end = start + (newspan->_npage << PAGE_SHIFT);//获取申请的span的结束的位置
	char* cur = start;
	char* next = cur + bytes;

	while (next < end)       //将申请的span按照byte大小分开，通过指针连起来
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
	SpanList* spanlist = &_spanlist[index];//找到该大小内存对应自由链表的位置

	//对当前桶进行加锁RAII思想
	std::unique_lock<std::mutex> lock(spanlist->_mtx);

	//获取一个span
	Span* span = GetOneSpan(spanlist, bytes);

	void* cur = span->_objlist;
	void* prev = cur;

	size_t fetchnum = 0;
	
	//类比 我要10个，但现在只有9个，我当然还是也要9个
	while (cur != nullptr&&fetchnum < num) //一种情况cur跳出循环，第二种情况fetech退出循环
	{                                      //在对应的span悬挂对象链表中取num个对象
										   //如果不够num个对象，则全部取出
		prev = cur;
		cur = NEXT_OBJ(cur);
		++fetchnum;
	}
	start = span->_objlist;
	end = prev;
	NEXT_OBJ(end) = nullptr;

	//修改span的oblist，span的_objlist指向剩余对象
	span->_objlist = cur;
	//已经用了fetchnum对象，使用计数增加
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

		//找到start内存块对应的页号映射的span
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);
		NEXT_OBJ(start) = span->_objlist;//将start内存块挂到对应的span里
		span->_objlist = start;

		//usecount==0 表示span切出的对象全部收回
		//释放span回到PageCache进行合并
		if (--span->_usecount == 0)
		{
			spanlist->Erase(span);//将span从spanlist链表中去掉

			span->_next = nullptr;
			span->_prev = nullptr;
			span->_objsize = 0;
			span->_objlist = nullptr;

			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}
		start = next;
	}

}