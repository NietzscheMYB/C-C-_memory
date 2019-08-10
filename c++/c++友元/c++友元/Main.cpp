
//#include <iostream>
//using namespace std;
//class Date{
//public:
//	Date(int year=1999,int month=2,int day=19)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << this->_year << "-"<<this->_month<<"-"<<this->_day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _day;
//	int _month;
//};
//
//int main()
//{
//	Date d;
//	d << cout;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, const Date& d);
//public:
//	Date(int year=1999,int day=19,int month=2)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	~Date()
//	{}
//
//private:
//	int _year;
//	int _day;
//	int _month;
//};
//
//ostream& operator <<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, const Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	int x = 0;
//
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}



#include<iostream>
using namespace std;
class Date;//前置声明
class Time
{
	friend class Date;//声明日期类为时间类的友元类，则在日期类中就之接访问time类中私有成员变量
public:
	Time()
	{

	}
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1999, int month = 2, int day = 10)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		//直接访问时间类的私有成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _day;
	int _month;
	Time _t;
};

int main()
{
	return 0;
}