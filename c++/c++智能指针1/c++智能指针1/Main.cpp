//智能指针 raii思想，利用对象的生命周期来控制资源
//像指针一样  operator*,operator->

#include<iostream>
using namespace std;
namespace bite{
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{

		}
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
		//资源转移
		auto_ptr(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				_ptr = p._ptr;
				p._ptr = nullptr;

			}
		}
		//资源的转移
		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = p._ptr;
				p._ptr = nullptr;
				return *this;
			}

		}
		T& operator*()
		{
			return *ptr;
		}
		T* operator->()
		{
			return &operator*();
		}
	private:
		T* _ptr;
	};
}


int main()
{
	bite::auto_ptr<int> p1(new int);
	bite::auto_ptr<int> p2(p1);
	p1 = p2;

	return 0;
}