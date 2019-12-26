#pragma once

#include"Common.h"

// ���Ϊ����ģʽ
class CentralCache
{
public:
	static CentralCache* GetInstance(){
		return &_inst;
	}

	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t n, size_t byte_size);
	// ��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t byte_size);

private:
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;

	static CentralCache _inst;//���ⶨ�壬������.h���涨��
};