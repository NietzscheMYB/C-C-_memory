#include <iostream>
using namespace std;

//thisָ�벻��Ϊ��
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a <<  endl;
//	}
//	void Show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//	return 0;
//}

//class Date{
//public:
//	Date(int year,int month,int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class B{
//public:
//	B(Date a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	Date _aobj;//û��Ĭ�Ϲ��캯����Ĭ�Ϲ��캯�������޲ι��캯����ȫȱʡ���캯��
//	int& _ref;//����
//	const int _n;//const
//};

class xx{
	int xxx;   //class Ĭ�Ϸ���Ȩ��Ϊprivate   struct Ĭ�Ϸ���Ȩ��Ϊpublic
public:
	int y; 
	static int z;

	xx()
	{
		_count++;
	}
	~xx()
	{
		_count--;
		cout << _count << endl;
	}
	xx(const xx&a)
	{
		_count++;
	}
	static int add(int a, int b)
	{
		return a + b;
	}

private:
	static int _count;
};
int xx::_count = 0;
int xx::z = 0;               //���ⶨ�� ʵ���Ƿ����ڴ棡
//int xx::add(int a, int b)
//{
//	return a + b;
//}
int main()
{
	xx a, b;
	xx c(a);
	a.z = 1;
	int ret = a.add(1, 2);
	return 0;

}
