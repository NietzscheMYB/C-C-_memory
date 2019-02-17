#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int main()
{
	int x=0,y=0;
	scanf("%d%d", &x, &y);
	long long num1 = y*log(x);
	long long num2 = x*log(y);   //两边取对数进行简化操作！！
	if (num1 > num2)
	{
		printf(">\n");
		return 0;
	}
	if (num1 < num2)
	{
		printf("<\n");
		return 0;
	}
	if (num1 == num2)
	{
		printf("=\n");
		return 0;
	}
	return 0;
}