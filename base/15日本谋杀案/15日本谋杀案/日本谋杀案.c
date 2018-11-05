//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//n个人说真话 if表达式相加为n！！！


#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					if (((a == 0) + (c == 1) + (d == 1) + (d == 0) )== 3)
					{
				/*		if (a == 1)
							printf("a是凶手\n");
						if (b == 1)
							printf("b是凶手\n");
						if (c == 1)
							printf("c是凶手\n");
						if (d == 1)
							printf("d是凶手\n");*/
						//printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
						if ((a + b + c + d) == 1)
						{
							printf("a=%d,b=%d,c=%d,d=%d\n1为凶手\n", a, b, c, d);
						}
						
					}
				}
			}
		}
	}
}


//#include <stdio.h>
//
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)//巧妙地利用ASCII 从A-D进行循环和比较
//	{
//		//下面分别对应每个人都供词  不是A 是C     是D    不是D
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)  //这里等于3表示 有三个人说了真话
//		{
//			printf("%c是凶手\n", killer);
//			break;
//		}
//	}
//	return 0;
//}

