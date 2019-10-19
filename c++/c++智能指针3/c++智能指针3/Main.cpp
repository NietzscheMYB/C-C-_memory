#include<iostream>
#include<mutex>
using namespace std;

template<class T>
//new 资源
struct DEDel{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

template<class T>
//malloc 资源
struct Free{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};

//文件类型只有一种类型，所以不需要模板
struct FClose{
	void operator()(FILE*& ptr)
	{
		if (ptr)
		{
			fclose(ptr);
			ptr = nullptr;
		}
	}
};

namespace bite
{
	//任意类型的资源能够进行管理
	//假设：资源可以new malloc 文件指针，套接字


	//RAII + operator*/operator->  + 可以拷贝复制+ 引用计数
	template<class T,class DF=DEDel<T>>
	class share_ptr{
	public:
		share_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}
		~share_ptr()
		{
			if (_ptr && 0 == SubRef())
			{
				DF()(_ptr);
				delete _pCount;
			}
		}
		share_ptr(const share_ptr<int>& p)
			:_ptr(p._ptr)
			, _pCount(p._pCount)
			, _pMutex(p._pMutex)
		{
			
			AddRef();
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		share_ptr<T>& operator=(share_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//要么当前对象有资源，要么当前对象没有资源
				
				Release();
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				AddRef();
			}
			return *this;
		}
	private:
		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				DF()(_ptr);//仿函数机制
				delete _pCount;
				if (_pMutex)
				{
					delete _pMutex;
				}
			}
		}
		void AddRef()
		{
			_pMutex->lock();
			++*_pCount;
			_pMutex->unlock();
		}
		int SubRef()
		{
			_pMutex->lock();
			--*_pCount;
			_pMutex->unlock();
			return *_pCount;
		}
	private:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;
	};
}


int main()
{
	bite::share_ptr<int> p(new int);
	bite::share_ptr<int,Free<int>> p1((int*)malloc(sizeof(int)));
	bite::share_ptr<int> p2;
	bite::share_ptr<int> p3;
	p2 = p;
	p3 = p;
	return 0;
}