#include"ThreadCache.h"
#include"CentralCache.h"
#include<iostream>

////从中心块取内存
//void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
//{
//	FreeList* freelist = &_freelist[index];
//	
//	//先批量获取，返回一个，将剩余的挂到自由链表上
//	size_t num = 10;
//
//	void* start, *end;
//	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);
//
//	if (fetchnum > 1)
//	{
//		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
//	}
//	NEXT_OBJ(start) = nullptr;
//	return start;
//
//}


//从中心块取内存
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];

	size_t num_to_move =min(ClasssSize::NumMoveSize(byte), freelist->MaxSize());//num_to_move是想要申请对象的个数
	void *start, *end;
	//fetchnum是实际申请对象的个数
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, byte);
	if (fetchnum > 1)
	{
		freelist->PushRange(start, end, fetchnum - 1);  //将除了第一个内存块的其他内存块挂到freelist上去
	}

	if (num_to_move == freelist->MaxSize())
	{
		int tmp = num_to_move;
		freelist->SetMaxSize(++tmp);
	}

	return start;  //将第一个返回
}


//开辟size字节大小的内存
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);
	//重新对齐取整
	size = ClasssSize::Roundup(size);
	size_t index = ClasssSize::Index(size);//计算下标
	//对应的自由链表
	FreeList* freelist = &_freelist[index];

	if (!freelist->Empty())
	{
		return freelist->Pop();
	}
	else{
		//从中心Cache中去拿
		return FetchFromCentralCache(index, size);
	}
}


//自由链表下挂载的对象太多，开始回收
void ThreadCache::ListTooLong(FreeList* freelist,size_t bytes)
{
	void* start = freelist->Clear();
	CentralCache::GetInstance()->ReleaseListToSpans(start,bytes);
}


//释放内存(回收)
void ThreadCache::Deallocate(void* ptr, size_t bytes)//解除分配
{
	assert(bytes <= MAXBYTES);
	bytes = ClasssSize::Roundup(bytes);
	size_t index = ClasssSize::Index(bytes);

	//对应的自由链表
	FreeList* freelist = &_freelist[index];
	//直接将释放的内存，插入到自由链表上
	freelist->Push(ptr);

	//当自由链表中的对象个数超过从CentralCache一次性获取的对象个数时
	//开始回收对象到CentralCache
	if (freelist->Size() >= freelist->MaxSize())
	{
		ListTooLong(freelist, bytes);
	}
}