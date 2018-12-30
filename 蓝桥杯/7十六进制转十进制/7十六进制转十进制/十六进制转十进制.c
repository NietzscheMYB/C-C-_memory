#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	char arr1[10000];
	char arr3[10000];
	int arr2[10000];
	long result=0;
	int coe = 1;
	scanf("%s", arr1);
	int i, j=0;
	for (i = strlen(arr1) - 1; i >= 0; i--)
		arr3[j++] = arr1[i];
	for (i = 0; i < j; i++)
	{
		if (arr3[i] >= 'A')
		{
			arr2[i] = arr3[i] - 'A'+10;
		}
		if (arr3[i] <= '9')
		{
			arr2[i] = arr3[i] - '0'+0;
		}
	}
	for (i =0; i <j; i++)
	{
		result = arr2[i] * coe + result;
		coe = coe * 16;
	}
	printf("%I64d", result);
	printf("\n");
	return 0;
}