//这是儿歌“快乐的小司机”。话说现在当司机光有红心不行，还要多拉快跑。多拉不是超载，是要让所载货物价值最大，特别是在当前油价日新月异的时候。司机所拉货物为散货，如大米、面粉、沙石、泥土......
//现在知道了汽车核载重量为w，可供选择的物品的数量n。每个物品的重量为gi, 价值为pi。求汽车可装载的最大价值。（n<10000, w<10000, 0<gi <= 100, 0 <= pi <= 100)
//输入格式
//输入第一行为由空格分开的两个整数n w
//第二行到第n + 1行，每行有两个整数，由空格分开，分别表示gi和pi
//输出格式
//最大价值（保留一位小数）
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