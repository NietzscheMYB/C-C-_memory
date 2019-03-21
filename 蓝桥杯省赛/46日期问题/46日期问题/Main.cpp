//
// Created by zhengwei.
//
/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。

样例输入
----
02/03/04

样例输出
----
2002-03-04
2004-02-03
2004-03-02

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

//1960年1月1日至2059年12月31日
//AA/BB/CC
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include <set>
void i2s(int i, string &s)
{
	stringstream ss;
	ss << i;
	ss >> s;
}

bool check(int a)
{
	return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}
string f(int a, int b, int c)
{
	if (a >= 0 && a <= 59)a += 2000;
	else if (a >= 60 && a <= 99)a += 1900;
	else return "";
	bool Is_Leap = check(a);
	if (b<1 || b>12)
	{
		return "";
	}
	if (c<1 || c>31)
	{
		return "";
	}
	switch (b)
	{
	case 2:
		if (Is_Leap&&c > 29) return "";
		if (!Is_Leap&&c > 28) return "";
		break;
	case 4:
		if (c > 30) return "";
		break;
	case 6:
		if (c > 30) return "";
		break;
	case 9:
		if (c > 30) return "";
		break;
	case 11:
		if (c > 30) return "";
		break;
	}
	string _a, _b, _c;
	i2s(a, _a);
	i2s(b, _b);
	i2s(c, _c);
	if (_b.length() == 1)_b = "0" + _b;
	if (_c.length() == 1)_c = "0" + _c;

	return _a + "-" + _b + "-" + _c;
}
int main()
{
	string in;
	cin >> in;
	int a = 0, b = 0, c = 0;
	a = (in[0] - '0') * 10 + (in[1] - '0');
	b = (in[3] - '0') * 10 + (in[4] - '0');
	c = (in[6] - '0') * 10 + (in[7] - '0');

	string case1 = f(a, b, c);
	string case2 = f(c, a, b);
	string case3 = f(c, b, a);

	set<string>ans;
	if (case1 != "") ans.insert(case1);
	if (case2 != "") ans.insert(case2);
	if (case3 != "") ans.insert(case3);

	for (set<string>::iterator iter = ans.begin(); iter != ans.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}