#include <stdio.h>
#define N 10
int main()
{
	int arr[N][N];
	int i = 0, j = 0;
	int flag=0;
	for (i = 0; i < N; i++)
	{for (j = 0; j < N; j++)
	{
		arr[i][j] = 1;
	}
	}
	for (i = 0; i < N; i++)
	{
		for (j =0; j < N;j++)
		{
			if (i >= 1&&j>=1)
			{arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}	
			
			if (i == j)
			{
				arr[i][j] = 1;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j<=i)
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;

}