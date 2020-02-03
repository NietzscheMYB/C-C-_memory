#pragma once

#include"Common.h"

//1.page cache ��һ����ҳΪ��λ��span��������
//2.Ϊ�˱�֤ȫ��ֻ��Ψһ��page cache������౻��Ƴ��˵���ģʽ

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}
	//��ȡһ��span
	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);


	//��ȡ��ҳ�ŵ�span��ӳ��
	Span* MapObjectToSpan(void* obj);

	//�ͷſ���span�ص�Pagecache���ϲ����ڵ�span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pagelist[NPAGES];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache operator=(const PageCache&) = delete;
	static PageCache _inst;

	std::mutex  _mtx;
	//��map��unordered_map���PagID��Span* ��ӳ���ϵ�����ںϲ�
	//std::unordered_map<PageID, Span*> _id_span_map;
	std::map<PageID, Span*> _id_span_map;

};