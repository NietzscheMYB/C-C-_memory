#pragma once
#include"Common.h"
#include"ThreadCache.h"

void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)
	{
		return malloc(size);
	}
	else{
		//ͨ��tls����ȡ�߳��Լ���threadcache
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
			//cout << std::this_thread::get_id()<<"->" << endl;

		}

		return tls_threadcache->Allocate(size);
		//return nullptr;
	}
}


void ConcurrentFree(void* ptr,size_t size)
{
	if (size > MAXBYTES)
	{
		return free(ptr);
	}
	else{
		tls_threadcache->Deallocate(ptr, size);
	}
}