#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int n;
	int arr[3][2];
	int i, j;
	int money[3] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int flag = 1;
	//double m;
	for (i = 0; i < 3; i++)
	{
		if (n>arr[i][0])
		{
			if (n%arr[i][0] == 0)
			{
				money[i] = (n / arr[i][0])*arr[i][1];
				continue;
			}
			else
			{
				money[i] = (n / arr[i][0]+1)*arr[i][1];
				continue;
			}
		}
		if (n <= arr[i][0])
		{
			if (flag == 1)
			{
				money[i]= arr[i][1];
				flag++;
				continue;
			}
			if (flag == 2)
			{
				money[i] = arr[i][1];
				flag++;
				continue;

			}
			if (flag == 3)
			{
				money[i] = arr[i][1];
				flag++;
				continue;
			}
		}
	}
	int min = money[0];
	for (i = 0; i < 3; i++)
	{
		if (min > money[i])
		{
			min = money[i];
		}
	}
	printf("%d\n", min);
	return 0;
}