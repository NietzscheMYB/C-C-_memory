#include "stdio.h"
void Print_wei(int a)
{
	int arr[32] = {0};
	int i=0;
	int count=0;
	while (a)
	{
		arr[i++] = a % 10;
		a /= 10;
		count++;
	}
	printf("它共%d位\n", count);
	for (i = count-1; i >=0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
int main()
{
	int a;
	int arr[32] = {0};
	printf("请输入一个整数>");
	
	scanf("%d", &a);
	Print_wei(a);
	return 0;
}