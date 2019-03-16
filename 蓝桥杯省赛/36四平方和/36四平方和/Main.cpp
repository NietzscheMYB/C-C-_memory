#include <iostream>
#include <math.h>
using namespace std;
//这种写法肯定会超时
//假设数据很大采取另一种方法
int main()
{
	int k = 0;
	scanf("%d", &k);
	int m = sqrt(k)+1;
	int i = 0, j = 0,a=0,b=0;
	if (m <= 500)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				for (a = 0; a < m; a++)
				{
					for (b = 0; b < m; b++)
					{
						if (k == i*i + j*j + a*a + b*b)
						{
							printf("%d %d %d %d\n", i, j, a, b);
							return 0;
						}
					}
				}
			}
		}
	}
	else
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m/2; j++)
			{
				for (a = 0; a < m/3; a++)
				{
					for (b = 0; b < m; b++)
					{
						if (k == i*i + j*j + a*a + b*b)
						{
							printf("%d %d %d %d\n", i, j, a, b);
							return 0;
						}
					}
				}
			}
		}
	}
}