#include<iostream>
#include<cstdio>
using namespace std;

void AdjustDown(int arr[], int size, int root)
{
	//�ж�root�Ƿ���Ҷ�ӽڵ�
	//��Ϊ������ȫ������������û������һ��û���Һ���
	//����Ϊ����˳��洢��
	//���ԣ��ҵ����ӵ��±꣬������ӵ��±�Խ���ˣ���û������
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)
	{
		//root��ʱ��Ҷ�ӽڵ�
		return;
	}
	//����һ�������ӣ��ж��Ƿ����Һ���
	//�ҳ����Ӻ��Һ�������С��
	int max = left;
	if (right<size&&arr[right]>arr[left])
	{
		//�Һ��Ӵ��ڣ����Һ��ӵ�ֵС������
		max = right;
	}
	if (arr[root] < arr[max])
	{
		int t = arr[root];
		arr[root] = arr[max];
		arr[max] = t;
		AdjustDown(arr, size, max);
	}
}

//����
//��׼������O(n)
//���Կ�����O(n*logn)
void CreateHeap(int arr[], int size)
{
	//�����һ����֧�ڵ��Ͽ�ʼ����
	//�����һ����֧�ڵ��Ͽ�ʼ����
	//�����һ����֧�ڵ��Ͽ�ʼ����

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}
}

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


//���򽨴��
//������
void HeapSortBig(int arr[], int size)
{
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++)
	{
		int t = arr[size - 1 - i];
		arr[size - 1 - i] = arr[0];
		arr[0] = t;
		AdjustDown(arr, size - i-1, 0);
	}
}


//���ϵ���
//arr����
//size���鳤��
//childҪ���ϵ����Ľ���±�

//��������
//1.�Ȳ���parent
//2.�Ѿ��ǻ���

void AdjustUp(int arr[], int size, int child)
{
	while (child != 0)
	{
		int parent = (child - 1) / 2;
		if (arr[parent] >= arr[child])
		{
			return;
		}
		int t = arr[parent];
		arr[parent] = arr[child];
		arr[child] = t;
		child = parent;
	}
}




void HeapSortSmall(int arr[], int size)
{
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++)
	{
		swap(arr[0], arr[size - i - 1]);
		AdjustUp(arr, size - i - 1, size-i-1);
	}
}

void TestHeapSort() {
	int array[] = { 39, 129, 12, 38, 27, 9, 33, 2, 14 };
	int size = sizeof array / sizeof(int);

	HeapSortSmall(array, size);

	PrintArray(array, size);
}


int main()
{
	TestHeapSort();
	return 0;
}