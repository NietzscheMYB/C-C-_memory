#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, ans, cur;
	cin >> s1;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] >= '0'&&s1[i] <= '9')
		{
			cur += s1[i];
		}
		else
		{
			if (ans.length() < cur.length())
			{
				ans.clear();
				ans = cur;
			}
			else
			{
				cur.clear();
			}
		}
	}
	//���ܻ��������һ�ε�������������ж�һ��
	if (ans.length() < cur.length())
	{
		ans.clear();
		ans = cur;
	}
	else
	{
		cur.clear();
	}
	cout << ans << endl;
	return 0;
}