//不分系统
#pragma once
#include"Common.h"

class ThreadCache
{
public:
	void* Allocate(size_t size);//分配内存
	void Deallocate(void* ptr,size_t size);//解除分配
	// 从中心缓存获取对象
	void* FetchFromCentralCache(size_t index, size_t size);
private:
	//自由链表，大小可控，
	FreeList _freelist[NLISTS];
};

