#include"CentralCache.h"
#include"PageCache.h"

CentralCache CentralCache::_inst;

//��׮ ���Դ���
//�����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*&start,void*&end,size_t n,size_t bytes)
{
	start = malloc(bytes*n);
	end = (char*)start + bytes*(n - 1);
	void* cur = start;
	while (cur < end)
	{
		void* next = (char*)cur + bytes;
		NEXT_OBJ(cur) = next;
		cur = next;
	}
	NEXT_OBJ(end) = nullptr;
	return n;
}