#include<iostream>
using namespace std;
//class Date{
//public:
//	/*Date()
//	{}*/
//	Date(int day = 19, int month = 2,int year=1999)
//		:_day(day)
//		, _month(month)
//		, _year(year)
//	{}
//private:
//	int _day;
//	int _month;
//	int _year;
//};
//
//int main()
//{
//	Date a;  //全缺省和无参构造函数都是默认构造函数 ，但只能有一个
//	return 0;
//}

//class Date{
//public:
//	Date(int year = 1990, int day = 2, int month = 10)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	~Date()
//	{
//
//	}
//
//private:
//	int _year;
//	int _day;
//	int _month;
//};
//
//int main()
//{
//	Date a(1990, 3, 4);
//	Date b(a);
//	return 0;
//}
class Date
{
public:
	Date(int year = 1990, int month = 2, int day = 10)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	~Date()
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Date& d1) {
		return this->_day == d1._day&&
		this->_month == d1._month&&this->_year == d1._year;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_day = d._day;
			this->_month = d._month;
			this->_year = d._year;
			return *this;
		}
	}
	Date& operator+(const Date& d)
	{
		this->_day += d._day;
		this->_month += d._month;
		this->_year += d._year;
		return *this;
	}
	Date& operator++()
	{

		this->_day++;
		this->_month++;
		this->_year++;
		return *this;
	}
	const Date operator++(int)
	{
		Date tem(*this);
		this->_day++;
		this->_month++;
		this->_year++;
		return tem;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a(100, 2, 2);
	Date b(12, 2, 2);
	a = b;
	Date c;
	c = a + b;
	++a;
	a++;
	return 0;
}

