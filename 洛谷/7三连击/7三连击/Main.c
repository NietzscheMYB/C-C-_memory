#include <stdio.h>
#pragma disable(warning:4996)
void Save(int arr[],int n,int m)
{
	while (m)
	{
		arr[n++] = m % 10;
		m = m / 10;
	}
	return;
}
void Borble_sort(int arr2[])
{
	int i = 0, j = 0,t=0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - 1 - i; j++)
		{
			if (arr2[j]>arr2[j + 1])
			{
				t = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = t;
			}
		}
	}
}
int Same(int arr1[], int arr2[])
{
	int i = 0,flag=0;
	for (i = 0; i < 9; i++)
	{
		if (arr1[i] == arr2[i])
		{
			flag++;
		}
		else
		{
			continue;
		}
	}
	if (i == flag)
	{
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	int i = 0,j=0,k=0;
	int num[3] = { 0 };
	int arr1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[9] = { 0 };
	int n=0,b=3,m=6;
	int temp = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 1; k < 10; k++)
			{
				num[0] = 100 * i + 10 * j + k;
				num[1] = 2 * num[0];
				num[2] = 3 * num[0];
				if (num[0] >999 || num[1]>999 || num[2]>999)
					continue;
				Save(arr2,n, num[0]);
				Save(arr2,b, num[1]);
				Save(arr2,m, num[2]);
				Borble_sort(arr2);
				temp = Same(arr1, arr2);
				if (temp == 1)
				{
					printf("%d %d %d\n", num[0], num[1], num[2]);
				}
				else{
					continue;
				}
			}
		}
	}
	return 0;
}