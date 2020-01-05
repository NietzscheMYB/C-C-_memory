#include"PageCache.h"

//实例化单例对象
PageCache PageCache::_inst;


/*
NewSpan获取一段对应的Span，Span是整数倍的页
该函数内不做页内存的切分，交给上层CentralCache做
*/
Span* PageCache::NewSpan(size_t npage)
{
	//解决对递归函数加锁的方式
	std::unique_lock<std::mutex> _lock(_mtx);
	return _NewSpan(npage);
}

Span* PageCache::_NewSpan(size_t npage)
{
	//首先对应的PageList上看有没有空闲的Span
	if (!_pagelist[npage].Empty())
	{
		//目标pagelist不为空
		return _pagelist[npage].PopFront();
	}

	//到这里即说明目标pagelist为空，需要向下寻找，进行分割，从下一个位置开始
	for (size_t i = npage + 1; i < NPAGES; ++i)
	{
		
		SpanList*pagelist = &_pagelist[i];
		if (!pagelist->Empty())
		{
			//找到的pagelist不为空
			Span* span = pagelist->PopFront();
			Span* split = new Span;
			split->_pageid = span->_pageid + span->_npage - npage;
			split->_npage = npage;
			span->_npage -= npage;

			//将剩余大块内存挂载到pageCache的相应位置下
			_pagelist[span->_npage].PushFront(span);

			//只有正在使用的页才需要建立映射
			for (size_t i = 0; i < split->_npage; ++i)
			{
				//建立页的映射关系，xxx页--xxx页都为split管理
				_id_span_map[split->_pageid + i] = split;
			}

			return split;
		}
	}

	//走到这里说明下面没有可以用来分割的Pagelist,需要重新申请内存
	void* ptr = VirtualAlloc(NULL, (npage) << PAGE_SHIFT, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}

	//将新申请的内存挂载到最下面
	Span* maxspan = new Span;
	maxspan->_objlist = ptr;
	maxspan->_pageid = (PageID)ptr >> 12;
	maxspan->_npage = NPAGES - 1;
	_pagelist[NPAGES - 1].PushFront(maxspan);

	//递归调用自己
	return _NewSpan(npage);
}


//获取从页号到span的映射
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID pageid = (PageID)obj >> 12;//计算指针所在的页
	auto it = _id_span_map.find(pageid);//查找该页对应的管理页
	if (it == _id_span_map.end())
	{
		assert(false);
	}
	return it->second;
}

//释放空闲span回到Pagecache，合并相邻的span
void PageCache::ReleaseSpanToPageCache(Span* span)
{
	assert(span != nullptr);
	std::unique_lock<std::mutex> lock(_mtx);

	//向前合并
	auto previt = _id_span_map.find(span->_pageid - 1);//找span前一页的id是否在map中
	while (previt!=_id_span_map.end())
	{
		Span* prevspan = previt->second;//取出前一页pageid映射的span

		if (prevspan->_usecount != 0)//如果前一页映射的span没有全部归还，跳出，不合并
		{
			break;
		}

		if ((prevspan->_npage + span->_npage) > (NPAGES - 1)) //如果合并的页数超过了最大的页就不合并
		{
			break;
		}

		//此时可以合并
		_pagelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;

		previt = _id_span_map.find(span->_pageid - 1);

	}

	//向后合并
	auto nextit = _id_span_map.find(span->_pageid + span->_npage);//找span后面span的id是否存在
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;//取出后面的pagid映射的span

		if (nextspan->_usecount != 0)  //如果后面的pagid映射的span没有全部归还，跳出，不合并
		{
			break;
		}
		if ((nextspan->_npage + span->_npage) > (NPAGES - 1))//超出最大的页不合并
		{
			break;
		}

		//此时可以合并
		_pagelist[nextspan->_npage].Erase(nextspan);
		span->_npage += nextspan->_npage;
		delete nextspan;

		nextit = _id_span_map.find(span->_pageid + span->_npage);
	}

	//将合并成的新span映射到map中
	for (size_t i = 0; i < span->_npage; ++i)
	{
		_id_span_map[span->_pageid + i] = span;
	}

	_pagelist[span->_npage].PushFront(span);//将合并成新的span插入到pagelist中

}