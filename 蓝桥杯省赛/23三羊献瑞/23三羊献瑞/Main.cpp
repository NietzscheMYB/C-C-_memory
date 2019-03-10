//三羊献瑞 观察下面的加法算式：
//  祥 瑞 生 辉 
//+ 三 羊 献 瑞
//------------------
//  三 羊 生 瑞 气
//(如果有对齐问题，可以参看【图1.jpg】)
//其中，相同的汉字代表相同的数字，不同的汉字代表不同的数字。 
//请你填写“三羊献瑞”所代表的4位数字（答案唯一），
//不要填写任何多余内容。
#include <iostream>
using namespace std;
int main()
{
	int i=0, j=0, k=0, l=0;
	int m=0, n=0, a=0, b=0, c=0;
	for (i = 0; i <= 9; i++)
	{
		if (i == j)
		{
			continue;
		}
		for (j = 0; j <= 9; j++)
		{
			if (j == k)
			{
				continue;
			}
			for (k = 0; k <= 9; k++)
			{
				if (k == l)
				{
					continue;
				}
				for (l = 0; l <= 9; l++)
				{
					if (l == m)
					{
						continue;
					}
					for (m = 0; m <= 9; m++)
					{
						if (m == n)
						{
							continue;
						}
						for (n = 0; n <= 9; n++)
						{
							if (n == a)
							{
								continue;
							}
							for (a = 0; a <= 9; a++)
							{
								if (a == b)
								{
									continue;
								}
								for (b = 0; b <= 9; b++)
								{
									int num1 = i * 1000 + j * 100 + k * 10 + l;
									int num2 = m * 1000 + n * 100 + a * 10 + j;
									int num3 = m * 10000 + n * 1000 + k * 100 + j * 10 + b;
									if ( i == j || i == k || i == l || i == m || i == n || i == a || i == b)
									{
										continue;
									}
									if (j == k || j == l || j == m|| j == n || j ==a || j == b)
									{
										continue;
									}
									if (k == l|| k == m || k ==n || k==a||k == b )
									{
										continue;
									}
									if (l == m || l == n|| l== a||l == b)
									{
										continue;
									}
									if (m == n ||m == a ||m ==b)
									{
										continue;
									}
									if ((num1 + num2) == num3)
									{
										if (num1>=1000&&num2>=1000&&num3>=10000)
										printf("%d %d %d\n", num1, num2, num3);
									}
								}
							}
						}
					}
				}

			}
		}
	}
	return 0;
}

