#include <stdio.h>
#pragma warning(disable :4996)
int main()
{
	char arr1[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	char arr2[26][26] = { '0' };
	int n, m;
	int i, j;
	int flag1 = 0,flag2=0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		flag1 = i;
		for (j = 0; j < m; j++)
		{
			flag2 = j;
			if (j<i)
			{
				arr2[i][j] = arr1[j-flag2 +flag1--];
			}
			if (j>=i)
			{
				arr2[i][j] = arr1[j-i];
			}
		}

	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%c", arr2[i][j]);
		}
		printf("\n");
	}
	return 0;
}