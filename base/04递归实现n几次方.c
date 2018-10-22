#include <stdio.h>
int Factorial(int a, int b)
{
	if (b == 1)
		return a;
	else
	{
		
		return a*Factorial(a,--b);
	}
}
int main()
{
	int ret = 0;
	int i, j;
	printf("请输入一个数和想计算的次方\n" );
	scanf("%d%d", &i, &j);
	ret = Factorial(i, j);
	printf("它的结果是%d\n", ret);
	return 0;
}