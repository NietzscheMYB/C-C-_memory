#pragma once
#include"Common.h"
//1.page cache 是一个以页为单位的span自由链表
//2.为了保证全局只有唯一的pagecache，这个类被设计成了单例模式

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);

	//获取对象到span的映射
	Span* MapObjectToSpan(void* obj);

	//释放空闲span回到Pagecache，并合并相邻的span
	void ReleaseSpanToPageCache(Span* span);
private:
	SpanList _pagelist[NLISTS];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache& operator=(const PageCache&) = delete;
	static PageCache _inst;

	std::mutex _mtx;
	std::unordered_map<PageID, Span*> _id_span_map;
};