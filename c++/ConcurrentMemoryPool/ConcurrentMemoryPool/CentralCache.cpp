#include"CentralCache.h"


CentralCache CentralCache::_inst;

// 从中心缓存获取一定数量的对象给thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t size)
{

}