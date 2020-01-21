#include"ThreadCache.h"
#include"CentralCache.h"

//��centralcache��ȡһ���ڴ�
void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];

	////������ȡ������һ������ʣ��Ĺҵ�����������
	//size_t num = 10;


	size_t num_to_move = min(ClassSize::NumMoveSize(byte), freelist->MaxSize());//NumMoveSize�������ޣ������513


	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, byte);
	if (fetchnum > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
	}

	if (num_to_move == freelist->MaxSize())
	{
		freelist->SetMaxSize(num_to_move + 1);
	}

	return start;
}

void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);
	//���¶���ȡ��
	size = ClassSize::Roundup(size);
	//�����±�
	size_t index = ClassSize::Index(size);

	//�ҵ���Ӧ����������
	FreeList* freelist = &_freelist[index];

	if (!freelist->Empty())
	{
		return freelist->Pop();
	}
	else{
		//ȥ����cacheȥȡ
		return FetchFromCentralCache(index, size);
	}

}

//���
void ThreadCache::Deallocate(void* ptr, size_t byte)
{
	assert(byte <= MAXBYTES);
	byte = ClassSize::Roundup(byte);
	size_t index = ClassSize::Index(byte);
	//��Ӧ����������
	FreeList* freelist = &_freelist[index];
	//���ص���Ӧ������������
	freelist->Push(ptr);

	//���������������������һ�����������Ļ����ƶ�������ʱ
	//��ʼ���ն������Ļ���
	if (freelist->Size() >= freelist->MaxSize())
	{ 
		ListTooLong(freelist, byte);
	}

}

void ThreadCache::ListTooLong(FreeList* freelist, size_t size)
{
	void* start = freelist->Clear();
	CentralCache::GetInstance()->ReleaseListToSpans(start, size);
}











