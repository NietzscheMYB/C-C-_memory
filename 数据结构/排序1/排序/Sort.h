#pragma warning(disable:4996)
#include <stdio.h>


//��ӡ
void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//��������
//	ʱ�临�Ӷ� 
//��� o(n)  �Ѿ�˳��
//ƽ�� o(n^2)
//� o(n^2) �Ѿ����� ����
void InsertSort(int arr[], int size)
{
	//��ߵ�ѭ��ʵ�ּ��ι���
	//һ��ѭ��ȡһ����������ǰ�������������
	int i = 0, j = 0,key=0;
	for (i = 0; i < size; i++)
	{
		key = arr[i];
		//�ڲ�ѭ��ʵ�ֵ��ǲ���Ĺ���
		//j��[i-1,0]
		//���arr[j]>key �����
		//���arr[j]==key ����ѭ��
		//���arr[j]<key ����ѭ��
		for (j = i-1; j>=0&&arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		//j+1 �ǲ����λ��
		arr[j+1] = key;
	}
}

void Test()
{
	int arr[] = { 51, 234, 1, 34, 5, 25, 6 };
	int size = (sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, size);
	PrintArr(arr, size);
}