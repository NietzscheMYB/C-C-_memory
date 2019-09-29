#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long  arr[100] = { 0 }; arr[0] = 0; arr[1] = 1; arr[2] = 1;
	for (int i = 3; i<100; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	long long  ans[100] = { 0 };
	for (int i = 0; i<100; i++)
	{
		ans[i] = abs(n - arr[i]);
	}
	int min = ans[0];
	for (int i = 0; i<100; i++)
	{
		if (min>ans[i])
		{
			min = ans[i];
		}
	}
	cout << min << endl;
}