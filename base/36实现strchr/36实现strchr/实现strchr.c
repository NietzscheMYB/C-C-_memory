#include <stdio.h>
#include <windows.h>
#include <assert.h>
char *My_strchr(const char *p1, char p2)
{
	assert(p1);
	assert(p2);
	int flag = 1;
	while (flag)
	{
		if (*p1 == p2)
		{
			break;
		}
		p1++;
	}
}
int main()
{
	const char *p1 = { "ajfdhlfndj" };
	char p2 = 'f';
	char *pst = My_strchr(p1, p2);
	printf("%c\n", *pst);
	system("pause");
	return 0;
}