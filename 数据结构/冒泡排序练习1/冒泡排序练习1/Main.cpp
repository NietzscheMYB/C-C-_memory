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

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i<size; i++)
	{
		for (int j = 1; j<size - i; j++)
		{
			if (arr[j - 1]>arr[j])
			{
				arr[j - 1] = arr[j - 1] + arr[j];
				arr[j] = arr[j - 1] - arr[j];
				arr[j - 1] = arr[j - 1] - arr[j];

			}
		}
	}
}



int main()
{
	int arr1[] = { 13, 32, 41, 5, 2, 6, 6 };
	int arr2[] = { 2, 4, 1, 5, 6, 2, 7, 9, 34, 234, 2 };

	int arr3[] = { 1, 3, 4, 1, 42, 41, 5, 2, 6, 6 };

	BubbleSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	BubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	BubbleSort(arr3, sizeof(arr3) / sizeof(arr3[0]));
	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));
	Print(arr2, sizeof(arr2) / sizeof(arr2[0]));
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]));
	return 0;
}