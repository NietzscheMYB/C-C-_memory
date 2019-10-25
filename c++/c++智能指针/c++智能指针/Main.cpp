#include<iostream>
using namespace std;
#if 0
namespace a{
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~auto_ptr(){
			if (_ptr)
			{
				delete _ptr;
			}
		}
		auto_ptr(auto_ptr<T>& p)
		{
			_ptr = p._ptr;
			p._ptr = nullptr;
		}
		//实现RAII 思想，像指针一样，解决深浅拷贝问题
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};
}

struct Date{
	int _year;
	int _month;
	int _day;
};
int main()
{
	a::auto_ptr<int> p1(new int(1));
	*p1=2;
	a::auto_ptr<int> p2(p1);
	//auto_ptr 的拷贝构造，是将资源进行转移，当下次继续对p1进行* 引用时，就会出错！
	*p1 = 2;
	a::auto_ptr<Date> p3(new Date);
	return 0;
}
#endif

#if 0
namespace b{
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
		//像指针一样
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		//c++11中防止拷贝的方式
		//函数后面加上delete
		//意思是禁止该函数生成，将默认成员函数删除
		unique_ptr(const unique_ptr<T> &) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&)=delete
	private:
		//防止拷贝与防止运算符重载
		//c++98在私有中只声明不定义
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator = (unique_ptr<T> p);

	private:
		T* _ptr;
	};
}
struct Data{
	int _date;
	int _year;
	int _month;
};

int main()
{
	b::unique_ptr<int> p1(new int(1));
	 //b::unique_ptr<int> p2(p1);
	 //b::unique_ptr<int> p3(new int(3));
	 //p1 = p3;
	b::unique_ptr<Data> p2(new Data);
	p2->_date = 1;
	p2->_month = 2;
	p2->_year = 3;

	return 0;
}
#endif

//任意类型的资源能够进行管理
//假设：资源可以new，malloc 文件指针，套接字
//定制删除器


//针对new的资源
template<class T>
struct DFDel
{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr == nullptr;
		}
	}
};



//对于文件资源
struct FClose{
	void operator()(FILE* pf)
	{
		if (pf)
		{
			fclose(pf);
		}
	}
};

//针对free的资源
template<class T>
struct Free
{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};
namespace b{

	template<class T, class DF = DFDel<T>>
	class unique_ptr{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			DF(_ptr);
		}
		//像指针一样
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		//c++11中防止拷贝的方式
		//函数后面加上delete
		//意思是禁止该函数生成，将默认成员函数删除
		unique_ptr(const unique_ptr<T> &) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&) = delete
	private:
		//防止拷贝与防止运算符重载
		//c++98在私有中只声明不定义
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator = (unique_ptr<T> p);

	private:
		T* _ptr;
	};
}
struct Data{
	int _date;
	int _year;
	int _month;
};

int main()
{
	b::unique_ptr<int> p1(new int(1));
	//b::unique_ptr<int> p2(p1);
	//b::unique_ptr<int> p3(new int(3));
	//p1 = p3;
	b::unique_ptr<Data> p2(new Data);
	p2->_date = 1;
	p2->_month = 2;
	p2->_year = 3;
	b::unique_ptr<Data,Free<Data>> p4((Data*)malloc(sizeof(Data)));
	b::unique_ptr<char, Free<char>> p5((char*)malloc(sizeof(char)));

	return 0;
}



#if 0
#include<mutex>
namespace c{
	template<class T>
	class share_ptr{
	public:
		share_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
			, _mt(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(0);
				_mt = new mutex;
				++*_pCount;
			}
		}
		~share_ptr()
		{
			_mt->lock();
			if (_ptr&&--*_pCount==0)
			{
				delete _ptr;
			}
			_mt->unlock();
		}
		share_ptr(const share_ptr<T>& p)
			:_ptr(p._ptr)
			, _pCount(p._pCount)
		{
			*_pCount++;
		}
		share_ptr<T>& operator=(share_ptr<T>& p)
		{
			//赋值分情况
			if (this != &p)
			{
				_mt->lock();
				//被赋值的对象
				if (_ptr)
				{
					if (_ptr&&--*_pCount == 0)
					{
						delete _ptr;
						delete _pCount;
					}
				}
				_ptr = p._ptr;
				_pCount = p._pCount;
				++*_pCount;
				_mt->unlock();
			}
			return *this;
		}
		//像指针一样
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}


	private:
		T* _ptr;
		int* _pCount;
		mutex* _mt;
	};
}
struct Date{
	int _day;
	int _year;
	int _month;
};

int main()
{
	c::share_ptr<int> p1(new int(1));
	c::share_ptr<int> p2(new int(2));
	c::share_ptr<int> p3;
	p3 = p1;
	p2 = p1;

	return 0;
}
#endif



