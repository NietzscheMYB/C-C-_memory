#include<stdio.h>
#pragma warning(disable :4996)
void Different_bit(int m, int n)
{
	int k1 = 0, k2 = 0;
	int count = 0;
	int flag = 1;
	int i = 1;
	for (i = 1; i <= 32; i++)
	{
		k1 = flag&m;
		k2 = flag&n;
		if (k1 != k2)
		{
			count++;
		}
		flag <<= 1;
		k1 = 0;
		k2 = 0;
	}
	printf("%d\n", count);

}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	Different_bit(m, n);
	return 0;
}