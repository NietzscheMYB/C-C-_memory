/*
一个数组中有两个数出现了一次 其余出现了两次！！！

这个数组所有的值进行 异或 ^  的结果为这两个数的异或！！！

设这个结果为  ret

让ret左移  找到第一个为1的数（一个简单的标记）！  记录此时位置

然后 让数组的所有元素 移动到这个位置！！ 那两个数与1进行 & 运算  结果为1 确定一个数  】
结果为0确定另一个数！



！！！必须数组先排序！！！！


*/



#include <stdio.h>
void Find_arr(int arr[], int len)
{
	int i;
	int sz = len;
	int ret =0;
	int post=0;
	int x=0, y=0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (1 == (ret >> i) & 1)
			post = i;
	}
	for (i = 0; i < sz; i++)
	{
		if (1 == ((arr[i] >> post) & 1))
		{
			x= arr[i];
		}
		else
		{
			y= arr[i];
		}
	}
	printf("%d %d\n", x, y);
}
int main()
{
	int arr[] = { 1,1,2,2,3,3,4,4,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_arr(arr, len);
	return 0;
}