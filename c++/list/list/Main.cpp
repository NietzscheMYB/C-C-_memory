#include<list>
#include<vector>
#include<iostream>
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
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	PrintList(l1);

	return 0;
}