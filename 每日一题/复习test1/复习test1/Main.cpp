#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

namespace test1{
	//并查集
	//维护集合的数据结构，
	//支持两个操作，1，合并两个集合  2.查找：判断两个元素是否在一个集合
	
	//用一个father数组来实现并查集
	//father[i] 表示元素i的父亲节点，而父亲节点本身也是这个元素内的集合
	//father[i]=i说明元素i是该集合的根节点
	//father[2]=1 2的父亲节点是1
	const int N = 100;
	int father[N];

	//初始化
	void FatherInit(int father[],int len)
	{
		//一开始每个元素都是独立的集合，因此每个元素的父亲是自身
		for (int i = 1; i <= len; i++)
		{
			father[i] = i;
		}
	}
	
	//查找 ,递推或递归实现
	int findFather(int x)
	{
		int tem1 = x;
		while(x != father[x])
		{
			x=(father[x]);
		}
		//把路径的所有节点都改为根节点
		while (tem1 != father[tem1])
		{
			int tem2 = tem1;
			tem1 = father[tem1];
			father[tem2]= x;
		}

		return x;
	}

	//合并 两个集合合并成一个集合，只有当两元素不在同一个集合内才开始合并
	//合并过程，把一个集合的父亲节点指向另一个集合的根节点
	//1.先判断两个元素是否在同一个集合，只需要判断它们根节点是否相同
	//2.将一个元素的父亲节点指向另一个父亲节点
	void Union(int x, int y)
	{
		int fx = findFather(x);
		int fy = findFather(y);
		if (fx == fy)
		{
			return;
		}
		father[fx] = fy;
	}
	//unordered_map<int, int> F;
	//int father(int x) {
	//	if (F.count(x) == 0)
	//		return x;
	//	if (F[x] != x)
	//		F[x] = father(F[x]);
	//	return F[x];
	//}

	//int longestConsecutive(vector<int>& nums) {
	//	F.clear();
	//	for (auto x : nums) {
	//		F[x] = father(x);
	//		if (F.count(x - 1) > 0)
	//			F[father(x - 1)] = father(x);
	//		if (F.count(x + 1) > 0)
	//			F[father(x)] = father(x + 1);
	//	}
	//	int res = 0;
	//	for (auto x : nums)
	//	if (father(x) - x + 1 > res)
	//		res = father(x) - x + 1;
	//	return res;
	//}


}

class Solution {
public:
	int findfather(unordered_map<int, int> &father, int x)
	{
		if (father.count(x) == 0)
		{
			father[x] = x;
			return x;
		}
		if (x != father[x])
		{
			return findfather(father, father[x]);
		}
		return x;
	}
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> father;

		for (int i = 0; i<nums.size(); i++)
		{
			int x = findfather(father, nums[i]);
			//if (father.count(x - 1) != 0)
			//{
			//	father[x - 1] = x;
			//}
			//if (father.count(x + 1) != 0)
			//{
			//	father[x] = x + 1;
			//}
			if (father.count(x - 1) != 0)
			{
				father[x - 1] = x;
				if (father.count(x + 1) != 0)
				{
					father[x - 1] = x + 1;
					father[x] = x + 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (findfather(father, nums[i]) - nums[i] + 1>res)
			{
				res = findfather(father, nums[i]) - nums[i] + 1;
			}
		}
		return res;

	}
};



int main()
{
	vector<int> v;
	v.push_back(100);
	v.push_back(4);
	v.push_back(200);
	v.push_back(1);
	v.push_back(3); v.push_back(2);
	Solution s;
	cout << s.longestConsecutive(v) << endl;
	return 0;
}