#include"ThreadCache.h"
#include"CentralCache.h"

//从centralcache获取一块内存
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];

	//批量获取，返回一个，将剩余的挂到自由链表上
	size_t num = 10;
	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);
	if (fetchnum > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
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

}













