#include <iostream>
using namespace std;
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//		, x(b)
//	{
//	}
//int x;
//	int _b;
//	
//};
//class A{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	//非静态成员变量，可以在成员声明时，之间初始化
//	int a = 10; 
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	B x = 20;   //调构造函数，20相当一个参数传到构造函数中
//	return 0;
//}


class Date{
public:
	Date(int year = 1999, int month = 2, int day = 19)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	~Date()
	{}
	bool operator==(const Date& d)
	{
		return this->_year == d._year&&this->_month==d._month&&this->_day==d._day;
	}
	Date operator+(Date& d)
	{
		Date x;
		x._day = this->_day + d._day;
		x._month = this->_month + d._month;
		x._year = this->_year + d._year;
		return x;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1999, 3, 421);
	Date d2(1231, 1, 1);
	Date d3 = d2 + d1;
	return 0;
}

