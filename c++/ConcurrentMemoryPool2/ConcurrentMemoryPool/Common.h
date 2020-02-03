#pragma once
#include<iostream>
#include<assert.h>
#include<thread>

using namespace std;


//�����������������ĳ���
const size_t NLISTS=240;   //�ĸ����䳤�����
const size_t MAXBYTES = 64 * 1024 * 1024;//64k
static inline void*& NEXT_OBJ(void* obj)
{
	return *((void**)obj);
}


//��ҳΪ��λ
typedef size_t PageID;
//Span��ȣ���С�������кϲ�                           32λϵͳ 4G�����ڴ棬��һҳԼ4k
struct Span   
{
	PageID _id;			//ҳ��
	size_t _npage;		//ҳ������

	void* _list;		//��������
	size_t _usecount=0;	//ʹ�ü���

};
struct SpanLlist
{

};


class FreeList
{
public:
	
	bool Empty()
	{
		return _list == nullptr;
	}

	void PushRange(void*start, void* end, size_t num)//��ʣ��Ĺҵ����������ϣ�����
	{
		NEXT_OBJ(end) = _list;
		_list = start;
		_size += num;
	}


	void* Pop()
	{
		void* obj = _list;
		_list = NEXT_OBJ(obj);
		--_size;
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
	void* _list=nullptr;
	size_t _size=0;
	size_t _maxsize=0;
};




//��������ӳ��
class ClasssSize
{
	// ������12%���ҵ�����Ƭ�˷�
	// [1,128]				8byte���� freelist[0,16)
	// [129,1024]			16byte���� freelist[16,72)
	// [1025,8*1024]		128byte���� freelist[72,128)
	// [8*1024+1,64*1024]	512byte���� freelist[128,240)
	
#if 0
	(1024-129)/16=56, 56+16=72
	7*1024/128=56,    56+72=128
#endif

public:
	static inline size_t _Roundup(size_t size,size_t align)   //align ������
	{
		//��8���� (size+7)&~7        ��16���� (size+15)&~15

		return (size + align - 1)&(~(align - 1));
	}
	//����ȡ��
	static inline size_t Roundup(size_t size)
	{
		assert(size < MAXBYTES);

		if (size <= 128){
			return _Roundup(size, 8);
		}
		else if (size <= 1024){
			return _Roundup(size, 16);
		}
		else if (size <= 8192){
			return _Roundup(size, 128);
		}
		else if (size <= 65536){
			return _Roundup(size, 512);
		}
		return -1;
	}

	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		//λ����  8����1������λ������
		return ((bytes + (1 << align_shift) - 1) >> align_shift) - 1;//����  (size+7)/8-1
	}
	static inline size_t Index(size_t bytes)
	{
		assert(bytes < MAXBYTES);

		// ÿ�������ж��ٸ���
		static int group_array[4] = { 16, 56, 56, 112 };

		//������Ǹ����䣡���������ֳ���4������
		if (bytes <= 128){
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024){
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8192){
			return _Index(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 65536){
			return _Index(bytes - 8192, 9) + group_array[2] + group_array[1] +
				group_array[0];
		}
		return -1;
	}



};