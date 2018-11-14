#include <stdio.h>
int Resever(int a)
{
	int top = sizeof(int)* 8;
	int flag = 1;
	int i=0;
	int ret=0;
	while (i < top)
	{
		if (a&(flag << i))
		{
			ret |= (flag << 31 - i);
		}
		i++;
	}
	return ret;
}
int main()
{
	int a;
	int b;
	printf("请输入一个值>");
	scanf("%d", &a);
	b = Resever(a);
	printf("%d : %d", a, b);
	return 0;
}