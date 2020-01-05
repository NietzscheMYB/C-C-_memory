#pragma once

#include"Common.h"

//1.page cache 是一个以页为单位的span自由链表
//2.为了保证全局只有唯一的page cache，这个类被设计成了单例模式

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}
	//获取一个span
	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);


	//获取从页号到span的映射
	Span* MapObjectToSpan(void* obj);

	//释放空闲span回到Pagecache，合并相邻的span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pagelist[NPAGES];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache operator=(const PageCache&) = delete;
	static PageCache _inst;

	std::mutex  _mtx;
	//用map或unordered_map存放PagID，Span* 的映射关系，用于合并
	//std::unordered_map<PageID, Span*> _id_span_map;
	std::map<PageID, Span*> _id_span_map;

};