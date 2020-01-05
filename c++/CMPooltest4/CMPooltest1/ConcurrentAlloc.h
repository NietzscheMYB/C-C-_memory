#pragma once
#include"Common.h"
#include"ThreadCache.h"


static void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)  //>64k
	{
		return malloc(size);
	}
	else{
		//通过tls,获取线程自己的threadcache
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
			//cout << std::this_thread::get_id() << "->" << endl;
		}
		return tls_threadcache->Allocate(size);
	}
}

static void ConcurrentFree(void* ptr, size_t size)
{
	if (size > MAXBYTES)
	{
		return free(ptr);
	}
	else{
		tls_threadcache->Deallocate(ptr, size);
	}
}