#include <stdio.h>
int Factorial(int i)
{
	if (i == 1)
		return 1;
	else
		return i*Factorial(i-1);
}


int main()
{
	int i;
	int ret;
	printf("请输入你要计算的阶乘数不能太大\n");
	scanf("%d", &i);
	ret = Factorial(i);
	printf("这个结果为%d\n", ret);
	return 0;
}