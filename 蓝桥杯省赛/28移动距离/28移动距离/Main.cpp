//星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1, 2, 3...当排满一行时，
//从下一行相邻的楼往反方向排号。 比如：当小区排号宽度为6时，开始情形如下：
//1  2  3  4  5  6 12 11 10 9  8  7 13 14 15 .....
//我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）
//输入为3个整数w m n，空格分开，
//都在1到10000范围内 w为排号宽度，m, n为待计算的楼号。 
//要求输出一个整数，表示m n 两楼间最短移动距离。
//
//例如： 用户输入： 6 8 2
//
//则，程序应该输出： 4
//
//再例如： 用户输入： 4 7 20
//
//则，程序应该输出： 5
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int w, m, n;
	//scanf("%d%d%d", &w, &m, &n);
	cin >> w >> m >> n;
	int rm = 0, rn = 0, cm = 0, cn = 0;
	rm = (m - 1) / w + 1;
	rn = (n - 1) / w + 1;
	int x = 0;
	if (rm % 2 == 0)
	{
		x = rm*w;
		cm = x - m + 1;
	}
	else{
		x = rm*w;
		cm = m-(x-w+1)+1;
	}
	if (rn % 2 == 0)
	{
		x = rn*w;
		cn = x - n + 1;
	}
	else{
		x = rn*w;
		cn = n - (x - w + 1) + 1;
	}
	int step = abs(cm-cn) + abs(rm-rn);
	cout << step << endl;
	return 0;
	
}
