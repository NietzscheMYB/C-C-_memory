#include"PageCache.h"

//ʵ������������
PageCache PageCache::_inst;


/*
NewSpan��ȡһ�ζ�Ӧ��Span��Span����������ҳ
�ú����ڲ���ҳ�ڴ���з֣������ϲ�CentralCache��
*/
Span* PageCache::NewSpan(size_t npage)
{
	//����Եݹ麯�������ķ�ʽ
	std::unique_lock<std::mutex> _lock(_mtx);
	return _NewSpan(npage);
}

Span* PageCache::_NewSpan(size_t npage)
{
	//���ȶ�Ӧ��PageList�Ͽ���û�п��е�Span
	if (!_pagelist[npage].Empty())
	{
		//Ŀ��pagelist��Ϊ��
		return _pagelist[npage].PopFront();
	}

	//�����Ｔ˵��Ŀ��pagelistΪ�գ���Ҫ����Ѱ�ң����зָ����һ��λ�ÿ�ʼ
	for (size_t i = npage + 1; i < NPAGES; ++i)
	{
		
		SpanList*pagelist = &_pagelist[i];
		if (!pagelist->Empty())
		{
			//�ҵ���pagelist��Ϊ��
			Span* span = pagelist->PopFront();
			Span* split = new Span;
			split->_pageid = span->_pageid + span->_npage - npage;
			split->_npage = npage;
			span->_npage -= npage;

			//��ʣ�����ڴ���ص�pageCache����Ӧλ����
			_pagelist[span->_npage].PushFront(span);

			//ֻ������ʹ�õ�ҳ����Ҫ����ӳ��
			for (size_t i = 0; i < split->_npage; ++i)
			{
				//����ҳ��ӳ���ϵ��xxxҳ--xxxҳ��Ϊsplit����
				_id_span_map[split->_pageid + i] = split;
			}

			return split;
		}
	}

	//�ߵ�����˵������û�п��������ָ��Pagelist,��Ҫ���������ڴ�
	void* ptr = VirtualAlloc(NULL, (npage) << PAGE_SHIFT, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}

	//����������ڴ���ص�������
	Span* maxspan = new Span;
	maxspan->_objlist = ptr;
	maxspan->_pageid = (PageID)ptr >> 12;
	maxspan->_npage = NPAGES - 1;
	_pagelist[NPAGES - 1].PushFront(maxspan);

	//�ݹ�����Լ�
	return _NewSpan(npage);
}


//��ȡ��ҳ�ŵ�span��ӳ��
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID pageid = (PageID)obj >> 12;//����ָ�����ڵ�ҳ
	auto it = _id_span_map.find(pageid);//���Ҹ�ҳ��Ӧ�Ĺ���ҳ
	if (it == _id_span_map.end())
	{
		assert(false);
	}
	return it->second;
}

//�ͷſ���span�ص�Pagecache���ϲ����ڵ�span
void PageCache::ReleaseSpanToPageCache(Span* span)
{
	assert(span != nullptr);
	std::unique_lock<std::mutex> lock(_mtx);

	//��ǰ�ϲ�
	auto previt = _id_span_map.find(span->_pageid - 1);//��spanǰһҳ��id�Ƿ���map��
	while (previt!=_id_span_map.end())
	{
		Span* prevspan = previt->second;//ȡ��ǰһҳpageidӳ���span

		if (prevspan->_usecount != 0)//���ǰһҳӳ���spanû��ȫ���黹�����������ϲ�
		{
			break;
		}

		if ((prevspan->_npage + span->_npage) > (NPAGES - 1)) //����ϲ���ҳ������������ҳ�Ͳ��ϲ�
		{
			break;
		}

		//��ʱ���Ժϲ�
		_pagelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;

		previt = _id_span_map.find(span->_pageid - 1);

	}

	//���ϲ�
	auto nextit = _id_span_map.find(span->_pageid + span->_npage);//��span����span��id�Ƿ����
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;//ȡ�������pagidӳ���span

		if (nextspan->_usecount != 0)  //��������pagidӳ���spanû��ȫ���黹�����������ϲ�
		{
			break;
		}
		if ((nextspan->_npage + span->_npage) > (NPAGES - 1))//��������ҳ���ϲ�
		{
			break;
		}

		//��ʱ���Ժϲ�
		_pagelist[nextspan->_npage].Erase(nextspan);
		span->_npage += nextspan->_npage;
		delete nextspan;

		nextit = _id_span_map.find(span->_pageid + span->_npage);
	}

	//���ϲ��ɵ���spanӳ�䵽map��
	for (size_t i = 0; i < span->_npage; ++i)
	{
		_id_span_map[span->_pageid + i] = span;
	}

	_pagelist[span->_npage].PushFront(span);//���ϲ����µ�span���뵽pagelist��

}