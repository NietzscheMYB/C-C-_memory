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
////�޲ι��캯����ȫȱʡ���캯������ΪĬ�Ϲ��캯��
//void test()
//{
//	Date d1;//�����޲ι��캯��
//	Date d2(2018, 1, 1);//���ô��ι��캯��
//	//d1.SetDate(2018, 2, 19);
//	//d2.SetDate(2018, 2, 17);
//	d1.Display();
//	d2.Display();
//	Date d3();//���ֻ������һ��d3�������ú����޲η���һ���������͵Ķ���
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

//�������캯���ǹ��캯����һ��������ʽ����
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date&d) //�������캯���ǿ������������أ�����ֻ��һ���ұ��봩���ã�����ֵ����������ݹ�
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
////ϵͳ����Ĭ�ϵĿ������캯���������ڴ�洢
////���ֽ�����ɿ��������ֿ�������ǳ����  ����ֵ����
//
//
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}

//��ֵ���������
//����������Ǿ������⺯�����ĺ���
//��������Ϊ���ؼ���operator�������Ҫ�����������
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
	//���������thisָ��ĵ��ú����Ķ���
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