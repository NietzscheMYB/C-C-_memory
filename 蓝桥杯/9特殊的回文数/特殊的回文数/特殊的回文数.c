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
			num = i;                                    //����ÿ����λ����λʮ������ 
			sum = 0, reversal = 0;                         //ÿλ����֮�����������������ֵ0 
			while (num>0)
			{
				reversal = reversal * 10 + num % 10;	      //�������� 
				sum += (num % 10);                        //��λ���룬�ӵ�λ��ʼ�ۼ� 
				num /= 10;
			}
			if (sum == n && reversal == i)                 //һ�����ĸ�λ����֮�͵���n���ǻ������������ 
				printf("%d\n", i);
		}
	}
	return 0;
}