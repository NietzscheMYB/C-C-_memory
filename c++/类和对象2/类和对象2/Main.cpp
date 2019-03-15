#include <iostream>
using namespace std;

//赋值运算符主要有四点
//参数类型
//返回值
//检查是否自己给自己赋值
//返回*this
//一个类如果没有显式定义赋值运算符重载，编译器也会
//生成一个，完成对象按字节的值拷贝
class Date
{
public:
	Date(int year , int month, int day )
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date &d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2018, 10, 1);
	d1 = d2;
	return 0;
}