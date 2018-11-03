#include "stdio.h"
int main()
{
	int i, j;
	int a, b;
	int max;
	int count=0;
	int arr1[32] ;
	int arr2[32] ;
	printf("请输入两个数>");
	scanf("%d%d",&a,&b);
	for (i = 0; i < 32; i++)
	{
		arr1[i] = 0;
	}
	for (i = 0; i < 32; i++)
	{
		arr2[i] = 0;
	}
	i = 0;
	while (a)
	{
		arr1[i++] = a % 2;
		a = a / 2;
	}
	j = 0;
	while (b)
	{
		arr2[j++] = b % 2;
		b = b / 2;
	}
	i = i - 1;
	j = j - 1;
	if (i > j)
	{
		max = i;
	}
	else
	{
		max = j;
	}
	for (i =max; i >= 0; i--)
	{
		if (arr1[i] != arr2[i])
		{
			count++;
		}
	}
	printf("两个数的不同位为>%d\n", count);
}