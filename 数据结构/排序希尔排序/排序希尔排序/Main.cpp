#include <stdio.h>
//插入排序
//时间复制度最坏o（n2） 已经有序 是逆序
//最好o(n)   顺序
void InsertSort(int arr[], int size)
{
	//外边循环实现减治过程
	//一次取一个数插到前面
	int i = 0, j = 0;
	for ( i = 0; i < size; i++)
	{
		int key = arr[i];
		//将key与0~i-1对比
		//现从i-1比 比arr[i-1]大/=的话
		//跳出
		//比arr[i-1]小的话
		//搬移并插入

		//下面循环实现搬移
		for (j = i - 1; j >= 0&&arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		//j+1为要插入的位置
		arr[j + 1] = key;
	}
}

//希尔排序
//是插入排序 的优化版本
//在排序之前，尽可能让数据有序
//分组插排
//时间复杂度
//最好 o（n）
//平均o（n1.2）~o（n1.3）
//最差o（n2）
//空间复杂度
//o（1）
//不稳定 （一旦分组，很难保证相同数分到一个组里）

//可以设置gap的插入排序

void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0,key=0;
	//最外层实现减治
	for (i = 0; i < size; i++)
	{
		key = arr[i];
		for (j = i - gap; j >= 0 && arr[j]>key; j-=gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//工程做法没有具体理论
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int arr[5] = { 55, 12, 30, 39, 3 };
	ShellSort(arr, 5);
	PrintArray(arr, 5);
	return 0;
}