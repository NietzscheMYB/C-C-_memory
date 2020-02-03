#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n, m;
	cin >> n >> m;
	vector<string> v;
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}
	if (n == 1)
	{
		for (int i = 0; i < v.size(); i++)
		{
			size_t fd = v[i].find(s);
			if (fd != string::npos)
			{
				cout << v[i] << endl;
			}
		}
	}
	else{
		transform(s.begin(), s.end(),s.begin(),::toupper);
		for (int i = 0; i < v.size(); i++)
		{
			string tem = v[i];
			transform(tem.begin(), tem.end(),tem.begin(), ::toupper);
			size_t fd = tem.find(s);
			if (fd != string::npos)
			{
				cout << v[i] << endl;
			}
		}
	}
	return 0;
}