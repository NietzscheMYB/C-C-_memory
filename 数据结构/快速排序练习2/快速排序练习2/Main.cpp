#include<iostream>
#include<algorithm>
using namespace std;

void Print(int arr[], int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//hore法
int Partition_1(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	int key = arr[right];
	while (begin<end)
	{
		while (begin<end&&arr[begin] <= key)
		{
			begin++;
		}
		while (begin<end&&arr[end]>key)
		{
			end--;
		}
		swap(arr[end], arr[begin]);
	}
	swap(arr[begin], arr[right]);
	return begin;
}

//挖坑法
int  Partition_2(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	int privot = arr[right];
	while (begin<end)
	{
		while (begin<end&&arr[begin] <= privot)
		{
			begin++;
		}
		//填右坑
		arr[end] = arr[begin];
		while (begin<end&&arr[end]>privot)
		{
			end--;
		}
		//填左坑
		arr[begin] = arr[end];
	}
	arr[begin] = privot;
	return begin;
}

//前后指针法
int Partition_3(int arr[], int left, int right)
{
	//i=d=left
	//i=d=left
	//i=d=left!!!!!

	int i = left, d = left;
	int key = arr[right];
	for (i = left; i<right; i++)
	{
		if (arr[i] <= key)
		{
			swap(arr[i], arr[d]);
			d++;
		}
	}
	swap(arr[right], arr[d]);
	return d;
}


void _QuickSort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (left>right)
	{
		return;
	}
	int index = Partition_3(arr, left, right);
	_QuickSort(arr, left, index - 1);
	_QuickSort(arr, index + 1, right);
}

void QuickSort(int arr[], int size)
{
	_QuickSort(arr, 0, size - 1);
}
int main()
{
	int arr1[] = { 13, 32, 41, 5, 2, 6, 6 };
	int arr2[] = { 2, 4, 1, 5, 6, 2, 7, 9, 34, 234, 2 };

	int arr3[] = { 1, 3, 4, 1, 42, 41, 5, 2, 6, 6 };

	QuickSort(arr1, sizeof(arr1) / sizeof(arr1[0]));

	QuickSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	QuickSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));
	Print(arr2, sizeof(arr2) / sizeof(arr2[0]));
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]));


	return 0;
}