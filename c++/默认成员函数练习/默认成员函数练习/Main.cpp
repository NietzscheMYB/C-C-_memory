#include <iostream>
using namespace std;
class Date {
public:  
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || (month > 12 || month<1) || (day <= 0 || day>getMonthDay(year, month)))
		{
			cout << "非法日期!日期已设为默认值：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
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
	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30,31,30,30,31,30,31 };
		//static 延长局部变量生命周期
		int day = days[month];
		if (month == 2)
		{
			//判断是否为闰年
			if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
			{
				day += 1;
			}
		}
		return day;
	}
		   Date& operator=(const Date& d);  
		   //Data +=2;
		   Date& operator+=(int day)
		   {
			   if (day<0)
			   {
				   return *this -= -day;
			   }
			   //1900-1-1
			   _day += day;
			   //考虑是否进位
			   //1900-1-1 +32 1-33  33-1=2  1900-2-2
			   while (_day > getMonthDay(_year, _month))
			   {
				   _day -= getMonthDay(_year, _month);
				   ++_month;
				   //判断当前月份是否正确
				   if (_month == 13)
				   {
					   _month = 1;
					   ++_year;
				   }
			   }
			   return *this;
		   }
		   Date& operator-=(int day)
		   {
			   if (day < 0)
			   {
				  return  *this += -day;
				   
			   }
			   _day -= day;
			   while (_day <=0)
			   {
				   --_month;
					if (_month == 0)
					   {
						   _month = 12;
						   --_year;
					   }
				   _day+= getMonthDay(_year, _month);
			   }
			   return *this;
		   }
		   Date operator+(int days)
		   {
			   Date ret(*this);
			   ret += days;
			   return ret;
		   }
		   Date operator-(int days)
		   {
			   Date ret(*this);
			   ret -= days;
			   return ret;
		   }
		  
		   Date& operator++()
		   {
			   //++Date  先自加,再返回
			    *this += 1;
				return *this;
		   }
		   Date operator++(int)
		   {
			   Date ret(*this);
			   //Data++  先返回之前的值,再自加
			   *this += 1;
			   return *this;

		   }
		   Date& operator--()
		   {
			   //--Date
			   *this -= 1;
			   return *this;
		   }
		   Date operator--(int)
		   {
			   //Date--
			   Date ret(*this);
			   *this -= 1;
			   return ret;
		   }
		   //*this >d
		   bool operator>(const Date& d)const
		   {
			   if (this->_year > d._year)
			   {
				   return true;
			   }
			   else if (_year == d._year)
			   {
				   if (_month > d._month)
				   {
					   return true;
				   }
				   else if (_month==d._month)
				   {
					   if (_day > d._day)
					   {
						   return true;
					   }
				   }
			   }
			   return false;
		   }
		   bool operator>=(const Date& d)const
		   {
			   return (*this > d) || (*this == d);
		   }
		   bool operator<(const Date& d)const
		   {
			   return !(*this >= d);
		   }
		   bool operator<=(const Date& d)const
		   {
			   return (*this < d) || (*this == d);
		   }
		   bool operator==(const Date& d)const
		   {
			 return   _year == d._year&&_month == d._month
				   &&_day == d._day;
		   }
		   bool operator!=(const Date& d)const
		   {
			   return !(*this == d);

		   }
		   //*this -d
		   int operator-(const Date& d)
		   {
			   Date ret(*this);
			   int flag = 1;
			   if (ret < d)
			   {
				   flag = -1;
			   }
			   int day=0;
			   if (ret < d)
			   {
				   while (ret < d)
				   {
							++ret;
						   ++day;
				   }
			   }
			   else
			   {
				   while (ret>d)
				   {
					   --ret;
					   ++day;
				   }
			   }
			   return day*flag;//正向累加还是负向累加
		   }
		   void display()
		   {
			   cout << _year << "-" << _month << "-" << _day << endl;
		   }
private:    
			   int _year;   
			   int _month;   
			   int _day;
};

void testDate()
{
	Date d1(2019, 1, 30);
	Date d2(2019, 2, 28);
	//cout << (d1++) << endl;
	d1++;
	cout << "d1(2019,1,30)++" << endl;
	d1.display();
	d2--;
	cout << "d2(2019,2,28)--" << endl;
	d2.display();
	Date d3 = d1 + 62;
	cout << "d3=d1+62" << endl;
	d3.display();
	Date d4 = d2 - 39;
	cout << "d4=d1-39" << endl;
	d4.display();
}
void testDate2()
{
	Date d1(2019, 3, 8);
	Date d2(2019, 1, 1);
	int d3 = d1 - d2;
}
int main()
{
	testDate();
	return 0;
}