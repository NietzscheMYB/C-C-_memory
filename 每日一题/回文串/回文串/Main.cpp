#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;

	int count = 0;
	for (int i = 0; i <= s1.size(); i++)
	{
		string s3(s1);
		s3.insert(i, s2);
		string s4(s3);
		reverse(s3.begin(), s3.end());
		if (s4 == s3)
		{
			count++;
		}
		s3.clear();
		s4.clear();
	}

	cout <<count << endl;

	return 0;
}


#if 0
int main()
{

	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	vector<int> sum;
	sum.resize(n);
	sum[0] = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		sum[i] = v[i]+sum[i-1];
	}
	int max = 0;
	for (int i = 1; i < sum.size(); i++)
	{
		if (sum[i] < 0)
		{
			continue;
		}
		if ((sum[i - 1] + v[i]) < 0)
		{
			continue;
		}
		if ((sum[i - 1] + v[i])>0)
		{
			if (max < (sum[i - 1] + v[i]))
			{
				max = sum[i - 1] + v[i];
			}
		}
	}
	

	cout << max << endl;

	return 0;
}
#endif