#include"ThreadCache.h"

void* Alloc(size_t byte)
{
	if (byte > 64 * 1024)
	{
		return malloc(byte);
	}
	else{

		//ͨ��tls����ȡ�߳��Լ���threadcache
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