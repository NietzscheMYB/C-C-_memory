
#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int Judge3(int n);
int Judge2(int m);
int Judge1(int k);

int Judge3(int n)
{
	/*int ret = m;
	int count = 0;
	int num = 0;
	int i = 0;
	int flag = 1;
	int  arr[10000];
	for (i = 0; i < 10000; i++)
	{
		arr[i] = 0;
	}
	while (m)
	{
		arr[count++] = m % 10;
		m = m / 10;
	}
	for (i = count - 1; i >= 0; i--)
	{
		num = arr[i] * flag + num;
		flag = flag * 10;
	}
	if (num == ret)
		return 0;
	if (num != ret)
		return num;*/
	int ret = n;
		int i = 0;
	int sum = 0;
	while (n != 0)
	{
		if (i == 0)
		{
			sum += n % 10;
			n /= 10;
			i++;
		}
		else
		{
			sum = sum * 10 + n % 10;
			n /= 10;
		}
	}
	if (ret == sum)
		return 0;
	return sum;

}
int Judge2(int m)
{
	int i = 0;
	//int k = 2;
	int k = (int)sqrt((double)m);
	for (i = 2; i <=k; i++)
	{
		if (m%i == 0)
			break;
		
		/*if (m%i == 0)
			break;*/
	}
	if (k < i)
		return m;
	return 0;
}
int Judge1(int k)
{
	int i = 0, flag1 = 0, flag2 = 0, flag3 = 0;
	int reverse = 0;
	int count = 0;
	for (i = 10; i < 1000000; i++)
	{
		flag1 = Judge2(i);
		flag2 = Judge3(i);
		if (flag1 == 0 || flag2 == 0)
			continue;
		reverse = Judge3(i);
		flag3 = Judge2(reverse);
		if (flag3 == 0)
			continue;
		count++;
		if (count == k)
			return i;
	}
}
int main()
{
	int k = 0;
	int ret = 0;
	scanf("%d", &k);
	if (k<1 || k>10000)
		return 0;
	ret = Judge1(k);
	printf("%d\n", ret);

}