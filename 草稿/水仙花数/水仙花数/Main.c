//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int a=0, b=0, c=0;
//	for (i = 100; i < 999; i++)
//	{
//		a = i / 100;
//		b = i / 10 % 10;
//		c = i % 10;
//		if (i == a*a*a + b*b*b + c*c*c)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int score = 0;
	printf("请输入分值：\n");
	scanf("%d", &score);
	while (score > 100 || score < 0)
	{
		printf("输入错误请重新输入:\n");
		scanf("%d", &score);
	}
	if (score >= 90 && score <= 100)
	{
		printf("A\n");
	}
	else if (score >= 80)
	{
		printf("B\n");
	}
	else if (score >= 70)
	{
		printf("C\n");
	}
	else if (score >= 60)
	{
		printf("D\n");
	}
	else
	{
		printf("E\n");
	}
	return;
}


