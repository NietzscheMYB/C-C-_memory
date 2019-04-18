#include <stdio.h>
void Print(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void BubbleSort(int arr[], int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		int key = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] >arr[j+1])
			{
				int tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
				key = 1;
			}
		}
		if (key == 0)
		{
			return;
		}
	}
}
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

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
				int tem = j;
				j = key;
				key = tem;
			}
		}
		Swap(arr + i, arr + key);
	}
}

void InsertSort(int arr[], int size)
{
	int i = 0, j = 0;
	//最外层循环实现减治
	for (i = 0; i < size; i++)
	{
		int key = arr[i];
		//key>=arr[i-1]时跳出循环
		//key<arr[i-1]时搬移然后把key插入
		for (j = i - 1; j >= 0 && key < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		int key = arr[i];
		for (j = i - gap; j >= 0 && key < arr[j]; j -= gap)
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
		gap = (gap / 3) + 1;
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}
int main()
{
	int arr[5] = { 48, 39, 23, 52, 53 };
	ShellSort(arr, 5);
	Print(arr, 5);
	return 0;
}