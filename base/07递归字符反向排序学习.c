
/*实现数组元素的反转*/
#include<stdio.h>
#include<string.h>
#define N 6
void arr_reverse(char arr[], int sz);
void arr_print(char arr[], int n);
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 't' };
	int sz = sizeof(arr) / sizeof(arr[0]);
	arr_reverse(arr, sz);
	arr_print(arr, N);
	return 0;
}
void arr_print(char arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}

void arr_reverse(char arr[], int sz)
{
	char tmp = arr[0];
	arr[0] = arr[sz - 1];
	arr[sz - 1] = '\0';
	if (strlen(arr + 1) > 1)
	{
		arr_reverse(arr + 1, strlen(arr + 1));
	}
	arr[sz - 1] = tmp;
}