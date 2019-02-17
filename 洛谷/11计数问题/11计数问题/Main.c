#include <stdio.h>
#pragma warning(disable:4996)
int Countnum(int x, int m)
{
	int count = 0;
	while (x)
	{
		if (x % 10 == m)
		{
			count++;
		}
		x = x / 10;
	}
	return count;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i = 0, sum = 0;
	int flag = 1;
	while (flag <= n)
	{
		sum += Countnum(flag, m);
		flag++;
	}
	printf("%d\n", sum);
	return 0;
}