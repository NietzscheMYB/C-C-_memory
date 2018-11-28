#include <stdio.h>
#include <assert.h>
#include <windows.h>
#pragma warning (disable:4090)
char *My_strstr(const char *p1, const char *p2)
{
	assert(p1);
	assert(p2);
	int i = 0;
	int flag = 1;
	int count = 0;
	while (flag)
	{
		if (*p1 == *p2)
		{
			p2++;
			count++;
			if (*p2 == '\0')
			{
				flag = 0;
			}
		}
		p1++;
	}
	return p2-count;
}
int main()
{
	const char *p1 = { "abcdjk" };
	const char *p2 = { "cd" };
	char *p3 = My_strstr(p1,p2);
	printf("%s\n", p3);

	system("pause");
	return 0;
}