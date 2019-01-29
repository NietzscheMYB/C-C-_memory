#include <stdio.h>
#pragma warning(disable:4996)
int Judge(int arr[], int n)
{
	int i=0,j=0;
	int arr1[30] = { 0 };
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n ; j++)
		{

			if (arr[i] == arr[j])
			{
				arr1[i]++;
			}
		}
	}
	int max = 0,flag=0;
	for (i = 0; i < n; i++)
	{
		if (max < arr1[i])
		{
			max = arr1[i];
			flag = i;
		}
	}
	printf("%d\n", arr[flag]);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n > 20||n<0)
	{
		return 0;
	}
	int arr[30];
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	Judge(arr, n);
	return 0;
}