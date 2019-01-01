#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int max, min;
	int arr[10000];
	int n,sum=0;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	min = arr[0];
	max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (min>arr[i])
		{
			min = arr[i];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
		sum += arr[i];
	}
	printf("%d\n%d\n%d\n", max, min, sum);
	return 0;
}