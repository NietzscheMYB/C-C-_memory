#include <iostream>
using namespace std;
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2018,2,19);
//	d2.SetDate(2018,2,17);
//	d1.Display();
//	d2.Display();
//	return 0;
//
//}

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////无参构造函数和全缺省构造函数都称为默认构造函数
//void test()
//{
//	Date d1;//调用无参构造函数
//	Date d2(2018, 1, 1);//调用带参构造函数
//	//d1.SetDate(2018, 2, 19);
//	//d2.SetDate(2018, 2, 17);
//	d1.Display();
//	d2.Display();
//	Date d3();//这个只是声明一个d3函数，该函数无参返回一个日期类型的对象
//	//return 0;
//}
#include <malloc.h>
#include <assert.h>
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity*sizeof(DataType));
//		assert(_pData);
//		_size = 1;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		free(_pData);
//		_pData = NULL;
//		_size = 0;
//		_capacity = 0;
//	}
//private:
//	int * _pData;
//	int  _size;
//	int _capacity;
//};
//void test2()
//{
//	SeqList l1(2);
//}
//
//int main()
//{
//	test2();
//	return 0;
//}
//
#include <cstring>
//class String
//{
//public:
//	String(const char *str="jack")
//	{
//		_str = (char *)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//	}
//
//private:
//	char *_str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

//拷贝构造函数是构造函数的一个重载形式！！
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date&d) //拷贝构造函数是拷贝函数的重载，参数只有一个且必须穿引用！！传值会引起无穷递归
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////系统生成默认的拷贝构造函数，对象按内存存储
////按字节序完成拷贝，这种拷贝叫做浅拷贝  或者值拷贝
//
//
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//赋值运算符重载
//运算符重载是具有特殊函数名的函数
//函数名字为：关键字operator后面接需要的运算符符号
class Date
{
public:
	Date(int year = 1999, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//bool operator==(Date *this,const &d2)
	//左操作数是this指向的调用函数的对象
	bool operator==(const Date& d2)
	{
		return _year = d2._year&&_month == d2._month
			&&_day == d2._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 9, 2);
	Date d2(d1);
	cout << (d1 == d2) << endl;
	return 0;
}