#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int i, j,m,n,k;
	for (i = 0; i <= 1; i++)
	{
		for (j = 0; j <= 1; j++)
		{
			for (m = 0; m <= 1; m++)
			{
				for (n = 0; n <= 1; n++)
				{
					for (k = 0; k <= 1; k++)
					{
						printf("%d%d%d%d%d\n", i, j, m, n, k);
					}
				}
			}
		}
	}
	return 0;
}