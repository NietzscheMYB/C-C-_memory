#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>
int Reverse(int m)
{
	int sum = 0, flag1= 0,flag2=10;
	while (m)
	{
		if (flag1 == 0)
		{
			sum = m % 10 + sum*flag2;
			flag1 = 1;
			m = m / 10;
			continue;
		}
		sum = m % 10 + sum*flag2;
	//	/flag2 = flag2 * 10;
		m = m / 10;
	}
	return sum;
}
int Symmetry_num(int m,int len)
{
	char down[20] = { '0' }, up[20] = {'0'};
	int i = 0,num1=0,num2=0;
	int min1 = 0, min2 = 0;
	int key1 = m, key2 = m;
	for (i = 0; i < len; i++)
	{
		if (i == 0)
		{
			down[i] = '1';
			continue;
		}
		down[i] = '0';
	}
	for (i = 0; i < len; i++)
	{
		up[i] = '9';
	}
	int down1 = Change(down), up1 = Change(up);
	min1 = m - Reverse(down1);
	min2 = Reverse(up1) - m;
//	int num11 = 0, num22 = 0;
	int num11 = 0, num22 = 0;
	for (i = down1; i <=m; i++)
	{
		num1 = Reverse(i);
		if (num1 != i)
			continue;
		if (num1 == m)
			break;
		if (min1 > m - num1)
		{
			min1 = m - num1;
			num11 = num1;
		}
	}
	for (i = up1; i >= m; i--)
	{
		num2 = Reverse(i);
		if (num2 != i)
			continue;
		if (num2 == m)
			break;
		if (min2 > num2 - m)
		{
			min2 = num2 - m;
			num22 = num2;
		}
	}
	if (min1 < min2)
		return num11;
	return num22;

	/*while (key1--)
	{
		if (key1 > down1)
		{
			num1 = Reverse(key1);
			if (num1 != key1)
				continue;
			if (min1 > m - num1)
			{
				min1 = m - num1;
				num11 = num1;
				break;
			}
		}
	}
	while (key2++)
	{
		if (key2 < up1)
		{
			num2 = Reverse(key2);
			if (num2 != key2)
				continue;
			if (min2>num2 - m)
			{
				min2 = num2 - m;
				num22 = num2;
				break;
			}
		}
	}
	if (min1 <= min2)
		return num11;
	return 22;*/
}
int Change(char arr[])
{
	int sum = 0;
	int i = 0;
	int flag = 1;
	for (i = strlen(arr) - 1; i >= 0;i--)
	{
		sum = sum + (arr[i] - '0')*flag;
		flag = flag * 10;
	}
	return sum;
}
int main()
{
	char arr[20] = { '0' };
	scanf("%s", &arr);
	int len = strlen(arr);
	if (len > 18)
		return 0;
	int num = Change(arr);
	int x=Symmetry_num(num,len);
	printf("%d\n", x);
}