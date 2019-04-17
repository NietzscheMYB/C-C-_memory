#include <stdio.h>
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
//ѡ������
//ʱ�临�Ӷ�
//ƽ��/���/�����  O��n2��
//�ռ临�Ӷ�o��1��
//���ȶ�
void SelectSort(int arr[], int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		int key = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[key]>arr[j])
			{
				key = j;
			}
		}
		Swap(arr + key , arr+i );
	}
}

void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0;
	//���������ʵ�ּ��εĹ���
	for (i = 0; i < size; i++)
	{
		int key = arr[i];

		//arr[key]>arr[j-1]//��ǰԪ�ظ��ϸ��������һ���Ƚ�
		//>=����ѭ��
		//С�ڽ��а��� Ȼ�󽻻�
		//j�ķ�Χ��i-1 ��0
		for (j = i - gap; j >= 0 && key < arr[j]; j -= gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}
//ϣ������
//ʱ�临�Ӷ����o��n��
//ƽ��o(n1.2~o1.3)
//�o��n2��
void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//��������
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}


int main()
{
	int arr[] = { 45, 32, 43, 2, 4 };
	//SelectSort(arr, 5);
	ShellSort(arr, 5);
	PrintArray(arr, 5);
	return 0;
}