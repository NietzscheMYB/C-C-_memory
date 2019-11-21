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


void InsectSortWithGap(int arr[], int size,int gap)
{
	int k = 0;
	int j = 0;
	for (int i = 1; i<size; i++)
	{
		int temp = arr[i];

		for (j = i - gap; j >= 0 && temp<arr[j]; j-=gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = temp;
	}
}



void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//工程做法没有理论
		InsectSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}

int main()
{
   int arr1[] = { 3, 4, 7, 5, 2, 1 };
	   ShellSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	   Print(arr1, sizeof(arr1) / sizeof(arr1[0]));
	
	   int arr2[] = { 213, 341, 12, 3, 421, 112, 112, 112 };
	   ShellSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	   Print(arr2, sizeof(arr2) / sizeof(arr2[0]));
	
		   int arr3[] = { 21, 311, 45, 1, 6, 3, 6, 3 };
	   ShellSort(arr3, sizeof(arr3) / sizeof(arr3[0]));
	   Print(arr3, sizeof(arr3) / sizeof(arr3[0]));
	    return 0;

	return 0;
}