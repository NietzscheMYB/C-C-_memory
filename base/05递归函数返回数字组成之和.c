#include <stdio.h>
int DigitSum(int a)
{
	if (a < 10)
		return a;
	else
		return a % 10 + DigitSum(a / 10);
}
int main()
{
	int i;
	int ret;
	printf("������һ����\n");
	scanf("%d", &i);
	ret = DigitSum(i);
	printf("���ĸ����ֺ�Ϊ%d\n", ret);
	return 0;
}