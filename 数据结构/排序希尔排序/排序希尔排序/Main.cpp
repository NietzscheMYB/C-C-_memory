#include <stdio.h>
//��������
//ʱ�临�ƶ��o��n2�� �Ѿ����� ������
//���o(n)   ˳��
void InsertSort(int arr[], int size)
{
	//���ѭ��ʵ�ּ��ι���
	//һ��ȡһ�����嵽ǰ��
	int i = 0, j = 0;
	for ( i = 0; i < size; i++)
	{
		int key = arr[i];
		//��key��0~i-1�Ա�
		//�ִ�i-1�� ��arr[i-1]��/=�Ļ�
		//����
		//��arr[i-1]С�Ļ�
		//���Ʋ�����

		//����ѭ��ʵ�ְ���
		for (j = i - 1; j >= 0&&arr[j]>key; j--)
		{
			arr[j + 1] = arr[j];
		}
		//j+1ΪҪ�����λ��
		arr[j + 1] = key;
	}
}

//ϣ������
//�ǲ������� ���Ż��汾
//������֮ǰ������������������
//�������
//ʱ�临�Ӷ�
//��� o��n��
//ƽ��o��n1.2��~o��n1.3��
//���o��n2��
//�ռ临�Ӷ�
//o��1��
//���ȶ� ��һ�����飬���ѱ�֤��ͬ���ֵ�һ�����

//��������gap�Ĳ�������

void InsertSortWithGap(int arr[], int size, int gap)
{
	int i = 0, j = 0,key=0;
	//�����ʵ�ּ���
	for (i = 0; i < size; i++)
	{
		key = arr[i];
		for (j = i - gap; j >= 0 && arr[j]>key; j-=gap)
		{
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int arr[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;//��������û�о�������
		InsertSortWithGap(arr, size, gap);
		if (gap == 1)
		{
			return;
		}
	}
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int arr[5] = { 55, 12, 30, 39, 3 };
	ShellSort(arr, 5);
	PrintArray(arr, 5);
	return 0;
}