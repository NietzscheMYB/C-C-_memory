#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	char arr[100][100] = { 'a' };
	int k = 0;
	scanf("%d", &k);
	int i = 0, j = 0;
	for (i = 0; i < k; i++)
	{
		gets(arr[i]);
	}
	return 0;
}