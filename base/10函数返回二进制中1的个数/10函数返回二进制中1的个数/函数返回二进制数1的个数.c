#include "stdio.h"
//void Print_tow(int x)
//{
//	int i;
//	if (x == 1)
//	{
//		printf("1");
//	}
//	if (x == 2)
//		printf("10");
//	if (x % 2 == 0)
//	{
//		printf("1");
//		for (i = 0; i < x / 2; i++)
//			printf("0");
//	}
//	if (x % 2 != 0)
//	{
//		printf("1");
//		Print_tow(x / 2);
//	}
//}

int count_one(int x)
{
	////int i;
	//if (x == 2)
	//{
	//	return 1;
	//}
	///*if (x % 2 == 0&&x!=2)
	//	return 0;*/
	//if (x % 2 == 0)
	//{
	//	return 1;
	//}
	//if (x % 2 != 0)
	//{
	//	//x = x / 2;
	//	return  1+count_one(x/2);
	//}
	int count = 0;
	while (x != 0)
	{
		if (x % 2 == 1)
		{
			count++;
		}
		x = x / 2;
	}
	return count;
}
int main()
{
	int a;
	int count;
	//int b;
	printf("请输入一个数>");
	scanf("%d", &a);
	count = count_one(a);
	//printf("这个数的二进制为>");
	//Print_tow(a);
	printf("二进制1的个数为>%d\n", count);
	return 0;
}