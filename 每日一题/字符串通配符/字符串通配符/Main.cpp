#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool ret(const char str1[],const char str2[])
{
	if (*str1 == '\0'&&*str2 == '\0')
	{
		return true;
	}
	if (*str1 == '\0' &&*str2 != '\0')
	{
		return false;
	}
	if (*str1 != '\0' && *str2 == '\0')
	{
		return false;
	}
	if (*str1 == '?')
	{
		return ret(str1 + 1, str2 + 1);
	}
	if (*str1 == '*')
	{
		return ret(str1 + 1, str2 + 1) || ret(str1, str2 + 1) || ret(str1 + 1, str2);
	}
	if (*str1 == *str2)
	{
		return ret(str1 + 1, str2 + 1);
	}
	if (*str1 != *str2)
	{
		return false;
	}
}

int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		
		bool rett = ret(s1.c_str(), s2.c_str());
		if (rett)
		{
			cout << "true" << endl;
		}
		else{
			cout << "false" << endl;
		}
	}


	return 0;
}