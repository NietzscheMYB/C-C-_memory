#include <stdio.h>
int main()
{
	int c;
	int a, b;
	printf("求两个数的平均值\n");
	printf("请输入两个值>");
	scanf("%d%d", &a, &b);
	if (a > b)
	{
		c = (a - b) / 2 + b;
	}
	if (a < b)
	{
		c = (a - b) / 2 + a;
	}
	if (a == b)
	{
		c = a;
	}
	printf("这两个数的平均值为>%d", c);
}