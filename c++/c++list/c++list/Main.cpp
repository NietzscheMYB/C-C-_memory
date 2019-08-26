//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	list<int> l1;//构造空的l1
//	list<int> l2(4, 100);//l2中放4个值为100的元素
//	list<int> l3(l2.begin(),l2.end());//用l2的begin(),end()左闭右开的区间构造l3
//	list<int> l4(l3);
//
//	//以数组为迭代器区间构造l5
//	int arr[] = {16,2,77,29};
//	list<int> l5(arr,arr+sizeof(arr)/sizeof(int));
//	
//
//	//用迭代器方式来打印l5中的元素
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//c++11迭代器打印
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
//	//使用数组作为迭代器进行构造
//	list<int> l(arr, arr +sizeof(arr)/sizeof(int) );
//	//使用正向迭代器正向打印list中的元素
//	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	//使用反向迭代器逆向打印list中的元素
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	//const的正向迭代器
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
//	//用数组当作迭代器进行构造
//	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
//	//打印list中有效节点的个数
//	cout << l.size() << endl;
//	//检查list是否为空
//	if (l.empty())
//	{
//		cout << "空的list" << endl;
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
//	//将list中的第一个节点与最后一个节点中的值改为10
//	l1.front() = 10; //list的第一个节点
//	l1.back() = 10;//list的第二个节点
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
//	//在list尾部插入4，头部插入0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	//删除list尾部节点和头部节点
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
////push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，在调拷贝构造函数
////emplace_back尾插：先构造节点，然后调用构造节点，然后调用构造函数在节点中直接构造对象
////emplace_back比push_back更高效，少一次拷贝构造函数的调用
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
//	//获取链表中第二个节点
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//	//在pos前插入值为4的元素
//	L.insert(pos, 4);
//	PrintList(L);
//	//在pos前插入v.begin(),v.end()区间中的元素
//	vector<int> v{7,8,9};
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	//删除pos位置上的元素
//	L.erase(pos);
//	PrintList(L);
//
//	//删除list中begin，end区间中的元素，即删除list中的所以元素
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//void TestList4()
//{
//	//用数组来构造list
//	int arr[] = { 1, 2, 3 };
//	list<int> l1(arr,arr+sizeof(arr)/sizeof(arr[0]));
//	PrintList(l1);
//
//
//	//将l1中元素个数增加到10个，多出元素用默认值填充
//	l1.resize(10);
//	PrintList(l1);
//
//	//将l1中的元素增加到20个，多出的元素用4来填充
//	l1.resize(20, 4);
//	PrintList(l1);
//
//	//将l1中的元素减少到5个
//	l1.resize(5);
//	PrintList(l1);
//
//	//用vector中的元素来构造list
//	vector<int> v{ 4, 5, 6 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//
//	//交换l1和l2中的元素
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	//将l2中的元素清空
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
		//错误写法
		//l.erase(it);
		//++it;
		//erase()函数执行后，it所指向的节点已经被删除，因此it无效，在下一次使用it时，必须先给其赋值
		l.erase(it++);//it=l.erase(it)
	}
}
int main()
{
	TestListIterator1();
	return 0;
}