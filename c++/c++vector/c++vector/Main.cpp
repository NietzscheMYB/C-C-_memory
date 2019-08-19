#include<iostream>
#include<vector>
using namespace std;
void PrintVector(const vector<int>& v)
{
	//使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	//用push_back插入4个数据
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//使用迭代器进行遍历打印
	vector<int>::iterator  it = v.begin();
	while (it != v.end())
	{
		cout << *it <<" ";
		++it;
	}
	cout << endl;
	//使用迭代器进行修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);

	//使用反向迭代器进行遍历再打印
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;

}
