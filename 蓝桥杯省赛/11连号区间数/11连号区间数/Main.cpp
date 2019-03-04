#include <iostream>
using namespace std;
int arr[5000] = { 0 };
int main()
{
	int ans = 0;
	int n=0;
	cin >> n;
	int i = 0,j=0,min=0,max=0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		min = arr[i], max = arr[i];
		for (j = i; j < n; j++)
		{
			if (arr[j]>max)
			{
				max = arr[j];
			}
			if (arr[j] < min)
			{
				min = arr[j];
			}
			if (i == j)
			{
				ans++;
			}
			else
			{
				if (max - min + 1 == j - i + 1)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}