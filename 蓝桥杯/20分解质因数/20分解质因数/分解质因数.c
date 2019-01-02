#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int n;
	int flag = 1;
	int  i = 2;
	for (; a <= b; a++)
	{
		n = a;
		printf("%d=", a);
		while (n != 1)
		{
			while (n%i == 0)
			{
				if (flag == 1)
				{
					printf("%d", i);
					flag = 0;
				}
				else
				{
					printf("*%d", i);
				}
				n = n / i;
			}
			i++;
		}
		flag = 1;
		i = 2;
		printf("\n");
	}
	return 0;
}