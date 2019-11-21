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

void InsectSort(int arr[], int size)
{
	int k = 0;
	int j = 0;
	for (int i = 1; i<size; i++)
	{
		int temp = arr[i];
	
		for (j = i - 1; j >= 0 && temp<arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	int arr1[] = { 3, 4, 7, 5, 2, 1 };
	InsectSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));

	int arr2[] = { 213, 341, 12, 3, 421, 112, 112, 112 };
	InsectSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	Print(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}