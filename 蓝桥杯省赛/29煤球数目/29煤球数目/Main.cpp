//煤球数目
//
//有一堆煤球，堆成三角棱锥形。具体：
//第一层放1个，
//第二层3个（排列成三角形），
//第三层6个（排列成三角形），
//第四层10个（排列成三角形），
//....
//如果一共有100层，共有多少个煤球？
//
//请填表示煤球总数目的数字。

#include <iostream>
using namespace std;
int main()
{
	int arr[100] = { 0 };
	arr[0] = 1, arr[1] = 3, arr[2] = 6;
	arr[3] = 10;
	int sum = 0;
	for (int i = 4,j=5; i < 100; i++,j++)
	{
		arr[i] =arr[i-1]+j;
	}
	for (int i = 0; i < 100; i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);

}