#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	char arr1[1000],arr2[1000];
	scanf("%s%s", &arr1, &arr2);
	int len1 = strlen(arr1), len2 = strlen(arr2);
	int i = 0, j = 0;
	int arr3[1000], arr4[1000];
	for (i = len1 - 1,j=0; i >= 0; i--,j++)
	{
		arr3[j] = arr1[i] - '0';
	}
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
	{
		arr4[j] = arr2[i] - '0';
	}
	int c[2000] = { 0 };
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			c[i + j] += arr3[i]* arr4[j];    //a[0] * b[0] = c[0]; a[0] * b[1] + a[1] * b[0] = c[1];逐渐我们可以发现规律： "c[i + j] += a[i] * b[j]"同过一个循环去实现，就可以把c[i + j]计算出来，需要指出的是，这里的计算我们还没有进行进位处理。

		}
	}

	for (i = 0; i < len1 + len2; i++)
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] = c[i] %10;
			continue;
		}
		if (c[i] < 10)
		{
			continue;
		}
	}
	for (j = 1999; j >= 0; j--)
	{
		if (c[j] != 0)
		{
			break;
		}
	}
	for (i = j; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;


}