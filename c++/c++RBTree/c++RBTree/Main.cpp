//红黑树确保没有一条路径会比其他路径长出两倍，因而是近似平衡的
//红黑树：近似平衡
//AVL树：高度平衡

//5个性质
//1.每个节点不是红色就是黑色
//2.根节点是黑色
//3.如果一个节点是红色，则它的两个孩子节点是黑色的
//红色只能接黑的，黑的啥都能接            保证平衡
//4.对于每个节点，从该节点到其后代节点的简单路径上，均含有相同数目的黑色节点
//插入时也要满足，全黑的节点的红黑树不存在。
//5.每个叶子节点都是黑色(此处的叶子节指的是空节点)


#include<iostream>
#include"RBTree.h"
using namespace std;

void Test()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	t.InOrder();

	if (t.IsValidRBTree())
	{
		cout << "正确" << endl;
	}

}

int main()
{
	Test();
	return 0;
}