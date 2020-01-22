#include"PageCache.h"

PageCache PageCache::_inst;

Span* PageCache::NewSpan(size_t npage)
{
	std::unique_lock<std::mutex> lock(_mtx);//�����ڵݹ����ʹ������
	if (npage >= NPAGES)
	{
		//��Ҫ��ϵͳ�����ڴ�
		void* ptr = SystemAlloc(npage);
		Span* span = new Span;
		span->_pageid = (PageID)ptr >> PAGE_SHIFT;
		span->_npage = npage;
		span->_objsize = npage << PAGE_SHIFT;

		_id_span_map[span->_pageid] = span;
		return span;
	}

	Span* span = _NewSpan(npage);
	span->_objsize = npage << PAGE_SHIFT;
	return span;
}

Span* PageCache::_NewSpan(size_t npage)
{
	//�����Ϊ�� ֻ��Ҫͷɾ�Ϳ�����
	if (!_pagelist[npage].Empty())
	{
		return _pagelist[npage].PopFront();
	}
	Span* span = nullptr;
	for (size_t i = npage + 1; i < NPAGES; ++i)
	{
		//��npage��ҳ��ʼ��
		SpanList* pagelist = &_pagelist[i];
		if (!pagelist->Empty())
		{
			Span* span = pagelist->PopFront();

			//�и�
			Span* split = new Span;
			split->_pageid = span->_pageid + span->_npage - npage;
			split->_npage = npage;
			span->_npage -= npage;
			_pagelist[split->_npage].PushFront(span);//��ʣ�µ�span�����뵽��Ӧ�Ĳ���

			for (size_t i = 0; i < split->_npage; ++i)
			{
				_id_span_map[split->_pageid + i] = split;
			}

			return split;
		}
	}
	//��Ҫ��ϵͳ�����ڴ�
	void* ptr = SystemAlloc(NPAGES - 1);

	Span* largespan = new Span;
	largespan->_pageid = (PageID)ptr >> PAGE_SHIFT;
	largespan->_npage = NPAGES - 1;
	_pagelist[NPAGES - 1].PushFront(largespan);

	for (size_t i = 0; i < largespan->_npage; ++i)
	{
		_id_span_map[largespan->_pageid + i] = largespan;
	}
	return _NewSpan(npage);
}

//��ȡ��ҳ�ŵ�span��ӳ��
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID pageid = (PageID)obj >> PAGE_SHIFT;//����ָ�����ڵ�ҳ��
	auto it = _id_span_map.find(pageid);
	if (it == _id_span_map.end())
	{
		assert(false);
	}
	return it->second;
}

//����spanֻ������Pagecache
//�ͷſ���span�ص�Pagecahce,���ϲ����ڵ�span
void PageCache::ReleaseSpanToPageCache(Span* span)
{
	std::unique_lock<std::mutex> lock(_mtx);
	if (span->_npage >= NPAGES)
	{
		void* ptr = (void*)(span->_pageid << PAGE_SHIFT);
		SystemFree(ptr);
		delete span;
		return;
	}
	//�ϲ�ǰһ��ҳ
	auto previt = _id_span_map.find(span->_pageid - 1);
	while (previt != _id_span_map.end())
	{
		Span* prevspan = previt->second;
		//���ǿ��У���ֱ������
		if (prevspan->_usecount != 0)
		{
			//ǰһ��span����0
			break;
		}
		//����ϲ�����NPAGESҳ��span���򲻺ϲ�������û�а취����
		if (prevspan->_npage + span->_npage >= NPAGES)
		{
			break;
		}

		//�Ȱ�prev�������в�������
		_pagelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;
		previt = _id_span_map.find(span->_pageid - 1);
	}
	//�ϲ���һ��ҳ�������һ��ҳӦ����+npage������
	auto nextit = _id_span_map.find(span->_pageid + span->_npage);
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;
		if (nextspan->_usecount != 0)
		{
			break;
		}
		if (nextspan->_npage + span->_npage >= NPAGES)
		{
			break;
		}
		//�Ƚ�nextspan�ó������в���
		_pagelist[nextspan->_npage].Erase(nextspan);
		span->_npage += nextspan->_npage;
		delete nextspan;
		nextit = _id_span_map.find(span->_pageid + span->_npage);

	}
	for (size_t i = 0; i < span->_npage; ++i)
	{
		_id_span_map[span->_pageid + i] = span;
	}
	//�ϲ���󣬽��в���
	_pagelist[span->_npage].PushFront(span);

}
