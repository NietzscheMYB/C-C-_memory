#include <iostream>
using namespace std;
#include <cstring>
#include <math.h>
int ans = 0;
int arr[3000] = { 0 };
int check(int n)
{
	if (n % 2 == 0)
	{
		return 0;
	}
	int k = sqrt(n);
	int i;
	for (i = 2; i <=k; i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	if (i == k)
	{
		return 1;
	}
}
int main()
{
	int i = 2,j=1;
	memset(arr, 0, sizeof(arr));
	arr[0] = 2;
	for (i = 2; i < 30000; i++)
	{
		if (check(i))
		{
			arr[j++] = i;
		}
	}
	int d = 0;
	for (i = 0; i < 3000; i++)
	{
		int first = arr[i];
		for (d = 1; d < arr[2999] - first; d++)
		{
			int m = first;
			for (j = 1; j < 10; j++)
			{
				m += d;
				if (check(m))
				{
					break;
				}
				if (j == 9)
				{
					printf("%d\n", d);
					return 0;
				}
			}
		}
	}
	return 0;
}