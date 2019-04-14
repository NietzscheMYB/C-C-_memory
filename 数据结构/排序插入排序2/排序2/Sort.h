#include <stdio.h>

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//插入排序
//时间复杂度
//最好O(n)   已经有序
//平均O(n2)
//最坏0(n2)  已经有序是逆序
//空间复杂度O(1)
//稳定
void InsertSort(int arr[], int size)
{
	//外边的循环实现减治的过程
	//一次去一个数，插入到前面的有序控制内
	for (int i=0; i < size; i++)
	{
		int key = arr[i];
		//内部的循环实现的是插入的过程
		//j从[i-1,0]
		//如果arr[j]>key,往后搬
		//如果arr[j]==key 跳出循环保证稳定型
		//arr[j]<key,跳出循环
		int j;
		for (j = i - 1; j >= 0 && arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
void test()
{
	int arr[5] = { 12, 5, 58, 52, 8 };
	PrintArray(arr, 5);
	InsertSort(arr, 5);
	PrintArray(arr, 5);

}