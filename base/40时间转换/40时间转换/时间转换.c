/*�����ּ򵥵Ļ������� ֱ����********** (% /)*********
��Ҫ���̫����

*******��ԭ����������ȡ����������ÿ��ֵ��
Ȼ�������

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