//���Ƕ��衰���ֵ�С˾��������˵���ڵ�˾�����к��Ĳ��У���Ҫ�������ܡ��������ǳ��أ���Ҫ�����ػ����ֵ����ر����ڵ�ǰ�ͼ����������ʱ��˾����������Ϊɢ��������ס���ۡ�ɳʯ������......
//����֪����������������Ϊw���ɹ�ѡ�����Ʒ������n��ÿ����Ʒ������Ϊgi, ��ֵΪpi����������װ�ص�����ֵ����n<10000, w<10000, 0<gi <= 100, 0 <= pi <= 100)
//�����ʽ
//�����һ��Ϊ�ɿո�ֿ�����������n w
//�ڶ��е���n + 1�У�ÿ���������������ɿո�ֿ����ֱ��ʾgi��pi
//�����ʽ
//����ֵ������һλС����
//-------------------- -

#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	double n, w;
	scanf("%lf%lf", &n, &w);
	double arr[1000][3] = {0};
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
		arr[i][j] = arr[i][j - 1] / arr[i][j - 2];
	}
//	Bubble_sort(arr[1000][3], n);

	int a = 0, b = 0;
		double c = 0;
	 i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n - i - 1; j++)
		{
			if (arr[j][2]>arr[j + 1][2])
			{
				a = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = a;


				b = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = b;

				c = arr[j][2];
				arr[j][2] = arr[j + 1][2];
				arr[j + 1][2] = c;
			}
		}
	}
	int k = n-1;
	double sum=0;
	double diff = 0;
	double weight = 0;
	while (weight < w)
	{
		if (arr[k][0]<(w-weight))
		{
			weight += arr[k][0];
			sum = sum + arr[k][1];
			k--;
			continue;
		}
		if (arr[k][0]>(w - weight))
		{
			diff = w - weight;
			weight += (w - weight);
			sum = sum + (diff)*arr[k][2];
			break;
		}
		if (weight >= w)
		{
			break;
		}

	}
	printf("%.1lf\n", sum);
	return 0;
}