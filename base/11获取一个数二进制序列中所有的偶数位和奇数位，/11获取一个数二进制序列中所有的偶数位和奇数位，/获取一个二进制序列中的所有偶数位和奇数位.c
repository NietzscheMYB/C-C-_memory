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
//	printf("ż��λ\n");
//	for (i =0; i <count; i + 2)
//	{
//		
//		printf("%d ", arr[i]);
//	}
//	printf("����λ\n");
//	for (i=0; i<count; i + 2)
//	{
//		
//		printf("%d ", arr[i]);
//	}
//	
//}
void print_num(unsigned value)
{
	int count = 0;//��������� λ��
	int a[32] = { 0 };
	int i = 0;
	while (value) {
		a[i++] = value % 2;
		value /= 2;
		count++;
	}
	printf("��������\n");
	for (i = 0; i <=count; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("ż������\n");
	for (i = 0; i <= count; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a;
	printf("������һ����>");
	scanf("%d", &a);
	print_num(a);
	//Print_two(a);

	return 0;
}