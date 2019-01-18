#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int Judge4(char *p)
{
	if(strlen(p)<8)
		return 0;
	return 1;
}
int Judge1(char *p)
{
	int i = 0;
	for (i = 0; i < strlen(p); i++)
	{
		if (*(p + i) >= 'A'||*(p + i) <= 'Z'||*(p + i) >= '0'||*(p + i) <= 9 || *(p + i) >= 'a'&&*(p + i) <= 'z')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int Judge2(char *p)
{
	if (*p >= '0'&&*p <= '9')
		return 0;
	return 1;
}
int Judge3(char *p)
{
	int i = 0;
	int j = 0;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	for (i = 0; i < strlen(p); i++)
	{
		if (*(p + i) >= 'A'&&*(p + i) <= 'Z')
		{
			flag1 = 1;
		}
		if (*(p + i) >= 'a'&&*(p + i) <= 'z')
		{
			flag2 = 1;
		}
		if (*(p + i) >= '0'&&*(p + i) <= '9')
		{
			flag3 = 1;
		}
		
	}
	if ((flag1&&flag2) || (flag1&&flag3) || (flag3&&flag2))
		return 1;
	return 0;
}
int main()
{
	char arr[100][100];
	int n;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		int ret1 = Judge1(&arr[i]);
		int ret2 = Judge2(&arr[i]);
		int ret3 = Judge3(&arr[i]);
		int ret4 = Judge4(&arr[i]);
		if (ret1&&ret2&&ret3&&ret4)
			printf("YES\n");
		else{
			printf("NO\n");
		}
	}
	return 0;
}