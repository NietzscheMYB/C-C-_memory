#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int money = a * 10 + b;
	int sum = money / 19;
	printf("%d\n", sum);
	return 0;
}