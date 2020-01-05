#include"ThreadCache.h"
#include"CentralCache.h"
#include<iostream>

////�����Ŀ�ȡ�ڴ�
//void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
//{
//	FreeList* freelist = &_freelist[index];
//	
//	//��������ȡ������һ������ʣ��Ĺҵ�����������
//	size_t num = 10;
//
//	void* start, *end;
//	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);
//
//	if (fetchnum > 1)
//	{
//		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
//	}
//	NEXT_OBJ(start) = nullptr;
//	return start;
//
//}


//�����Ŀ�ȡ�ڴ�
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];

	size_t num_to_move =min(ClasssSize::NumMoveSize(byte), freelist->MaxSize());//num_to_move����Ҫ�������ĸ���
	void *start, *end;
	//fetchnum��ʵ���������ĸ���
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, byte);
	if (fetchnum > 1)
	{
		freelist->PushRange(start, end, fetchnum - 1);  //�����˵�һ���ڴ��������ڴ��ҵ�freelist��ȥ
	}

	if (num_to_move == freelist->MaxSize())
	{
		int tmp = num_to_move;
		freelist->SetMaxSize(++tmp);
	}

	return start;  //����һ������
}


//����size�ֽڴ�С���ڴ�
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);
	//���¶���ȡ��
	size = ClasssSize::Roundup(size);
	size_t index = ClasssSize::Index(size);//�����±�
	//��Ӧ����������
	FreeList* freelist = &_freelist[index];

	if (!freelist->Empty())
	{
		return freelist->Pop();
	}
	else{
		//������Cache��ȥ��
		return FetchFromCentralCache(index, size);
	}
}


//���������¹��صĶ���̫�࣬��ʼ����
void ThreadCache::ListTooLong(FreeList* freelist,size_t bytes)
{
	void* start = freelist->Clear();
	CentralCache::GetInstance()->ReleaseListToSpans(start,bytes);
}


//�ͷ��ڴ�(����)
void ThreadCache::Deallocate(void* ptr, size_t bytes)//�������
{
	assert(bytes <= MAXBYTES);
	bytes = ClasssSize::Roundup(bytes);
	size_t index = ClasssSize::Index(bytes);

	//��Ӧ����������
	FreeList* freelist = &_freelist[index];
	//ֱ�ӽ��ͷŵ��ڴ棬���뵽����������
	freelist->Push(ptr);

	//�����������еĶ������������CentralCacheһ���Ի�ȡ�Ķ������ʱ
	//��ʼ���ն���CentralCache
	if (freelist->Size() >= freelist->MaxSize())
	{
		ListTooLong(freelist, bytes);
	}
}