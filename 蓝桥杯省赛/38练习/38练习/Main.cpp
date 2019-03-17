#include <iostream>
using namespace std;
//int main()
//{
//	int year = 1777, month = 4, day = 30;
//	for (int i = 1; i < 8113; i++)
//	{
//		day++;
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		{
//			if (month == 2)
//			{
//				if (day == 30)
//				{
//					month++;
//					day = 1;
//				}
//			}
//		}
//		else
//		{
//			if (month == 2)
//			{
//				if (day == 29)
//				{
//					month++;
//					day = 1;
//				}
//			}
//		}
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		{
//			if (day == 32)
//			{
//				month++;
//				day = 1;
//			}
//		}
//		if (month == 4 || month == 6 || month == 9 || month == 11)
//		{
//			if (day == 31)
//			{
//				month++;
//				day = 1;
//			}
//		}
//		if (month == 13)
//		{
//			month = 1;
//			year++;
//		}
//
//	}
//	printf("%d %d %d\n", year, month, day);//1799 7 16
//	return 0;
//}

//int ans = 0;
//int main()
//{
//	int a = 1, b = 1, c = 1, d = 1, e = 1;
//	for (a=1; a <= 9; a++)
//	{
//		for (b=1; b <= 9; b++)
//		{
//			if (b == a)
//			{
//				continue;
//			}
//			for (c=1; c <= 9; c++)
//			{
//				if (c == a || c == b)
//				{
//					continue;
//				}
//				for (d=1; d <= 9; d++)
//				{
//					if (d == a || d == b || d == c)
//					{
//						continue;
//					}
//					
//					for (e=1; e <= 9; e++)
//					{
//						if (e == a || e == b || e == c || e == d)
//						{
//							continue;
//						}
//						int num1 = a * 10 + b;
//						int num2 = c * 100 + 10 * d + e;
//						int num3 = a * 100 + d * 10 + b;
//						int num4 = c * 10 + e;
//						if ((num1*num2) == (num3*num4))
//						{
//							ans++;
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("%d\n", ans); //142
//}

int ans = 0;
void f(int k,int flag)
{
	if (k < 0)
	{
		return;
	}
	if (k == 0&&(flag%2==0))
	{
		ans++;
		return;
	}
	f(k - 1,flag+1);
	f(k - 2,flag+1);  //写函数时一定不要写flag++
}

int main()
{
	f(39,0);
	cout << ans << endl;   //51167078
	return 0;
}