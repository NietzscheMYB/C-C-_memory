#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	long long temp,s=0;
	int n = 0;
	temp = n;
	scanf("%d",&temp);
	printf("%I64d\n", ((1 + temp)*temp) / 2);
	return 0;
}