//对象池 ，定长池
#pragma once
#include <iostream>
using namespace std;

//定长的对象池
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//内存块管理，char* 处理方便
		//c++11给确定值就初始化了
		char* _start = nullptr;
		size_t _bytesize = 0;//多少个字节
		size_t _byteleft = 0;//剩余字节数
		Block* _next = nullptr;
		Block(size_t bytesize)
		{
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}
		~Block()
		{
			free(_start);
			_byteleft=_bytesize = 0;
			_next = nullptr;
		}
	};
public:
	ObjectPool(size_t initnum=8)//第一次申请多少个对象
	{
		_head = _tail = new Block(initnum*sizeof(T));
	}

	~ObjectPool()
	{
		Destory();
	}
	Destroy()
	{
		Block* cur = _head;
		while (cur)
		{
			Block* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head = _tail = nullptr;
		_freelist = nullptr;
	}


	T*& OBJ_NEXT(T* obj)
	{
		//如果是*(T*) obj;
		//解引用后是该类型的大小，T**解引用后是该类型指针的大小与操作系统无关
		return *(T**)obj;//该类型的指针前多少个字节
	}
	T* New()//先提供一个申请一份空间
	{
		T* obj = nullptr;
		//如果自由链表不为空
		if (_freelist!=nullptr)
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
		//new(obj)T();//定位表达式
		return obj;
	}
	void Delete(T* ptr)
	{
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			//(*(T**)ptr)=nullptr;
			OBJ_NEXT(ptr) = nullptr;        //将ptr里面的前四个字节的内容置为空！！！
		}
		else{
			OBJ_NEXT(ptr) = _freelist;//将ptr里面前四个字节的内容置为_freelist!!!
			_freelist = ptr;
		}
	}
protected:
	//自由链表，最重要是管理块！！！
	T* _freelist = nullptr;
	//块管理
	Block* _head = nullptr;
	Block* _tail = nullptr;
};

void test()
{
	ObjectPool<int> pool;  //因为是int类型，所以每次分割的内存碎片为4个字节，所以每次设置 OBJ_NEXT 都将所有的大小(4个字节) 置为下一个内存碎片的地址
	int* p1 = pool.New();
	int* p2 = pool.New();
	
	cout << p1 << endl;
	cout << p2 << endl;
	pool.Delete(p1);
	pool.Delete(p2);
	cout << pool.New() << endl;
	cout << pool.New() << endl;
}