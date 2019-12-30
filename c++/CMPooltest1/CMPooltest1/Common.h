#pragma once
#include<iostream>
#include<assert.h>
#include<thread>
#include<mutex>
using namespace std;

const size_t NLISTS = 240;//管理对象自由链表的长度，  四个区间长度相加
const size_t MAXBYTES = 64 * 1024 * 1024;//64K
const size_t PAGE_SHIFT = 12;
const size_t NPAGES = 129;

static inline void*& NEXT_OBJ(void* obj)
{
	return *((void**)obj);
}


class FreeList
{
public:
	bool Empty()
	{
		return _list == nullptr;
	}
	void PushRange(void* start, void* end, size_t num)//将剩余的挂到自由链表上
	{
		NEXT_OBJ(end) = _list;
		_list = start;
		_size += num;
	}
	void* Pop()
	{
		void* obj = _list;
		_list = NEXT_OBJ(obj);
		_size--;
		return obj;
	}
	void Push(void* obj)
	{
		NEXT_OBJ(obj) = _list;
		_list = obj;
		++_size;
	}
	size_t Size()
	{
		return _size;
	}
	size_t MaxSize()
	{
		return _maxsize;
	}
private:
	void* _list = nullptr;
	size_t _size = 0;
	size_t _maxsize = 0;
};


//管理对齐映射
class ClasssSize
{
	//控制在12%左右的内碎片浪费
	//[1,128]				8byte对齐 freelist[0,16)
	//[129,1024]			16byte对齐 freelist[16,72)
	//[1025,8*1024]			128byte对齐 freelist[72,128)
	//[8*1024+1,64*1024]	512byte对齐 freelist[128,240)

public:
	static inline size_t _Roundup(size_t size,size_t align) //align对齐数
	{
		//跟8对齐(size+7)&~7      跟16对齐 (size+15)&~15
		return (size + align - 1)&(~(align - 1));
	}
	
	//向上取整
	static inline size_t Roundup(size_t size)
	{
		assert(size < MAXBYTES);
		if (size <= 128)
		{
			return _Roundup(size, 8);
		}
		else if (size <= 1024)
		{
			return _Roundup(size, 16);
		}
		else if (size <= 8 * 1024)
		{
			return _Roundup(size, 128);
		}
		else if (size <= 64 * 1024)
		{
			return _Roundup(size, 512);
		}
		return -1;
	}

	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		//位操作      8就是1左移动3位
		return ((bytes + (1 << align_shift) - 1) >> align_shift) - 1; //类似(size+7)/8-1
	}
	static inline size_t Index(size_t bytes)
	{
		assert(bytes < MAXBYTES);

		//每个区间有多少个链
		static int group_array[6] = { 16, 56, 56, 112 };

		//算出在那个区间！！！，分成了4个区间
		if (bytes <= 128)
		{
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024)
		{
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8192){
			return _Index(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 65536)
		{
			return _Index(bytes - 8192, 9) + group_array[2] + group_array[1] + group_array[0];
		}
		return -1;

	}

	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)
		{
			return 0;
		}
		int num = static_cast<int>(MAXBYTES / size);//功能是把一个表达式转换为某种类型，但没有运行时类型检查来保证转换的安全性。
		if (num < 2)
		{
			num = 2;
		}
		if (num>512)
		{
			num = 512;
		}
		return num;
	}
	//计算一次向系统获取几个页
	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		npage >>= 12;
	}
};