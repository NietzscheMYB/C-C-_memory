//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	list<int> l1;//����յ�l1
//	list<int> l2(4, 100);//l2�з�4��ֵΪ100��Ԫ��
//	list<int> l3(l2.begin(),l2.end());//��l2��begin(),end()����ҿ������乹��l3
//	list<int> l4(l3);
//
//	//������Ϊ���������乹��l5
//	int arr[] = {16,2,77,29};
//	list<int> l5(arr,arr+sizeof(arr)/sizeof(int));
//	
//
//	//�õ�������ʽ����ӡl5�е�Ԫ��
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//c++11��������ӡ
//
//	for (auto& x : l5)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,0};
//	//ʹ��������Ϊ���������й���
//	list<int> l(arr, arr +sizeof(arr)/sizeof(int) );
//	//ʹ����������������ӡlist�е�Ԫ��
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//ʹ�÷�������������ӡlist�е�Ԫ��
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//const�����������
//	auto cit = l.cbegin();
//	cout << typeid(cit).name() << endl;
//	for (auto &xx : l)
//	{
//		cout << xx << " ";
//	}
//	cout << endl;
//	
//	return 0;
//}

//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	//�����鵱�����������й���
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//	//��ӡlist����Ч�ڵ�ĸ���
//	cout << l.size() << endl;
//	//���list�Ƿ�Ϊ��
//	if (l.empty())
//	{
//		cout << "�յ�list" << endl;
//	}
//	else
//	{
//		for (auto &e : l)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,0};
//	list<int> l1(arr, arr + sizeof(arr) / sizeof(int));
//	for (auto& e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//��list�еĵ�һ���ڵ������һ���ڵ��е�ֵ��Ϊ10
//	l1.front() = 10; //list�ĵ�һ���ڵ�
//	l1.back() = 10;//list�ĵڶ����ڵ�
//	for (auto& e : l1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	const list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	const int& ca = l2.front();
//
//	return 0;
//}
//#include<vector>
//#include<iostream>
//#include<list>
//using namespace std;
//void PrintList(list<int>& l)
//{
//	for (auto &x : l)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//}
//void TestList1()
//{
//	int arr[] = { 1, 2, 3 };
//	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//��listβ������4��ͷ������0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	//ɾ��listβ���ڵ��ͷ���ڵ�
//	L.pop_back();
//	L.pop_front();
//	PrintList(L);
//}
//class Date{
//public:
//	Date(int year=1900,int month=1,int day=1)
//		:_year(year)
//		, _month(month)
//		, _day(_day)
//	{
//		cout << "Date(int,int,int)" << this << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date&)" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ڵ��������캯��
////emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
////emplace_back��push_back����Ч����һ�ο������캯���ĵ���
//void TestList2()
//{
//	list<Date> l;
//	Date d(2018, 10, 21);
//	l.emplace_back(2018, 10, 21);
//	l.emplace_front(2018, 10, 19);
//}
//
//
//void TestList3()
//{
//	int arr[] = {1,2,3};
//	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	//��ȡ�����еڶ����ڵ�
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//	//��posǰ����ֵΪ4��Ԫ��
//	L.insert(pos, 4);
//	PrintList(L);
//	//��posǰ����v.begin(),v.end()�����е�Ԫ��
//	vector<int> v{7,8,9};
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	//ɾ��posλ���ϵ�Ԫ��
//	L.erase(pos);
//	PrintList(L);
//
//	//ɾ��list��begin��end�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//void TestList4()
//{
//	//������������list
//	int arr[] = { 1, 2, 3 };
//	list<int> l1(arr,arr+sizeof(arr)/sizeof(arr[0]));
//	PrintList(l1);
//
//
//	//��l1��Ԫ�ظ������ӵ�10�������Ԫ����Ĭ��ֵ���
//	l1.resize(10);
//	PrintList(l1);
//
//	//��l1�е�Ԫ�����ӵ�20���������Ԫ����4�����
//	l1.resize(20, 4);
//	PrintList(l1);
//
//	//��l1�е�Ԫ�ؼ��ٵ�5��
//	l1.resize(5);
//	PrintList(l1);
//
//	//��vector�е�Ԫ��������list
//	vector<int> v{ 4, 5, 6 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//
//	//����l1��l2�е�Ԫ��
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	//��l2�е�Ԫ�����
//	l2.clear();
//	cout << l2.size() << endl;
//}
//int main(){
//	//TestList2();
//	TestList4();
//	return 0;
//}

#include<iostream>
#include<list>
using namespace std;
void TestListIterator1()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		//����д��
		//l.erase(it);
		//++it;
		//erase()����ִ�к�it��ָ��Ľڵ��Ѿ���ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it++);//it=l.erase(it)
	}
}
int main()
{
	TestListIterator1();
	return 0;
}