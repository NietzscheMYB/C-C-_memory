//对象池，定长池

#pragma once
#include<iostream>
using namespace std;
//定长的对象池
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//内存块管理，char* 处理方便
		char* _start=nullptr;
		size_t _bytesize=0;//多少个字节
		size_t _byteleft = 0;//剩余字节数
		Block* _next=nullptr;
		Block(size_t bytesize)
		{
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}

	};
public:
	ObjectPool(size_t initnum=8)
	{
		_head = _tail = new Block(initnum*sizeof(T));
	}

	T*& OBJ_NEXT(T* obj)
	{
		return  *(T**)obj;
	}

	T* New()  //先提供一个申请一份空间
	{
		T* obj = nullptr;
		if (_freelist != nullptr)
		{
			obj = _freelist;
			_freelist = OBJ_NEXT(_freelist);
		}
		else{
			 
			if (_tail->_byteleft==0)
			{
				Block* newblock = new Block(_tail->_bytesize*2);
				_tail->_next = newblock;
				_tail = newblock;
			}

			obj = (T*)(_tail->_start+(_tail->_bytesize-_tail->_byteleft));
			_tail->_byteleft -= sizeof(T);
			
		}
		return obj;
	}
	
	void Delete(T* ptr)
	{
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			//(*(T**)ptr) = nullptr;//根据指针来取8个字节还是4个字节
			OBJ_NEXT(ptr) = nullptr;
		}
		else{
			//(*(T**)ptr) = _freelist;
			OBJ_NEXT(ptr) = _freelist;
			_freelist = ptr;
		}
	}

protected:
	//自由链表
	T* _freelist=nullptr;
	//块管理
	Block* _head=nullptr;
	Block* _tail=nullptr;
};

void test()
{
	ObjectPool<int> pool;
	int* p1=pool.New();
	int* p2=pool.New();

	cout << p1 << endl;
	cout << p2 << endl;

	pool.Delete(p1);
	pool.Delete(p2);

	cout << pool.New()<< endl;
	cout << pool.New() << endl;
}
