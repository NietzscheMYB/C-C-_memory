#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int arr[7][2];
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j< 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 1; j++)
		{
			if ((arr[i][j] + arr[i][j + 1])>8)
			{
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}