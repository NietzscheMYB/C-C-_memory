/*
һ����������������������һ�� ������������Σ�����

����������е�ֵ���� ��� ^  �Ľ��Ϊ������������򣡣���

��������Ϊ  ret

��ret����  �ҵ���һ��Ϊ1������һ���򵥵ı�ǣ���  ��¼��ʱλ��

Ȼ�� �����������Ԫ�� �ƶ������λ�ã��� ����������1���� & ����  ���Ϊ1 ȷ��һ����  ��
���Ϊ0ȷ����һ������



�������������������򣡣�����


*/



#include <stdio.h>
void Find_arr(int arr[], int len)
{
	int i;
	int sz = len;
	int ret =0;
	int post=0;
	int x=0, y=0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (1 == (ret >> i) & 1)
			post = i;
	}
	for (i = 0; i < sz; i++)
	{
		if (1 == ((arr[i] >> post) & 1))
		{
			x= arr[i];
		}
		else
		{
			y= arr[i];
		}
	}
	printf("%d %d\n", x, y);
}
int main()
{
	int arr[] = { 1,1,2,2,3,3,4,4,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_arr(arr, len);
	return 0;
}