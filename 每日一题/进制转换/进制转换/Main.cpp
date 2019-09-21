#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	string s, table = "0123456789ABCDEF";
	//输入m的值可能为负数，负数也要换成进制
	bool flag = false;
	if (m < 0)
	{
		flag = true;
		m = -m;
	}
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
	{
		s += '-';
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}