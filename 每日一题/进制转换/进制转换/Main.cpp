#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	string s, table = "0123456789ABCDEF";
	//����m��ֵ����Ϊ����������ҲҪ���ɽ���
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