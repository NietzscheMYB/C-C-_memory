#include <stdio.h>
#pragma warning(disable:4996)
//int  arr[100000];
int main()
{
	int  arr[100000];
	int i, j=0, n;
	int  key,flag=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);
	for (i = 0; i < n; i++)
	{
		if (key == arr[i])
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}