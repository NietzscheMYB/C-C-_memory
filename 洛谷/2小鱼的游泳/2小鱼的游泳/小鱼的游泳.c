#include <stdio.h>
#pragma warning (disable:4996)
int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int minute1 = a * 60 + b;
	int minute2 = c * 60 + d;
	int minute3 = minute2 - minute1;
	f = minute3 % 60;
	e = minute3 / 60;
	printf("%d %d\n", e, f);
	return 0;
}