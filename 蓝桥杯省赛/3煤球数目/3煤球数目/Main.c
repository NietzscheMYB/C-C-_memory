#include <stdio.h>

int main()
{
	int arr[100];
	int i, j=0;
	arr[0] = 1;
	arr[1] = 3;
	int sum = arr[0] + arr[1];
	for (i = 2,j=3; i < 100; i++)
	{
		arr[i] = arr[i - 1] + j++;
		sum += arr[i];
	}
	printf("%d\n", sum);
	return 0;
}