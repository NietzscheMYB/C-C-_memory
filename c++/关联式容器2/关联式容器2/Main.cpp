#include <iostream>
#include <map>
#include<functional>
#include<string>
#include<set>
using namespace std;

void testMap()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(2, 3));
	m1.insert(make_pair(0, 1));
	m1[5] = 1;
	auto dit = m1.begin();

	//operator[]
	//先创建pair 然后进行一个插入，返回一个pair 然后拿到它的first 得到迭代器 在解引用 然后拿到second  最后=号进行修改


	//map键值不允许重复！！
	while (dit != m1.end())
	{
		cout << dit->first<<""<<dit->second<<endl;
		dit++;
	}

}

void testmap()
{
	//map<int, string> m1; //greater<int> 加入仿函数 从大到小排序
	map<int, string, greater<int>> m1;
	m1[8] = "中国";
	m1[2] = "美国";
	m1[1] = "de国";
	m1[2] = "美国";
	m1[2] = "ee国";
	m1[3] = "法国";
	for (const auto& e : m1)
	{
		cout << e.first << ""<< e.second << endl;
	}
	//二叉搜索树时间复杂度为log（n)跟高度有关
	int key;
	//count 判断键值存不存在！！
	/*while (cin>>key)
	if (m1.count(key))
	{
		cout << key << "---->" << m1[key] << endl;
	}
	else
	{
		cout << "not dind key:" << key << endl;
	}*/
	cin >> key;
	if (m1.find(key) != m1.end())
	{
		cout << m1[key] << endl;
	}
}
void test()
{
	//multimap<int, string, greater<int>> m1;
	multimap<int, string> m1;
	//multimap 不提供[]操作，因为key不唯一
	m1.insert(make_pair(1, "中国"));
	m1.insert(make_pair(2, "美国"));
	m1.insert(make_pair(3, "法国"));
	m1.insert(make_pair(4, "德国"));
	/*cout << m1.count(1) << endl;
	for (const auto &e : m1)
	{
		cout << e.first << "--->" << e.second << endl;
	}*/

	//low_bound 返回第一个<= 的迭代器
	auto mit = m1.lower_bound(3);
	cout << mit->first << "" << mit->second << endl;
	cout << endl;

	//upper_bound 返回第一个>的迭代器
	mit = m1.upper_bound(3);
	cout << mit->first << "" << mit->second << endl;
}
void testSet()
{
	////set  值不允许修改  只能先删除后插入
	//set<int> s1;
	//s1.insert(1);
	//s1.insert(10);
	//s1.insert(18);
	//s1.insert(1);
	//s1.insert(2);
	//s1.insert(3);
	////set 去重复
	//for (const auto&e : s1)
	//{
	//	cout << e << endl;
	//}
	multiset<int> s1;
	s1.insert(1);
	s1.insert(10);
	s1.insert(18);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	//set 去重复
	for (const auto&e : s1)
	{
		cout << e << endl;
	}
}
int main()
{
	testSet();
	return 0;
}