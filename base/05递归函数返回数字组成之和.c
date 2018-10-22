#include <stdio.h>
int DigitSum(int a)
{
	if (a < 10)
		return a;
	else
		return a % 10 + DigitSum(a / 10);
}
int main()
{
	int i;
	int ret;
	printf("请输入一个数\n");
	scanf("%d", &i);
	ret = DigitSum(i);
	printf("它的各部分和为%d\n", ret);
	return 0;
}