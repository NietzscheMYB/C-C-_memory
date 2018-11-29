#include <stdio.h>
#include <windows.h>
#include <assert.h>
int My_strcmp(const char *p1, const char *p2)
{
	int flag = 1;
	char *pp1 = p1;
	char *pp2 = p2;
	int num1 = 1,num2=1;
	int count = 0;
	while (*pp1)
	{
		pp1++;
		num1++;
	}
	while (*pp2)
	{
		pp2++;
		num2++;
	}
	while (flag)
	{
		if (*p1 == *p2)
		{
			count++;
		}
		if (*p1 > *p2)
		{
			return 1;
		}
		if (*p1 < *p2)
		{
			return -1;
		}
		if (count == num1&&count == num2)
		{
			return 0;
		}
		p1++;
		p2++;
	}
}
int main()
{
	const char *p1 = {"aj"};
	const char *p2 = {"aj"};
	int a = 0;
	a = My_strcmp(p1, p2);
	if (a == 0)printf("×Ö·û´®1µÈÓÚ×Ö·û´®2\n");
	if (a > 0)printf("×Ö·û´®1´óÓÚ×Ö·û´®2\n");
	if (a < 0)printf("×Ö·û´®1Ð¡ÓÚ×Ö·û´®2\n");
	system("pause");
	return 0;
}