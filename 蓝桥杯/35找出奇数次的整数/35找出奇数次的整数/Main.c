//只有一个整数出现奇数次
//一个无序数组里有若干个正整数，范围从1到100，其中98个整数都出现了偶数次，只有两个整数出现了奇数次（比如1,1,2,2,3,4,5,5），如何找到这个出现奇数次的整数？
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr[5] = { 0 };
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num = 0;
	for (i = 0; i < 5; i++)
	{
		 num=num^arr[i];
	}
	//num = arr[i];
	printf("%d\n", num);

}