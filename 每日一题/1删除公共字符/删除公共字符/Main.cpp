#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string str1, str2;
	//oj�������ַ�����getline
	getline(cin, str1);
	getline(cin, str2);
	int hashtable[256] = { 0 };
	//��ϣӳ��˼��ͳ��str2�ַ����ֵĴ���
	for (size_t i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ' ')
		{
			continue;
		}
		hashtable[str2[i]]++;
	}
	string ret;
	//����str1 ��hashtable��0Ϊû�г��ֵ��ַ� str1[1]�ӵ�ret��
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