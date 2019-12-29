#pragma once

#include"Common.h"

// 1.page cache��һ����ҳΪ��λ��span��������
// 2.Ϊ�˱�֤ȫ��ֻ��Ψһ��page cache������౻��Ƴ��˵���ģʽ��
class PageCache
{
public:

	static PageCache* GetInstance()
	{
		return &_inst;
	}
	Span* NewSpan(size_t npage);

private:
	SpanList _pagelist[NPAGES];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	static PageCache _inst;
};