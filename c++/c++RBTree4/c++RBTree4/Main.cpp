//#include"RBTree.h"
//#include "Map.hpp"
#include"Set.hpp"


void Test()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, KeyOfValue> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;

	RBTree<int, KeyOfValue>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}
int main()
{
	TestSet();

	return 0;
}