#include"PageCaceh.h"

PageCache PageCache::_inst;

Span* PageCache::NewSpan(size_t npage)
{
	if (!_pagelist[npage].Empty())
	{
		return _pagelist[npage].PopFront();
	}
	Span* span = nullptr;
	for (size_t i = npage+1; i < NPAGES; ++i)
	{
		//��npage��ҳ��ʼ��
		SpanList* pagelist = &_pagelist[i];
		if (!pagelist->Empty())
		{
			Span* span = pagelist->PopFront();

			Span* split = new Span;
			split->_pageid = span->_pageid + span->_npage - npage;
			split->_npage = npage;
			span->_npage -= npage;
			_pagelist[span->_npage].PushFront(span);

			for (size_t i = 0; i < split->_npage; ++i)
			{
				_id_span_map[split->_pageid + i] = split;
			}

			return split;
		}
	}

	//��Ҫ��ϵͳ�����ڴ�
	void* ptr = VirtualAlloc(NULL,(NPAGES-1)<<PAGE_SHIFT, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
	if (ptr==nullptr)
	{
		throw std::bad_alloc();
	}
	Span* largespan = new Span;
	largespan->_pageid =(PageID)ptr >> PAGE_SHIFT;
	largespan->_npage = NPAGES - 1;
	_pagelist[NPAGES - 1].PushFront(largespan);

	for (size_t i = 0; i < largespan->_npage; ++i)
	{
		_id_span_map[largespan->_pageid + i] = largespan;
	}

	//_id_span_map[largespan->_pageid] = largespan;

	return NewSpan(npage);						//�ݹ�����Լ�������
}


// ��ȡ�Ӷ���span��ӳ��
Span* PageCache::MapObjectToSpan(void* obj)

// �ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
void PageCache::ReleaseSpanToPageCahce(Span* span)
{

	auto previt = _id_span_map.find(span->_pageid-1);
	while (previt != _id_span_map.end())
	{
		Span* prevspan = previt->second;
		//���ǿ��У���ֱ������
		if (prevspan->_usecount != 0)
		{
			break; 
		}

		//����ϲ�������NPAGESҳ��span���򲻺ϲ�������û�취����
		if (prevspan->_npage + span->_npage >= NPAGES)
		{
			break;
		}

		_pagelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;

		previt = _id_span_map.find(span->_pageid - 1);
	}
	
	auto nextit = _id_span_map.find(span->_pageid +span->_npage);
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;
		if (nextspan->_usecount!=0)
		{
			break;
		}
		if (span->_npage + span->_npage >= NPAGES)
		{
			break;
		}

		
		_pagelist[nextspan->_npage].Erase(nextspan);
		span->_npage += nextspan->_npage;
		delete nextspan;
	
		nextit = _id_span_map.find(span->_pageid + span->_npage);
	}

	for (size_t i = 0; i < span->_npage; ++i)
	{
		_id_span_map[span->_pageid + i] = span;
	}

	_pagelist[span->_npage].PushFront(span);


}