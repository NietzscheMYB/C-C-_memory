#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int t;
	scanf("%d", &t);
	int i, j;
	int h, m, s;
	s = t % 60;
	m = t / 60 % 60;
	h = t / 60 / 60 % 60;
	printf("%d:%d:%d\n", h, m, s);
	return 0;
}