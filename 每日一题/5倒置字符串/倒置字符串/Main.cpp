#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s1;
	getline(cin, s1);//��ֹ�ո��з֣�
	string tmp, ans;
	//�Ƚ������ַ�����ת�����Կո�Ϊ��λ ��תÿ�����ʣ�����
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