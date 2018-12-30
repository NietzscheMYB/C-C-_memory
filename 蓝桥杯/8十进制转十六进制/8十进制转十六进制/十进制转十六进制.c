#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	char arr1[] = { "0123456789ABCDEF" };
	long n;
	int flag = 0;
	int i;
	int j = 1;
	char arr2[10];
	scanf("%d", &n);
	if (n == 0)
		printf("0");
	while (n)
	{
		
		arr2[flag++] = arr1[n % 16];
		n = n / 16;
		
	}

	for (i = flag-1 ; i >= 0; i--)
		printf("%c", arr2[i]);
	printf("\n");
	return 0;
}