#include"ThreadCache.h"
#include"CentralCache.h"

//从centralcache获取一块内存
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];

	////批量获取，返回一个，将剩余的挂到自由链表上
	//size_t num = 10;


	size_t num_to_move = min(ClassSize::NumMoveSize(byte), freelist->MaxSize());//NumMoveSize决定上限！！最大513


	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, byte);
	if (fetchnum > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
	}

	if (num_to_move == freelist->MaxSize())
	{
		freelist->SetMaxSize(num_to_move + 1);
	}

	return start;
}

void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);
	//重新对齐取整
	size = ClassSize::Roundup(size);
	//计算下标
	size_t index = ClassSize::Index(size);

	//找到对应的自由链表
	FreeList* freelist = &_freelist[index];

	if (!freelist->Empty())
	{
		return freelist->Pop();
	}
	else{
		//去中心cache去取
		return FetchFromCentralCache(index, size);
	}

}

//解除
void ThreadCache::Deallocate(void* ptr, size_t byte)
{
	assert(byte <= MAXBYTES);
	byte = ClassSize::Roundup(byte);
	size_t index = ClassSize::Index(byte);
	//对应的自由链表
	FreeList* freelist = &_freelist[index];
	//返回到对应的自由链表中
	freelist->Push(ptr);

	//当自由链表对象数量超过一次批量从中心缓存移动的数量时
	//开始回收对象到中心缓存
	if (freelist->Size() >= freelist->MaxSize())
	{ 
		ListTooLong(freelist, byte);
	}

}

void ThreadCache::ListTooLong(FreeList* freelist, size_t size)
{
	void* start = freelist->Clear();
	CentralCache::GetInstance()->ReleaseListToSpans(start, size);
}











