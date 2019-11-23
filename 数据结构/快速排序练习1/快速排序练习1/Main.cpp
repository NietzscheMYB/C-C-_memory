#include<iostream>
#include<cstdio>
using namespace std;

void Print(int arr[], int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

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
		while (begin<end&&arr[end] >= key)
		{
			end--;
		}
		Swap(arr + begin, arr + end);
	}
	Swap(arr + begin, arr + right);
	return begin;
}


int Partition_2(int arr[], int left, int right)
{
	int pivot = arr[right];
	int begin = left;
	int end = right;
	int div = right;
	while (begin<end)
	{
		while (begin<end&&arr[begin] <= pivot)
		{
			begin++;
		}
		//���ҿ�
		arr[end] = arr[begin];
		while (begin<end&&arr[end] >= pivot)
		{
			end--;
		}
		//�����
		arr[begin] = arr[end];

	}
	arr[begin] = pivot;
	return begin;
}


int Partition_3(int arr[], int left, int right)
{
	int div = left;
	for (int i = left; i<right; i++)
	{
		//���arr[i]<arr[right]С�ڻ�׼ֵ������i����div���н�����
		//Ȼ�����++��arr[i]>arr[right]ʱ��ֻi++
		if (arr[i]<arr[right])
		{
			Swap(arr + i, arr + div);
			div++;
		}
	}
	//��ѭ��ʱ��div��ָ���λ�ÿ϶��ǵ�һ�����ڻ�׼ֵ����
	//�򽻻�����
	Swap(arr + div, arr + right);
	return div;
}


void _QuickSort(int arr[], int left, int right)
{
	//��ֹ����size==0||size==1
	if (right == left)
	{
		return;
	}
	if (left>right)
	{
		return;
	}
	int index = 0;
	//index=Partition_1(arr,left,right);
	// index=Partition_2(arr,left,right);
	index = Partition_3(arr, left, right);
	_QuickSort(arr, 0, index - 1);
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