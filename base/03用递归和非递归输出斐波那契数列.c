#include<stdio.h>
int Fibonacci(int n)
{
	int i;
	if (n == 1 || n == 2)
		return 1;
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
int main()
{
	int i = 0;
	int ret = 0;
	printf("������Ҫ�ڼ���쳲���������\n");
	scanf("%d", &i);
	ret = Fibonacci(i);
	printf("��%d��쳲���������Ϊ%d\n",i, ret);
	return 0;
}