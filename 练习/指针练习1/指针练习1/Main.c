#include <stdio.h>
#pragma warning(disable:4996)
void Test1()
{
	char a[20] = {'0'};
	int *p;
	p= (int *)a;
	p++;

	
}

void Test2()
{
	char a[20] = "abcdefg";
	int *p = (int *)a;
	p += 3;
}

int main()
{
	Test2();
	return 0;
}