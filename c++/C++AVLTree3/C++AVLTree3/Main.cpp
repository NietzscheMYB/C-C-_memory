#include"AVL.h"

int main()
{
	AVLTree<int> t;
	//{16, 3, 7, 11, 9, 26, 18, 14, 15}
	//t.Insert(16);
	//t.Insert(3);
	//t.Insert(7);
	//t.Insert(11);
	//t.Insert(9);
	//t.Insert(26);
	//t.Insert(18);
	//t.Insert(14);
	//t.Insert(15);
	//4, 2, 6, 1, 3, 5, 15, 7, 16, 14
	t.Insert(4);
	t.Insert(2);
	t.Insert(6);
	t.Insert(1);
	t.Insert(3);
	t.Insert(5);
	t.Insert(15);
	t.Insert(7);
	t.Insert(16);
	t.Insert(14);
	t.InOrdor();
	bool ret = t.IsValidAVLTree();
	cout << ret << endl;
	return 0;


}