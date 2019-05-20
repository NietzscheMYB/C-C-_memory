#include<iostream>
#include<vector>
#include<memory>
using namespace std;

//template<class T>
//class SmartPtr{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			cout << "delete _ptr" << endl;
//		}
//	}
//private:
//	T* _ptr;
//};
//
//void Test()
//{
//	int* tmp = new int;
//	SmartPtr<int> sp(tmp);
//	//vector<int> v(100000000000000, 10);
//
//	throw("sdjkajsdk");
//
//	cout << "delete tmp" << endl;
//	delete tmp;
//}
//
//int main()
//{
//	try{
//		Test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (const char *str)
//	{
//		cout << "str error" << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknow error" << endl;
//	}
//	return 0;
//}

//template<class T>
//class SmartPtr{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//	//*ptr
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T* operator=(T* ptr)
//	{
//		_ptr = ptr;
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//struct Date
//{
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//public:
//	int _year = 1900;
//	int _month = 1;
//	int _day = 11;
//};
//
//void Test()
//{
//	SmartPtr<Date> sp(new Date);
//	Date d1;
//	sp.operator=(&d1);
//	sp->_day = 1000;
//	sp->_month = 32;
//	sp.operator->()->_month = 21;
//}
//int main()
//{
//	Test();
//	return 0;
//}

class Date
{
public:
	Date()
	{}
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	~Date()
	{
		cout << "~Date()" << endl;
	}

	int _day=2;
	int _month=32;
	int _year=23;
};
//int main()
//{
//	auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);
//
//	//当对象拷贝或者赋值后，后面的对象就选空l
//	//autoptr管理权转移 解决二次释放问题 （浅拷贝）
//	
//	copy->_day = 10;
//	cout << copy->_day << endl;
//	
//	return 0;
//}

template<class T>
class Auto_ptr{
public:
	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{}
	Auto_ptr(Auto_ptr<T>& pp)
		:_ptr(pp._ptr)
	{
		pp._ptr = nullptr;
	}
	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T* operator=(T* ptr)
	{
		_ptr = ptr;
	
		return _ptr;
	}
private:
	T* _ptr;
};
void test()
{
	Date d1;
	d1._day = 11;
	d1._month = 12;
	d1._year = 2019;
	Auto_ptr<Date> ap1(new Date);
	Auto_ptr<Date> ap2(ap1);
	cout << ap2->_day << endl;

}
int main()
{
	test();
	return 0;
}