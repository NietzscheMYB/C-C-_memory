#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int i, j, k;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			for (k = 0; k < 9; k++)
			{
				if ((i * 100 + j * 10 + k) == (i*i*i + j*j*j + k*k*k))
				{
					if ((i*100+j*10+k)>99)
					printf("%d\n", i * 100 + j * 10 + k);
				}
			}
		}
	}
	return 0;
}