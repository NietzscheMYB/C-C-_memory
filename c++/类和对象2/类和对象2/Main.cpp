#include <iostream>
using namespace std;

//��ֵ�������Ҫ���ĵ�
//��������
//����ֵ
//����Ƿ��Լ����Լ���ֵ
//����*this
//һ�������û����ʽ���帳ֵ��������أ�������Ҳ��
//����һ������ɶ����ֽڵ�ֵ����
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