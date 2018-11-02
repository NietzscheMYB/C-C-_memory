#include "stdio.h"
//void Print_two(int x)
//{
//	int count=0;
//	int arr[32] = {0};
//	int i = 0;
//	while (x)
//	{
//		arr[i++] = x % 2;
//		x = x / 2;
//		count++;
//	}
//	printf("偶数位\n");
//	for (i =0; i <count; i + 2)
//	{
//		
//		printf("%d ", arr[i]);
//	}
//	printf("奇数位\n");
//	for (i=0; i<count; i + 2)
//	{
//		
//		printf("%d ", arr[i]);
//	}
//	
//}
void print_num(unsigned value)
{
	int count = 0;//计算二进制 位数
	int a[32] = { 0 };
	int i = 0;
	while (value) {
		a[i++] = value % 2;
		value /= 2;
		count++;
	}
	printf("奇数序列\n");
	for (i = 0; i <=count; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("偶数序列\n");
	for (i = 0; i <= count; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a;
	printf("请输入一个数>");
	scanf("%d", &a);
	print_num(a);
	//Print_two(a);

	return 0;
}