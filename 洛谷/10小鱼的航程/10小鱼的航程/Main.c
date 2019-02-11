#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int n, x;
	scanf("%d%d", &x, &n);
	int i = 0,sum=0;
	for (i = 1; i <= n; i++)
	{
		if (x != 6 && x!= 7)
		{
			sum += 250;
		}
		if (x == 7)
		{
			x = 1;
		}
		else
		{
			x++;
		}
	}
	printf("%d\n", sum);
	
	return 0;
}