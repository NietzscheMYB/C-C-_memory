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

int main()
{
	list<int> l1;  //构造
	l1.push_back(1);  //简单插入
	l1.push_back(2);
	l1.push_back(3);
	PrintList(l1);
	l1.pop_back();
	PrintList(l1);
	list<int> l2(l1);  //拷贝构造
	PrintList(l2);
	list<int> l3(4, 8);  //生成4个为8的int
	PrintList(l3);

	list<int>l4(l3.begin(), l3.end());  //用迭代器
	PrintList(l4);

	list<string>l5;
	l5.push_back("hello");
	l5.push_back("world");
	l5.push_front("myb");
	PrintList(l5);

	return 0;
}