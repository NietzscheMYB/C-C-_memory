#pragma once
#include"Common.h"
//1.page cache ��һ����ҳΪ��λ��span��������
//2.Ϊ�˱�֤ȫ��ֻ��Ψһ��pagecache������౻��Ƴ��˵���ģʽ

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);

	//��ȡ����span��ӳ��
	Span* MapObjectToSpan(void* obj);

	//�ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
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