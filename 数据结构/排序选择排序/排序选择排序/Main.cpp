#include <stdio.h>
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
//选择排序
//时间复杂度
//平均/最好/最坏都是  O（n2）
//空间复杂度o（1）
//不稳定
void SelectSort(int arr[], int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		int key = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[key]>arr[j])
			{
				key = j;
			}
		}
		Swap(arr + key , arr+i );
	}
}

void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0;
	//最外面过程实现减治的过程
	for (i = 0; i < size; i++)
	{
		int key = arr[i];

		//arr[key]>arr[j-1]//当前元素跟上个过程最后一个比较
		//>=跳出循环
		//小于进行搬移 然后交换
		//j的范围是i-1 到0
		for (j = i - gap; j >= 0 && key < arr[j]; j -= gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}
//希尔排序
//时间复杂度最好o（n）
//平均o(n1.2~o1.3)
//最坏o（n2）
void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//工程做法
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}


int main()
{
	int arr[] = { 45, 32, 43, 2, 4 };
	//SelectSort(arr, 5);
	ShellSort(arr, 5);
	PrintArray(arr, 5);
	return 0;
}