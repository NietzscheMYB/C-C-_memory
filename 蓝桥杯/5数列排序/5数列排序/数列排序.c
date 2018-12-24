#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr[201] = { 0 };
	int n;
	int i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}