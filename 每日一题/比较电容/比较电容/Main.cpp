
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	v.resize(n + 1);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(2);
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}

	multimap<int, int> m;
	for (int i = 0; i < v.size() - 1; i++)
	{
		m.insert(make_pair(v[i][0], v[i][1]));
	}
	multimap<int, int> m1(m);
	multimap<int, int> m2(m);


	int x = v[n][0], y = v[n][1];
	int flag1 = 0;
	auto it = m1.find(x);
	while (it != m1.end())
	{
		while (it != m1.end())
		{
			if (it->second != y)
			{
				it = m1.find(it->second);
				continue;
			}
			if (it->second == y)
			{
				flag1 = 1;
				break;
			}
		}
		m1.erase(x);
		it = m1.find(x);
	}


	if (flag1 == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	x = v[n][1], y = v[n][0];
	int flag2 = 0;
	it = m2.find(x);
	while (it != m2.end())
	{
		while (it != m2.end())
		{
			if (it->second != y)
			{
				it = m2.find(it->second);
				continue;
			}
			if ((it->second) == y)
			{
				flag2 = 1;
				break;
			}
		}
		m2.erase(x);
		it = m2.find(x);
	}
	if (flag2 == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	if (flag1 == 0 && flag2 == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	return 0;
}
