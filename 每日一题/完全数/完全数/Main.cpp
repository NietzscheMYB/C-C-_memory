#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				if (i%j == 0)
				{
					v.push_back(j);
				}
			}
			int sum = 0;
			for (int j = 0; j < v.size(); j++)
			{
				sum += v[j];
			}
			if (sum == i)
			{
				count++;
			}
			v.clear();
		}
		cout << count << endl;
	}


	return 0;
}