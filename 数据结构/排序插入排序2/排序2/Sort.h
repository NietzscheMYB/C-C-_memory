#include <stdio.h>

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//��������
//ʱ�临�Ӷ�
//���O(n)   �Ѿ�����
//ƽ��O(n2)
//�0(n2)  �Ѿ�����������
//�ռ临�Ӷ�O(1)
//�ȶ�
void InsertSort(int arr[], int size)
{
	//��ߵ�ѭ��ʵ�ּ��εĹ���
	//һ��ȥһ���������뵽ǰ������������
	for (int i=0; i < size; i++)
	{
		int key = arr[i];
		//�ڲ���ѭ��ʵ�ֵ��ǲ���Ĺ���
		//j��[i-1,0]
		//���arr[j]>key,�����
		//���arr[j]==key ����ѭ����֤�ȶ���
		//arr[j]<key,����ѭ��
		int j;
		for (j = i - 1; j >= 0 && arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
void test()
{
	int arr[5] = { 12, 5, 58, 52, 8 };
	PrintArray(arr, 5);
	InsertSort(arr, 5);
	PrintArray(arr, 5);

}