
 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;
	
	vector<vector<int>> v;
	v.resize(w);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(h,1);
	}
//x2-x1=2,y2-y1=0          x2-x1=0, y2-y1=2
	int num = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (v[i][j] == 1)
			{
				num++;
				if ((i + 2) < w)
				{
					v[i + 2][j] = 0;
				}
				if ((j+2)<h)
				{
					v[i][j + 2] = 0;
				}
			}

		}
	}

	cout << num << endl;
	return 0;
}
 


#if 0
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		if (str[0] == '+')
		{
			vector<int> v;
			for (int i = 1; i < str.size(); i++)
			{
				if (str[i] <= '9'&&str[i] >= '0')
				{
					v.push_back(str[i] - '0');
				}
				else{
					return 0;
				}
			}
			int num = 0,flag=1;
			int len = v.size();
			for (int i = 0; i < len; i++)
			{
				num += flag*v.back();
				flag *= 10;
				v.pop_back();
			}
			return num;
		}
		else if (str[0] == '-')
		{
			vector<int> v;
			for (int i = 1; i < str.size(); i++)
			{
				if (str[i] <= '9'&&str[i] >= '0')
				{
					v.push_back(str[i] - '0');
				}
				else{
					return 0;
				}
			}
			int num = 0, flag = 1;
			int len = v.size();
			for (int i = 0; i <len; i++)
			{
				num += flag*v.back();
				flag *= 10;
				v.pop_back();
			}
			num = -num;
			return num;
		}
		else if (str[0] <= '9'&&str[0] >= '0')
		{
			vector<int> v;
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] <= '9'&&str[i] >= '0')
				{
					v.push_back(str[i] - '0');
				}
				else{
					return 0;
				}
			}
			int num = 0, flag = 1;
			int len = v.size();
			for (int i = 0; i < len; i++)
			{
				num += flag*v.back();
				flag *= 10;
				v.pop_back();
			}
			return num;
		}
		else
		{
			return 0;
		}
	}
};
int main()
{
	Solution s;
	int ret=s.StrToInt("+2147483647");
	cout << ret << endl;
}
#endif