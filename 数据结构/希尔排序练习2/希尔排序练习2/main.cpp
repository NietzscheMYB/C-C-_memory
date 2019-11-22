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

void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0, key = 0;
	for (i = 0; i<size; i++)
	{
		key = arr[i];
		for (j = i - gap; j >= 0 && key<arr[j]; j -= gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

//ϣ������
//��С��������
//���on����������

void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//����������û����ȷҪ��
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}

int main()
{
	int arr1[] = { 13, 32, 41, 5, 2, 6, 6 };

	int arr2[] = { 2, 4, 1, 5, 6, 2, 7, 9, 34, 234, 2 };

	int arr3[] = { 1, 3, 4, 1, 42, 41, 5, 2, 6, 6 };
	ShellSort(arr1, sizeof(arr1) / sizeof(arr1[0]));

	ShellSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	ShellSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));

	Print(arr2, sizeof(arr2) / sizeof(arr2[0]));
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]));

	return 0;
}