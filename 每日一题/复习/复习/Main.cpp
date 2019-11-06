#if 0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < v.size(); i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long sum = 0;
		int x = n;
		for (int i = v.size() - 2; i>0 && n>0; i = i - 2, n--)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}

	return 0;
}
#endif


#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++)
	{
		int index = s1.find(s2[i]);//Ã»ÓĞ·µ»Ø-1
		if (index>0)
		{
			s1.erase(index, 1);
		}
	}
	cout << s1;
	s1.clear();
	s2.clear();
	return 0;
}
#endif



#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	string ret;
	int hashtable[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		hashtable[s2[i]]++;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (hashtable[s1[i]] == 0)
		{
			ret += s1[i];
		}
	}

	cout << ret << endl;

	return 0;
}































