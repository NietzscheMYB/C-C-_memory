/*像这种简单的换算问题 直接用********** (% /)*********
不要想的太复杂

*******将原数按除法和取余运算分离出每个值，
然后再输出

!!!!!!!!*/




#include "stdio.h"
#include <windows.h>
#pragma warning(disable:4996)
int main()
{
	int b, c, d;
	int t;
	scanf("%d", &t);
	b = t / 3600;
	c = (t / 60) % 60;
	d = t % 60;
	printf("%d:%d:%d", b, c, d);
	system("pause");
	return 0;
}