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
	printf("������һ�����������Ĵη�\n" );
	scanf("%d%d", &i, &j);
	ret = Factorial(i, j);
	printf("���Ľ����%d\n", ret);
	return 0;
}