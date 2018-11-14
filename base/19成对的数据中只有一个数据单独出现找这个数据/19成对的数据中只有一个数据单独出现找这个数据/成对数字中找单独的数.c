/***任何数和0异或的结果是这个数本身！！！！
    两个相等的数异或的结果是0
	在数组中直接两两异或 不用考虑顺序 两两相同为0 不同为它本身
	调用数组或者指针用assert.h
	sizeof()作用是返回一个对象或者类型所占内存字节数！！！！！

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
