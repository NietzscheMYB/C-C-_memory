#pragma warning(disable:4996)
#include <stdio.h>


//打印
void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//插入排序
//	时间复杂度 
//最好 o(n)  已经顺序
//平均 o(n^2)
//最坏 o(n^2) 已经有序 逆序
void InsertSort(int arr[], int size)
{
	//外边的循环实现减治过程
	//一次循环取一个数，插入前面的有序区间内
	int i = 0, j = 0,key=0;
	for (i = 0; i < size; i++)
	{
		key = arr[i];
		//内部循环实现的是插入的过程
		//j从[i-1,0]
		//如果arr[j]>key 往后搬
		//如果arr[j]==key 跳出循环
		//如果arr[j]<key 跳出循环
		for (j = i-1; j>=0&&arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		//j+1 是插入的位置
		arr[j+1] = key;
	}
}

void Test()
{
	int arr[] = { 51, 234, 1, 34, 5, 25, 6 };
	int size = (sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, size);
	PrintArr(arr, size);
}