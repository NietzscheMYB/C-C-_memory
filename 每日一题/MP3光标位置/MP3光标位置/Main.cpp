#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	string s;
	while (cin >>n>> s)
	{
#if 0
		int i = 1;
		int j = 1;
		int step = 0;
		int count = 0;
		for (int k = 0; k < s.size(); k++)
		{
			if (s[k] == 'U')
			{
				count++;
			}
			else if (s[k] == 'D')
			{
				count--;
			}
		}
		while (count != 0)
		{
			if (count < 0)
			{
				i++;
				step++;
				if (step % 4 == 0)
				{
					j++;
					step = 0;
				}
				count++;
				if (i>n)
				{
					i = 1;
					step = 0;
					j = 1;
				}

			}
			else if (count > 0)
			{
				i--;
				count--;
				step++;
				if (step % 4 == 0)
				{
					j = n-3;
				}
				if (i == 0)
				{
					i = n;
				}

			}
			if (count == 0)
			{
				break;
			}
		}

		int ans = i;

		while (i != j)
		{
			cout << i << " ";
			i++;
		}
		cout << i << endl;
		cout << ans << endl;
#endif
		//将n首歌曲编号1：n，num为光标当前所在歌曲的编号
		//first为当前屏幕显示页的第一首歌曲的编号
		int num = 1, first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (num == 1 && s[i] == 'U')
				{
					num = n;
				}
				else if (num == n&&s[i] == 'D')
				{
					num = 1;
				}
				else if (s[i] == 'U')
				{
					num--;
				}
				else{
					num++;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				cout << i << " ";
			}
			cout << endl;
			cout << num << endl;
		}
		else{
			for (int i = 0; i < s.size(); i++)
			{
				if (first == 1 && num == 1 && s[i] == 'U')
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n&&s[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first&&s[i] == 'U')
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && s[i] == 'D')
				{
					first++;
					num++;
				}
				else if (s[i] == 'U')
				{
					num--;
				}
				else{
					num++;
				}
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << " ";
			}
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}

	return 0;
}