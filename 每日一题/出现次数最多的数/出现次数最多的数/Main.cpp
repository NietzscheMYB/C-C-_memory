#include<iostream>
#include<vector>
using namespace std;
int main()
{
//	int n[10000] = { -1 };
	vector<int> v(10000, -1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v[k - 1]++;
	}
	int index = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (v[index] < v[i])
		{
			index = i;
		}
	}
	cout << index+1 << endl;
	return 0;
}