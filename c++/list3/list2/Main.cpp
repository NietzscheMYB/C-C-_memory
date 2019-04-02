#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template <class T>
void PrintList(const list<T>& l)
{
	auto lit = l.cbegin();
	while (lit != l.cend())
	{
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int)" << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date &d)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test1()
{
	list<int> l1;  //����
	l1.push_back(1);  //�򵥲���
	l1.push_back(2);
	l1.push_back(3);
	PrintList(l1);
	l1.pop_back();
	PrintList(l1);
	list<int> l2(l1);  //��������
	PrintList(l2);
	list<int> l3(4, 8);  //����4��Ϊ8��int
	PrintList(l3);

	list<int>l4(l3.begin(), l3.end());  //�õ�����
	PrintList(l4);

	list<string>l5;
	l5.push_back("hello");
	l5.push_back("world");
	l5.push_front("myb");
	PrintList(l5);

	//return 0;
}

void test2()
{
	/*list<int> l1;
	l1.push_back(1);
	l1.emplace_front(0);
	l1.push_back(2);
	l1.emplace_back(3);
	PrintList(l1);*/

	list<Date> l;
	l.push_back(Date(2018, 8, 7));
	cout << "emplace:" << endl;
	l.emplace_front(2018);
	//PrintList(l);

	Date d(2018, 8, 8);   //���ù��캯��
	list<Date> l2;			//���ù��캯��
	l2.push_back(d);      //���ÿ������캯��
	l2.push_back(d);      //���ÿ������캯��
	l2.push_back(d);		//���ÿ������캯��
	l2.push_back(d);		//���ÿ������캯��
	cout << l.size() << endl;
	cout << l2.size() << endl;

}

void test3()
{
	list<int> l1;
	l1.push_back(9);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(5);
	l1.push_back(5);
	l1.push_back(5);

//	PrintList(l1);
	//l1.remove(5);   //remove ȫ��ɾ��
	//PrintList(l1);
	//l1.remove(10);
	//PrintList(l1);
	l1.sort();
	PrintList(l1);
	l1.unique();   //ȥ�ظ���������Ҫ����
	PrintList(l1);
}

void test4()
{
	list<int> l2;
	l2.push_back(11);
	l2.push_back(9);
	l2.push_back(18);
	l2.reverse();     //����
	PrintList(l2);
	reverse(l2.begin(), l2.end());  //����
	PrintList(l2);
	list<int> l1;
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

}

int main()
{
	test4();
	return 0;
}