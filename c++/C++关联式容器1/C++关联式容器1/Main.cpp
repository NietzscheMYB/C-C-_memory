#include<iostream>
#include<map>
#include<string>
using namespace std;
void TestMap()
{
	map<string, string> m;//空map
	//插入就是插入键值对，先构造键值对
	m.insert(pair<string, string>("宋江", "及时雨"));//构造键值对
	m.insert(pair<string, string>("李逵", "黑旋风"));//构造键值对

	//insert 返回是个pair<iterator,bool>
	//iterator:代表map key---value 的键值对
	//bool : insert 插入是否成功

	//构造键值对2种
	//1.pair  2.make_pair
	//直接make构造键值对
	auto ret = m.insert(make_pair("孙二娘","母夜叉"));
	if (ret.second)
	{
		cout << ret.first->first << "--->" << ret.first->second << endl;
	}
	ret = m.insert(pair<string, string>("李逵", "铁牛"));
	if (ret.second)
	{
		cout << ret.first->first << "--->" << ret.first->second << endl;
	}
	cout << ret.first->first << "--->" << ret.first->second << endl;


	cout << m.size() << endl;
	cout << m["李逵"] << endl;//下标运算符重载
	//用户提供key--->[]  返回key对应的value
	m["李逵"] = "铁牛"; //下标运算符
	cout << m["李逵"] << endl;
	m["林冲"] = "豹子头";//这也是插入操作，如果key不存在，也进行插入

	cout << m.size() << endl;

}
void TestMap2()
{
	int array[] = {3,1,9,4,0,7,6,2};
	map<int, int> m;
	for (auto e : array)
	{
		m.insert(make_pair(e, e));
	}
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.erase(1);
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}

}
int main()
{
	TestMap2();

	return 0;
}