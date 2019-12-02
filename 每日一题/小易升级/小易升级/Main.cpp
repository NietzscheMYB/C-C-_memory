#include<iostream>
#include<vector>
using namespace std;

int fun(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}
	while (a%b != 0)
	{
		int x = a%b;
		a = b;
		b = x;
	}
	return b;
}



int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int sum = m;
		for (int i = 0; i < n; i++)
		{
			if (v[i] <= sum)
			{
				sum += v[i];
			}
			else{
				sum += fun(v[i], sum);
			}
		}
		cout << sum << endl;
		v.clear();
	}

	return 0;
}