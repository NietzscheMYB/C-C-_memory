//����ϵͳ
#pragma once
#include"Common.h"

class ThreadCache
{
public:
	void* Allocate(size_t size);//�����ڴ�
	void Deallocate(void* ptr,size_t size);//�������
	// �����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index, size_t size);
private:
	//����������С�ɿأ�
	FreeList _freelist[NLISTS];
};

