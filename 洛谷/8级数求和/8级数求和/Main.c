#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	double k;
	scanf("%lf", &k);
	double sum = 0,n=1;
	while (sum <=k)
	{
		sum += 1/n;
		n++;
	}
	printf("%.lf\n", n-1);
	return 0;
}
