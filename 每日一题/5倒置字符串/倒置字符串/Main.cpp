#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s1;
	getline(cin, s1);//防止空格切分，
	string tmp, ans;
	//先将整个字符串反转，再以空格为单位 反转每个单词！！！
	reverse(s1.begin(), s1.end());
	int flag = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != ' ')
		{
			tmp += s1[i];
		}
		else
		{
			reverse(tmp.begin(), tmp.end());
			ans +=tmp+' ';
			tmp.clear();
		}
	}
	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	cout << ans << endl;
	return 0;
}