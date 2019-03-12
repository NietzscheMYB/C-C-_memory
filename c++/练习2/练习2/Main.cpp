#include <iostream>
using namespace std;
////1.构造函数
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
//	d1.SetDate(2018, 5, 1);
//	d1.Display();
//	
//	d2.SetDate(2019,3,8);
//	d2.Display();
//
//	//对于以上d1,d2 用SetDate公用方法给对象设置内容
//	//但是 如果每次创建对象都用SetDate比较麻烦
//	//所以引出构造函数
//	//构造函数是一种特殊的成员函数，名字与类相同，创建类类型
//	//时由编译器自动调用，保证每个数据成员都有一个合适的初始值
//	//初始化对象 而不是开空间创建对象！！！
//	return 0;
//}


class Date
{
public:
	//1.无参构造函数
	Date()
	{

	}
	//2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = _day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1;//调用无参构造函数
	Date d2(2018, 3, 8);//调用带参的构造函数
	 //注意：如果通过无参构造函数创建对象时，
	//对象后面不需要带括号，否则成为了函数的声明
	Date d3();//声明了d3函数，该函数无参，返回
	//一个日期类型的对象
}
//如果类中没有显示定义构造函数
//则c++编译器会自动生成一个无参的默认构造函数
//用户定义则编译器不在定义
//int main()
//{
//	TestDate();
//	return 0;
//}
//-------------------------------------------------------

//2.析构函数
//对象在销毁的时候自动调用析构函数，完成类的一些
//资源清理工作。
//对象生命周期结束的时候，c++编译系统自动调用析构函数
//析构函数的函数名是在类名前加~



//5.赋值运算符重载
class Date
{
public :
	Date(int year = 1982, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d1)
	{
		_year = d1._year;
		_month = d1._month;
		_day = d1._day;
	}
private:
	int _year;
	int _month;
	int _day;
};