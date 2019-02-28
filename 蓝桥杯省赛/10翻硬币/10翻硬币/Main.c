#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>
int main()
{
	char Int[100] = { '0' };
	char target[100] = { '0' };
	scanf("%s", &Int);
	scanf("%s", &target);
	int start = -1;
	int len = strlen(Int);
	int i = 0,count=0;
	for (i = 0; i < len; i++)
	{
		if (Int[i] != target[i])
		{
			if (start == -1)
			{
				start = i;
			}
			else{
				count += i - start;
				start = -1;
			}
		}
	}
	printf("%d\n", count);
}