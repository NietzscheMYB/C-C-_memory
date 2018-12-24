#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int main()
{
	double r, PI;
	PI = atan(1.0) * 4;
	scanf("%lf", &r);
	printf("%.7lf\n", PI*r*r);
	return 0;
}