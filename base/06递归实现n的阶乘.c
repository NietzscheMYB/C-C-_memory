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
	printf("��������Ҫ����Ľ׳�������̫��\n");
	scanf("%d", &i);
	ret = Factorial(i);
	printf("������Ϊ%d\n", ret);
	return 0;
}