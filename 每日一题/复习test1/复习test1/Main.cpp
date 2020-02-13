#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

namespace test1{
	//���鼯
	//ά�����ϵ����ݽṹ��
	//֧������������1���ϲ���������  2.���ң��ж�����Ԫ���Ƿ���һ������
	
	//��һ��father������ʵ�ֲ��鼯
	//father[i] ��ʾԪ��i�ĸ��׽ڵ㣬�����׽ڵ㱾��Ҳ�����Ԫ���ڵļ���
	//father[i]=i˵��Ԫ��i�Ǹü��ϵĸ��ڵ�
	//father[2]=1 2�ĸ��׽ڵ���1
	const int N = 100;
	int father[N];

	//��ʼ��
	void FatherInit(int father[],int len)
	{
		//һ��ʼÿ��Ԫ�ض��Ƕ����ļ��ϣ����ÿ��Ԫ�صĸ���������
		for (int i = 1; i <= len; i++)
		{
			father[i] = i;
		}
	}
	
	//���� ,���ƻ�ݹ�ʵ��
	int findFather(int x)
	{
		int tem1 = x;
		while(x != father[x])
		{
			x=(father[x]);
		}
		//��·�������нڵ㶼��Ϊ���ڵ�
		while (tem1 != father[tem1])
		{
			int tem2 = tem1;
			tem1 = father[tem1];
			father[tem2]= x;
		}

		return x;
	}

	//�ϲ� �������Ϻϲ���һ�����ϣ�ֻ�е���Ԫ�ز���ͬһ�������ڲſ�ʼ�ϲ�
	//�ϲ����̣���һ�����ϵĸ��׽ڵ�ָ����һ�����ϵĸ��ڵ�
	//1.���ж�����Ԫ���Ƿ���ͬһ�����ϣ�ֻ��Ҫ�ж����Ǹ��ڵ��Ƿ���ͬ
	//2.��һ��Ԫ�صĸ��׽ڵ�ָ����һ�����׽ڵ�
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