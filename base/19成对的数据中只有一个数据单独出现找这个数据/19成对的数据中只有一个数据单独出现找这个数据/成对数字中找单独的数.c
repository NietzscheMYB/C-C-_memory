/***�κ�����0���Ľ�������������������
    ������ȵ������Ľ����0
	��������ֱ��������� ���ÿ���˳�� ������ͬΪ0 ��ͬΪ������
	�����������ָ����assert.h
	sizeof()�����Ƿ���һ���������������ռ�ڴ��ֽ�������������

********/
#include <stdio.h>
#include <assert.h>
int Findsignal(int arr[], int num)
{
	assert(arr);
	assert(num > 0);
	int i = arr[0];
	int j = 1;
	while (j < num)
	{
		i ^= arr[j];
			j++;

	}
	return i;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 10, 1, 2, 3, 4, 5, 6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int data = Findsignal(arr, num);
	printf("data = %d\n", data);
	return 0;
}
