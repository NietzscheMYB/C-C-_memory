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
		//内存块管理，char* 处理更方便
		//c++11给确定值就初始化
		char* _start = nullptr;
		size_t _bytesize = 0;//多少字节
		size_t _byteleft = 0;//剩余多少字节
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
	ObjectPool(size_t initnum = 8)//第一次申请多少个对象
	{
		///申请一个块！！！
		_head = _tail = new Block(initnum*sizeof(T));
	}


	T*& OBJ_NEXT(T* obj)
	{
		//如果是*(T*) obj;
		//解引用后是该类型的大小，T**解引用后是该类型的指针的大小与操作系统无关
		return *(T**)obj;//该类型的指针前多少个字节
	}

	T* New()//先提供一个申请一份空间
	{
		T* obj = nullptr;
		//如果自由链表不为空
		if (_freelist != nullptr)
		{
			//从自由链表中去取就可以
			obj = _freelist;
			//变化头指针
			_freelist = OBJ_NEXT(_freelist);
		}
		else{
			//自由链表为空
			//判断当前的内存块是否还有剩余
			if (_tail->_byteleft == 0)
			{
				//没有剩余，重新申请内存块
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
		//头插！！！
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			OBJ_NEXT(ptr) = nullptr;
		}
		else{
			//头插!!!!
			OBJ_NEXT(ptr) = _freelist;
			_freelist = ptr;
		}
	}
private:
	//自由链表， 最重要是管理块！
	T* _freelist = nullptr;
	//块管理
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