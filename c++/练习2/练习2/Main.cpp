#include <iostream>
using namespace std;
////1.���캯��
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
//	//��������d1,d2 ��SetDate���÷�����������������
//	//���� ���ÿ�δ���������SetDate�Ƚ��鷳
//	//�����������캯��
//	//���캯����һ������ĳ�Ա����������������ͬ������������
//	//ʱ�ɱ������Զ����ã���֤ÿ�����ݳ�Ա����һ�����ʵĳ�ʼֵ
//	//��ʼ������ �����ǿ��ռ䴴�����󣡣���
//	return 0;
//}


class Date
{
public:
	//1.�޲ι��캯��
	Date()
	{

	}
	//2.���ι��캯��
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
	Date d1;//�����޲ι��캯��
	Date d2(2018, 3, 8);//���ô��εĹ��캯��
	 //ע�⣺���ͨ���޲ι��캯����������ʱ��
	//������治��Ҫ�����ţ������Ϊ�˺���������
	Date d3();//������d3�������ú����޲Σ�����
	//һ���������͵Ķ���
}
//�������û����ʾ���幹�캯��
//��c++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯��
//�û���������������ڶ���
//int main()
//{
//	TestDate();
//	return 0;
//}
//-------------------------------------------------------

//2.��������
//���������ٵ�ʱ���Զ���������������������һЩ
//��Դ��������
//�����������ڽ�����ʱ��c++����ϵͳ�Զ�������������
//���������ĺ�������������ǰ��~



//5.��ֵ���������
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