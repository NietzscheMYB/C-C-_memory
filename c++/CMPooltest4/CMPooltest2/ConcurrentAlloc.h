//#include"ThreadCache.h"
//
//void* Alloc(size_t byte)
//{
//	if (byte > 64 * 1024)
//	{
//		return malloc(byte);
//	}
//	else{
//
//		//ͨ��tls����ȡ�߳��Լ���threadcache
//		if (tls_threadcache == nullptr)
//		{
//			tls_threadcache = new ThreadCache;
//		}
//
//
//		return tls_threadcache->Allocate(byte);
//	}
//}
//
//void Delloc(void* ptr,size_t byte)
//{
//	tls_threadcache->Deallocate(ptr, byte);
//}

#pragma once
#include"Common.h"
#include"ThreadCache.h"
#include"PageCache.h"

void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)//  >64k           ����64K��4K���ж��룡������
	{
		size_t roudsize = ClassSize::_Roundup(size, PAGE_SHIFT);  //4k�Ķ�������12!!!
		//��ҳΪ��λ����
		size_t npage = roudsize >> PAGE_SHIFT;//�������ҳ
		Span* span = PageCache::GetInstance()->NewSpan(npage);
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);
		return ptr;
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


void ConcurrentFree(void* ptr)
{
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objsize;

	if (size > MAXBYTES)
	{
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);
	}
	else{
		tls_threadcache->Deallocate(ptr, size);
	}
}