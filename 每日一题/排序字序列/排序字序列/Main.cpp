#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	vector<string> v;
	string temp;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != ' ')
		{
			temp += s1[i];
		}
		else if ( s1[i] == ' ')
		{
			v.push_back(temp);
			temp.clear();
		}
		if (i == (s1.size() - 1))
		{
			v.push_back(temp);
			temp.clear();
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
		if (i != 0)
		{
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
#endif

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int count = 1;
	for (int i = 1; i < n-1; i++)
	{
		if (v[i-1]>v[i] && v[i] < v[i + 1] || v[i-1]<v[i] && v[i]>v[i + 1])
		{
			count++;
			if (i != n - 3)
			{
				i++;
			}
		}
	}
	cout << count<< endl;
	return 0;
}

