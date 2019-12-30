#include"ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];
	
	//先批量获取，返回一个，将剩余的挂到自由链表上
	size_t num = 10;

	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);

	if (fetchnum > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
	}
	NEXT_OBJ(start) = nullptr;
	return start;

}

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

void ThreadCache::Deallocate(void* ptr, size_t size)//解除分配
{
	assert(size <= MAXBYTES);
	size_t index = ClasssSize::Index(size);

	//对应的自由链表
	FreeList* freelist = &_freelist[index];
	//直接将释放的内存，插入到自由链表上
	freelist->Push(ptr);

	//ListToolong();

}