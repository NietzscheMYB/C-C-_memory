#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	int arr[12] = { 0 };
	int i = 0,pre=0;
	double sum=0;
	for (i = 0; i < 12; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 12; i++)
	{
		if (arr[i]<=(pre+300))
		{
			pre = 300 + pre - arr[i];
			if (pre >= 100)
			{
				sum = sum + pre / 100 * 100;
				pre = pre%100;
			}
			continue;
		}
		if (arr[i] > (pre + 300))
		{
			printf("-%d\n", i+1);
			return 0;
		}
	}

	printf("%d\n",(int)(sum*1.2+pre));
	return 0;
}