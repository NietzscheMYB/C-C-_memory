#include <stdio.h>
int main()
{
	double x = 2.3, y = 1.9, sum = 82.3;
	int  n = 0, m = 0;
	double i = 1.0,j=1.0,max1=sum/x,max2=sum/y;
	//printf("%llf\n", sum);
	for (j=1.0; j < max2; j++)
	{
		for (i=1.0; i < max1; i++)
		{
			if (i < j)
			{

				if ((i*x + j*y) == sum)
				{
					printf("%llf %llf\n", i, j);
				}
			}
		}
	}

	return 0;
}