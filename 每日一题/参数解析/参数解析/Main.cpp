
#if 0
#include <iostream>
#include <string>
using namespace std; 
int main() 
{ 
	string str; 
	while (getline(cin, str)) 
	{ 
		int count = 0; //���ȼ���������� 
		for (int i = 0; i < str.size(); i++) 
		{ if (str[i] == ' ') 
		count++; //�����˫���ţ���������ֱ����һ��˫���Ž��� 
		if (str[i] == '"') 
		{ 
			do { i++; } 
		while (str[i] != '"'); 
		} 
		} //�Կո����������ո������Ȳ���������1 
		cout << count + 1 << endl; //��flag��ʾ�Ƿ����˫���ţ�0��ʾ��˫���� //˫�����еĿո�Ҫ��ӡ���� //�����ı�flag��ֵ������˫���ſ���ʹflag��ԭ 
		int flag = 1; 
		for (int i = 0; i < str.size(); i++) 
		{ //��˫���ţ�flagͨ������Ϊ0����һ��������˫���ţ�flag��Ϊ1 
			if (str[i] == '"') flag ^= 1; //˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"') 
			cout << str[i]; //˫�����еĿո�Ҫ��ӡ 
			if (str[i] == ' ' && (!flag)) 
			cout << str[i]; //����˫����֮��Ŀո�ͻ��� 
			if (str[i] == ' ' && flag) cout << endl; 
		} 
		cout << endl; 
	} 
	return 0;
}
#endif


#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int flag = 0;
	string temp1;
	string temp2;
	vector<string> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '"'&&flag==0)
		{
			flag=1;
			temp2 += s[i];
			continue;
		}
		if (s[i] == '"'&&flag == 1)
		{
			flag = 0;
			v.push_back(temp2);
			temp2.clear();
			continue;
		}
		if (s[i] != ' ')
		{
			temp1 += s[i];
			continue;
		}
		if (s[i] == ' ')
		{
			v.push_back(temp1);
			temp1.clear();
			continue;
		}
	}
	v.push_back(temp1);
	cout << v.size() << endl;
	for (auto &e : v)
	{
		cout << e << endl;
	}
	return 0;
}