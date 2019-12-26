#include"ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::FetchFromCentralCache(size_t index,size_t byte)
{
	FreeList* freelist = &_freelist[index];
	//������ȡ������һ������ʣ��Ĺҵ����������ϣ�����
	size_t num = 10;
	void*start, *end;
	size_t fetchnum=CentralCache::GetInstance()->FetchRangeObj(start,end,num,byte);
	if (fetchnum == 1)
	{
		return start;
	}
	//�����ȡ10��������1 ��������9���ҵ�����������
	freelist->PushRange(NEXT_OBJ(start),end,fetchnum-1);
	return start;
}


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
		//����cacheȥȡ
		return FetchFromCentralCache(index,size);
	}

}

void ThreadCache::Deallocate(void* ptr, size_t size)//�������
{
	assert(size <= MAXBYTES);
	size_t index = ClasssSize::Index(size);
	//��Ӧ����������
	FreeList& freelist = _freelist[index];
	freelist.Push(ptr);

	//ListToolong();


}