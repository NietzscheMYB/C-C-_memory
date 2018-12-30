//#include <stdio.h>
#pragma warning(disable:4996)
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i, j;
//	int num = 0;
//	int sum = 0;
//	for (i = 10000; i < 1000000; i++)
//	{
//		//num = i;
//		while (i>0)
//		{
//			sum += i % 10;
//			num = num / 10;
//		}
//		if (sum == i)
//		{
//			sum = 0;
//			printf("%d\n", i);
//		}
//			
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int i, n, num;
	int sum, reversal;
	scanf("%d", &n);
	{
		for (i = 10000; i<1000000; i++)
		{
			num = i;                                    //遍历每个五位与六位十进制数 
			sum = 0, reversal = 0;                         //每位数字之和与其回文数均赋初值0 
			while (num>0)
			{
				reversal = reversal * 10 + num % 10;	      //求解回文数 
				sum += (num % 10);                        //数位分离，从低位开始累加 
				num /= 10;
			}
			if (sum == n && reversal == i)                 //一个数的各位数字之和等于n且是回文数，则输出 
				printf("%d\n", i);
		}
	}
	return 0;
}