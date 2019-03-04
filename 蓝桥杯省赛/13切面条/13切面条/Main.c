#include <stdio.h>
int main()
{
	//int n = 512,sum=0;
	//while (n)
	//{
	//	sum += n;
	//	n = n / 2;
	//}
	//sum = sum + 2;
	//printf("%d\n", sum);
	int i = 1,sum=2;
	for (i = 1; i <= 10; i++)
	{
		sum = 2 * sum - 1;
	}
	printf("%d\n", sum);

}