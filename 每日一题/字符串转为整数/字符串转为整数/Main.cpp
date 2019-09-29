#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
		{
			return 0;
		}
		int flag1 = 1;
		int flag2 = 0;
		if (str[0] == '+')
		{
			flag1 = 1;
			flag2 = 1;
		}
		else if (str[0] == '-')
		{
			flag1 = 0;
			flag2 = 1;
		}
		int sum = 0;
		//reverse(str.begin(),str.end());
		for (size_t i = 0; i<str.size(); i++)
		{
			if (flag2 == 1)
			{
				flag2 = 0;
				continue;

			}
			if (str[i] <= '9'&&str[i] >= '0')
			{
				char temp = str[i];
				sum = sum * 10;
				sum += temp - '0';
			}
			else{
				return 0;
			}
		}
		if (flag1 == 1)
		{
			sum = sum;
		}
		if (flag1 == 0)
		{
			sum = -sum;
		}
		return sum;
	}
};