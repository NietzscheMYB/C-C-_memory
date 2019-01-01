#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int sum, res;
	int num;
	for (i = 1000; i < 10000; i++)
	{
		num = i;
		sum = 0;
		res = 0;
		while (num)
		{
			res = res * 10 + num % 10;
			sum += num % 10;
			num = num / 10;
		}
		if (num == n&&res == i)
			printf("%d\n", i);
	}
	return 0;
}