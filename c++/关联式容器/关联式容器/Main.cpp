#include <iostream>
#include<map>
#include <string>
using namespace std;
//void testMap()
//{
//	map<int, int> map1;
//	map1.insert(make_pair(0, 1));
//	map1.insert(pair<int, int>(2, 3));
//
//	map<string, string> disctMap;
//	disctMap.insert(make_pair("中国", "China"));
//	disctMap.insert(make_pair("科技", "Tech"));
//	disctMap["西安"] = "xian";
//	auto dit = disctMap.begin();
//	while (dit != disctMap.end())
//	{
//		cout << dit->first << " " << dit->second << endl;
//		++dit;
//	}
//}
void TestMap()
{
	//key和value的类型都给成字符串
	map<string, string> m1{ { "apple", "苹果" }, {"banan","香蕉"}

	, { "orange", "橘子" }, {"peach","桃子"} };
	//通过对key值的访问找到value
	cout << m1["apple"] << endl;
	cout << m1["banan"] << endl;
	//cout << m1._Getpfirst() << endl;

	map<string, string> m2(m1);
	for (auto it = m2.begin(); it != m2.end(); ++it)
	{
		cout << (*it).first << "---->" << (*it).second << endl;
	}
	cout << endl;
	
}

void test()
{
	map<string, string> m;

}
int main()
{
	TestMap();
	return 0;
}