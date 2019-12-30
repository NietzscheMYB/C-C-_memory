//����ϵͳ

#pragma once
#include"Common.h"

//�̻߳��棬Ч�ʸߣ���Ϊû����
class ThreadCache
{
public:
	void* Allocate(size_t size);//�����ڴ�
	void Deallocate(void* ptr, size_t size);//�������
	//�����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index, size_t size);
	//�����ж���̫�࣬��ʼ���ա�
	void ListTooLong(FreeList* freelist);

private:
	//����������С�ɿ�
	FreeList _freelist[NLISTS];

};

//��̬tsl�����������̶߳���һ��������
static _declspec(thread) ThreadCache* tls_threadcache = nullptr;