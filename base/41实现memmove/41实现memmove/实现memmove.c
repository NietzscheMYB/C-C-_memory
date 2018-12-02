#include <stdio.h>
#include <windows.h>
#include <assert.h>
void *My_memmove(char dst[], const char *src, int n)
{
	char *ret = dst;
	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	return ret;
}
int main()
{
	char dst[] = { "skjfkf" };
	const char *src = { "djkf" };
	char *ret=My_memmove(dst, src, sizeof(src));
	printf("%s\n", dst);
	system("pause");
	return 0;
}