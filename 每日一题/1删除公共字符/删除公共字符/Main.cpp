#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string str1, str2;
	//oj中输入字符串用getline
	getline(cin, str1);
	getline(cin, str2);
	int hashtable[256] = { 0 };
	//哈希映射思想统计str2字符出现的次数
	for (size_t i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ' ')
		{
			continue;
		}
		hashtable[str2[i]]++;
	}
	string ret;
	//遍历str1 在hashtable中0为没有出现的字符 str1[1]加到ret上
	for (size_t i=0; i < str1.size(); i++)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	
	return 0;
}