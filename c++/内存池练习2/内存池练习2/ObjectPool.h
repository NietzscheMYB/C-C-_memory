#pragma once
#include<iostream>
using namespace std;

//�����Ķ����
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//�ڴ�����char* ���������
		//c++11��ȷ��ֵ�ͳ�ʼ��
		char* _start = nullptr;
		size_t _bytesize = 0;//�����ֽ�
		size_t _byteleft = 0;//ʣ������ֽ�
		Block* _next = nullptr;
		Block(size_t bytersize)
		{
			_start = (char*)malloc(bytersize);
			_bytesize = bytersize;
			_byteleft = bytersize;
			_next = nullptr;
		}
	};
public:
	ObjectPool(size_t initnum = 8)//��һ��������ٸ�����
	{
		///����һ���飡����
		_head = _tail = new Block(initnum*sizeof(T));
	}


	T*& OBJ_NEXT(T* obj)
	{
		//�����*(T*) obj;
		//�����ú��Ǹ����͵Ĵ�С��T**�����ú��Ǹ����͵�ָ��Ĵ�С�����ϵͳ�޹�
		return *(T**)obj;//�����͵�ָ��ǰ���ٸ��ֽ�
	}

	T* New()//���ṩһ������һ�ݿռ�
	{
		T* obj = nullptr;
		//�����������Ϊ��
		if (_freelist != nullptr)
		{
			//������������ȥȡ�Ϳ���
			obj = _freelist;
			//�仯ͷָ��
			_freelist = OBJ_NEXT(_freelist);
		}
		else{
			//��������Ϊ��
			//�жϵ�ǰ���ڴ���Ƿ���ʣ��
			if (_tail->_byteleft == 0)
			{
				//û��ʣ�࣬���������ڴ��
				Block* newblock = new Block(_tail->_bytesize * 2);
				_tail->_next = newblock;
				_tail = newblock;
			}
			obj = (T*)(_tail->_start + (_tail->_bytesize - _tail->_byteleft));
			_tail->_byteleft -= sizeof(T);
		}
		return obj;
	}
	void Delete(T* ptr)
	{
		//ͷ�壡����
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			OBJ_NEXT(ptr) = nullptr;
		}
		else{
			//ͷ��!!!!
			OBJ_NEXT(ptr) = _freelist;
			_freelist = ptr;
		}
	}
private:
	//�������� ����Ҫ�ǹ���飡
	T* _freelist = nullptr;
	//�����
	Block* _head = nullptr;
	Block* _tail = nullptr;
};

void test()
{
	ObjectPool<int> pool;
	int *p1 = pool.New();
	int *p2 = pool.New();
	int *p3 = pool.New();
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	pool.Delete(p1);
	pool.Delete(p2);
	pool.Delete(p3);
	cout << pool.New() << endl;
	cout << pool.New() << endl;
	cout << pool.New() << endl;
}