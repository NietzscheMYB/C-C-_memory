//马虎的算式
//小明是个急性子，上小学的时候经常把老师写在黑板上的题目抄错了。
//有一次，老师出的题目是：36 x 495 = ?
//他却给抄成了：396 x 45 = ?
//但结果却很戏剧性，他的答案竟然是对的！！
//假设 a b c d e 代表1~9不同的5个数字（注意是各不相同的数字，且不含0）
//能满足形如： ab * cde = adb * ce 这样的算式一共有多少种呢？
//请你利用计算机的优势寻找所有的可能，并回答不同算式的种类数。
//满足乘法交换律的算式计为不同的种类，所以答案肯定是个偶数。



//不同数字


#include <stdio.h>
int main()
{
	int count = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int num1 = 0, num2 = 0;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= 9; b++)
		{
			if (a == b)
			{
				continue;
			}
			for (c = 1; c <= 9; c++)
			{
				if (a==c||b==c)
				{
					continue;
				}
				for (d = 1; d <= 9; d++)
				{
					if (a == d || b == d || c == d)
					{
						continue;
					}
					for (e = 1; e <= 9; e++)
					{
						if (a == e || b == e || c == e || d == e)
						{
							continue;
						}
						num1 = (a * 10 + b)*(c * 100 + d * 10 + e);
						num2 = (a * 100 + d * 10 + b)*(c * 10 + e);
						if (num1 == num2)
						{
							count++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", count);
}
