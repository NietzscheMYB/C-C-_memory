#include <iostream>
using namespace std;

//this指针不能为空
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a <<  endl;
//	}
//	void Show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//	return 0;
//}

//class Date{
//public:
//	Date(int year,int month,int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class B{
//public:
//	B(Date a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	Date _aobj;//没有默认构造函数，默认构造函数包括无参构造函数和全缺省构造函数
//	int& _ref;//引用
//	const int _n;//const
//};

class xx{
	int xxx;   //class 默认访问权限为private   struct 默认访问权限为public
public:
	int y; 
	static int z;

	xx()
	{
		_count++;
	}
	~xx()
	{
		_count--;
		cout << _count << endl;
	}
	xx(const xx&a)
	{
		_count++;
	}
	static int add(int a, int b)
	{
		return a + b;
	}

private:
	static int _count;
};
int xx::_count = 0;
int xx::z = 0;               //类外定义 实际是分配内存！
//int xx::add(int a, int b)
//{
//	return a + b;
//}
int main()
{
	xx a, b;
	xx c(a);
	a.z = 1;
	int ret = a.add(1, 2);
	return 0;

}
