#include"RBTree.h"


void Test()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	t.InOrder();

}
int main()
{
	Test();

	return 0;
}