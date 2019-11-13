#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
int main()
{
	int n = 0;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	int flag1 = 0, flag2 = -1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() <= v[i].size())
		{
			flag1 = 1;
		}
		if (v[i - 1].size() > v[i].size())
		{
			flag1 = 0;
			break;
		}
	}
	int flag3 = -1;
	for (int i = 1; i < v.size(); i++)
	{
		int k = 0;
		for (int j = 0; j < v[i-1].size(); j++,k++)
		{
			if (v[i - 1][k] == v[i][j])
			{
				flag2 = 1;
				continue;
			}
			if (v[i - 1][k] < v[i][j])
			{
				flag2 = 1;
				break;
			}
			if (v[i - 1][k] > v[i][j]){
				flag2 = 0;
				break;
			}
		}
		if (flag2 == 0)
		{
			flag3 = 0;
		}
	}
	if (flag3 == 0)
	{
		flag2 = 0;
	}
	if (flag1 == 1 && flag2 == 1)
	{
		cout << "both" << endl;
		return 0;
	}
	if (flag1 == 1)
	{
		cout << "lengths" << endl;
		return 0;
	}
	if (flag2 == 1)
	{
		cout << "lexicographically" << endl;
		return 0;
	}
	//if (flag1 == 1 && flag2 != 1)
	//{
	//	cout << "lengths" << endl;
	//	return 0;
	//}
	//if (flag1 != 1 && flag2 == 1)
	//{
	//	cout <<"lexicographically" <<endl;
	//	return 0;
	//}
	cout << "none" << endl;
	return 0;
}
#endif
 


#if 1
int fun(int a1,int b1)
{
	int a=a1, b=b1;
	
	if (a < b)
	{
		int a2 = a, b2 = b;
		while (b2%a2 != 0)
		{
			int k = b2%a2;
			b2 = a2;
			a2 = k;
		}
		return a*b / a2;
	}
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		int a2 = a, b2 = b;
		while (a2%b2 != 0)
		{
			int k = a2%b2;
			a2 = b2;
			b2 = k;
		}
		return a*b / a2;
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	int ret = fun(a, b);
	cout << ret << endl;
	return 0;
}
#endif