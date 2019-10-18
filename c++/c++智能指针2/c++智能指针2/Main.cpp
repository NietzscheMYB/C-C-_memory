#include<iostream>
#include<memory>
using namespace std;

//int main()
//{
//	unique_ptr<int> up1(new int);
//	//出错，禁止拷贝构造
//	//unique_ptr<int> up2(up1);
//	unique_ptr<int> up2;
//	//也不能赋值，禁止复制运算符重载
//	//up2 = up1;
//
//	//将当前对象首地址打印
//	cout << up1.get() << endl;
//	up1.release();//将里面释放
//
//	//将当前对象首地址打印
//	cout << up1.get() << endl;
//	up1.reset(new int);
//	
//	//将当前对象首地址打印
//	cout << up1.get() << endl;
//
//	return 0;
//}

//unique_ptr:实现原理：一份资源被
//一个对象独占
//RAII + operator*()/operator->()  +   禁止调用拷贝构造
namespace bite{
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
	private:
		//c++98; 只声明不定义！！！
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator=(unique_ptr<T>& p);
		//c++11 delete 禁止生成该函数
		unique_ptr(const unique_ptr<T>& p) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&p) = delete;
	private:
		T* _ptr;
	};

	
}
namespace x{
	//share_ptr
	//RAII operator*()/operator->() +支持拷贝构造+支持赋值运算符重载 +  引用计数
	//缺陷：不能管理任意类型的指针，
	//线程不安全 存在++
	//循环引用


	template<class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}
		~shared_ptr()
		{
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr; //
				delete _pCount;
			}
		}
		////////////////////////////////////////////
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		///////////////////////////////////////
		//采用引用计数的方式解决浅拷贝问题
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			++*_pCount;
		}
		//sp2=sp1;
		//sp2是否有资源----->没有----->直接共享
		//sp2是否有资源----->有：
		//1.资源的计数是1   
		//2.计数>1    
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//将this从资源中分离开
				if (_ptr && 0 == --*_pCount)
				{
					delete _ptr;
					delete _pCount;
				}
				//共享资源
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				++*_pCount;
			}
			return *this;
		}
		size_t use_count() const
		{
			return *_pCount;
		}
	private:
		T* _ptr;
		int* _pCount;
	};

}

int main()
{
	x::shared_ptr<int> p1(new int);
	bite::unique_ptr<int> p2(new int);
	return 0;
}













