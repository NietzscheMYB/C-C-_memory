#include<iostream>
#include<cstdio>
using namespace std;


void Swap(int *left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void Print(int arr[], int size)
{
	for (int i = 0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�����򽨴��(����)������
//ʱ�临�Ӷȣ�
//�|���|ƽ�� O(n*log(n))
//�ռ临�Ӷ�o(1)
//���ȶ�  (���µ��������У��޷���֤�����ǰ���ϵ)



//���µ���
void AdjustDown(int arr[], int size, int root)
{
	int i = 2 * root + 1;
	int j = 2 * root + 2;
	if (i >= size)
	{
		return;
	}
	int m = i;
	if (j<size&&arr[j]>arr[i])
	{
		m = j;
	}
	if (arr[m]>arr[root])
	{
		Swap(arr + m, arr + root);
		AdjustDown(arr, size, m);
	}
}

//����
//O(n) or  O(n*logN)
//
void CreateHeap(int arr[], int size)
{
	//�����һ���ڵ�ķ�֧�ڵ��Ͽ�ʼ���ѣ���
	//���һ����֧�ڵ��Ͻ��ѣ�����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}
}

//������
void HeapSort(int arr[], int size)
{
	CreateHeap(arr, size);
	for (int i = 0; i<size; i++)
	{
		Swap(arr, arr + size - 1 - i);
		AdjustDown(arr, size - 1 - i, 0);
	}
}


int main()
{
	int arr1[] = { 13, 32, 41, 5, 2, 6, 6 };
	int arr2[] = { 2, 4, 1, 5, 6, 2, 7, 9, 34, 234, 2 };

	int arr3[] = { 1, 3, 4, 1, 42, 41, 5, 2, 6, 6 };

	HeapSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	HeapSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
	HeapSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

	Print(arr1, sizeof(arr1) / sizeof(arr1[0]));
	Print(arr2, sizeof(arr2) / sizeof(arr2[0]));
	Print(arr3, sizeof(arr3) / sizeof(arr3[0]));


	return 0;
}

