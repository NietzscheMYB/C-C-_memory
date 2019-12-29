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

			return split;
		}
	}

	//��Ҫ��ϵͳ�����ڴ�



	return nullptr;
}