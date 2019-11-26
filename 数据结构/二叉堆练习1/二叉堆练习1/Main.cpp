#include<iostream>
#include<cstdio>
using namespace std;

void AdjustDown(int arr[], int size, int root)
{
	//判断root是否是叶子节点
	//因为堆是完全二叉树，所以没有左孩子一定没有右孩子
	//又因为堆是顺序存储的
	//所以，找到左孩子的下标，如果左孩子的下标越界了，则没有左孩子
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)
	{
		//root此时是叶子节点
		return;
	}
	//这里一定有左孩子，判断是否右右孩子
	//找出左孩子和右孩子中最小的
	int max = left;
	if (right<size&&arr[right]>arr[left])
	{
		//右孩子存在，且右孩子的值小于左孩子
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

//建堆
//精准看成是O(n)
//粗略看出是O(n*logn)
void CreateHeap(int arr[], int size)
{
	//从最后一个分支节点上开始建堆
	//从最后一个分支节点上开始建堆
	//从最后一个分支节点上开始建堆

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


//升序建大堆
//堆排序
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


//向上调整
//arr数组
//size数组长度
//child要向上调整的结点下标

//结束条件
//1.比不过parent
//2.已经登基了

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