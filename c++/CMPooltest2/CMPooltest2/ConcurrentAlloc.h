#include"ThreadCache.h"

void* Alloc(size_t byte)
{
	if (byte > 64 * 1024)
	{
		return malloc(byte);
	}
	else{

		//通过tls，获取线程自己的threadcache
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
		}


		return tls_threadcache->Allocate(byte);
	}
}

void Delloc(void* ptr,size_t byte)
{
	tls_threadcache->Deallocate(ptr, byte);
}