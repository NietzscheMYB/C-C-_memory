#include <stdio.h>
#pragma warning(disable:4996)
int  main()
{
	double x;
	scanf("%lf", &x);
	double arr[500] = { 0 };
	int i = 0;
	int step = 0;
	double sum = 0;
	arr[0] = 2;
	while (sum <=x)
	{
		sum += arr[i];
		i++;
		arr[i] = arr[i - 1] * 0.98;
	}
	step = i;
	printf("%d\n", step);
	return 0;
}