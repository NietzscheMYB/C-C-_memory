#include <stdio.h>
int main()
{
	int c;
	int a, b;
	printf("����������ƽ��ֵ\n");
	printf("����������ֵ>");
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
	printf("����������ƽ��ֵΪ>%d", c);
}