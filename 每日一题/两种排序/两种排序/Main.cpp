#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);

#if 0
	for (auto &x : v)
	{
		cin >> x;
	}
#endif
	for (auto& x : v)
	{
		cin >> x;
	}
	bool f1 = false, f2 = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i].size() <= v[i + 1].size())
		{
			f1 = true;
		}
		else{
			f1 = false;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{

		//这个比较是按照字符串的字典比较
		if (v[i] <= v[i + 1])
		{
			f2 = true;
		}
		else
		{
			f2 = false;
			break;
		}
	}
	if (f1 == false && f2 == false)
	{
		printf("none");
		return 0;
	}
	if (f1 == true && f2 == false)
	{
		printf("lengths");
		return 0;
	}
	if (f1 == false && f2 == true)
	{
		printf("lexicographically");
		return 0;
	}
	if (f1 == true && f2 == true)
	{
		printf("both");
		return 0;
	}
	return 0;
}