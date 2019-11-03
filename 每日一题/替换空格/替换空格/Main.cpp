#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
#if 0
		string s;
		s.resize(100);
		for (int i = 0; i<length; i++)
		{
			s[i] = str[i];
		}
		string t = "%20";
		string s2;
		s2.resize(100);
		for (int i = 0, j = 0; s[i] != '\0'; i++, j++)
		{
			if (s[i] == ' ')
			{
				for (int k = 0; k < 3; k++, j++)
				{
					s2[j] = t[k];
				}
				j--;
				continue;
			}
			s2[j] = s[i];
		}
		int m = 0;
		for (m = 0; s2[m] != '\0'; m++)
		{
			str[m] = s2[m];
		}
		str[m] = '\0';
#endif
		string s(str);
		int j = 0;
		size_t i= 0;
		while (s[j]!='\0')
		{
				if ((i = s.find(' '))<=s.size())
				{
					s.erase(i, 1);
					s.insert(i, "%20");
				}
			j++;
		}
		auto x = s.c_str();
		strcpy(str, x);
	}

};
int main()
{
	char p[100] = "We Are Happy";
	Solution s;
	 s.replaceSpace(p, strlen(p));

	string ss = "1234";
	/*char pp[]="abcd";
	for (int i = 0; i < ss.size(); i++)
	{
		pp[i] = ss[i];
	}*/
	cout << p << endl;
	return 0;
}