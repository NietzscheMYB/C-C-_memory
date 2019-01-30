#include <stdio.h>
#pragma warning(disable:4996)
int D(int n)
{
	int i = 0,num=n;
	while (n)
	{
		num += n % 10;
		n = n / 10;
	}
	return num;
}
void FindAlone(int n)
{
	int i,j, flag = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{

			if (D(j) == i)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d\n", i);
		}
		if (flag == 1)
		{
			flag = 0;
		}
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n<0 || n>10000)
	{
		return 0;
	}
	int i = 0;
	FindAlone(n);
	return 0;
}
