//////#include <iostream>
//////using namespace std;
//////int main()
//////{
//////	int ans = 0;
//////	int a, b, c, d, e;
//////	for (a = 1; a<10; a++)
//////	{
//////		if (a == 4)
//////		{
//////			continue;
//////		}
//////		for (b = 0; b<10; b++)
//////		{
//////			if (b == 4)
//////			{
//////				continue;
//////			}
//////			for (c = 0; c<10; c++)
//////			{
//////				if (c == 4)
//////				{
//////					continue;
//////				}
//////				for (d = 0; d<10; d++)
//////				{
//////					if (d == 4)
//////					{
//////						continue;
//////					}
//////					for (e = 0; e<10; e++)
//////					{
//////						if (e == 4)
//////						{
//////							continue;
//////						}
//////						printf("%d%d%d%d%d\n", a, b, c, d, e);
//////						ans++;
//////					}
//////				}
//////			}
//////		}
//////	}
//////	cout << ans << endl;  //52488 
//////	return 0;
//////}
////
////#include <iostream>
////#include <sstream>
////using namespace std;
////void i2s(int i, string &s)
////{
////	stringstream ss;
////	ss << i;
////	ss >> s;
////}
////bool check(string &s)
////{
////	if (s.find('4'))
////	{
////		return true;
////	}
////	return false;
////}
////int main()
////{
////	int ans = 0;
////	for (int i = 10000; i <= 99999; i++)
////	{
////		string s;
////		i2s(i, s);
////		if (!check(s))
////		{
////			ans++;
////		}
////
////	}
////	cout << ans << endl;
////	return 0;
////}
//
////
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c, d, e, f, g, h, i;
//	for (a = 0; a <= 9; a++)
//	{
//		for (b = 0; b <= 9; b++)
//		{
//			if (b == a)
//			{
//				continue;
//			}
//			for (c = 0; c <= 9; c++)
//			{
//				if (c == a || c == b)
//				{
//					continue;
//				}
//				for (d = 0; d <= 9; d++)
//				{
//					if (d == a || d == b || d == c)
//					{
//						continue;
//					}
//					for (e = 0; e <= 9; e++)
//					{
//						if (e == a || e == b || e == c || e == d)
//						{
//							continue;
//						}
//						for (f = 0; f <= 9; f++)
//						{
//							if (f == a || f == b || f == c || f == d || f == e)
//							{
//								continue;
//							}
//							for (g = 0; g <= 9; g++)
//							{
//								if (g == a || g == b || g == c || g == e || g == f || g == d)
//								{
//									continue;
//								}
//								//	for(h=0;h<=9;h++)
//
//
//								for (i = 0; i <= 9; i++)
//								{
//
//									if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
//									{
//										continue;
//									}
//									int num1 = a * 1000 + b * 100 + c * 10 + d;
//									int num2 = e * 1000 + f * 100 + g * 10 + b;
//									int num3 = e * 10000 + f * 1000 + c * 100 + b * 10 + i;
//									if ((num1 + num2) == num3)
//									{
//										printf("%d %d %d\n", num1, num2, num3);
//									}
//								}
//
//
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;  //9567 1085 10652
//}

#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 1; i <= 100; i++)
	{
		for (j = i; j <= 100; j++)
		{
			count += j;
			if (count == 236)
			{
				printf("%d\n", i);
				return 0;
			}
		}
		count = 0;
	}
	return 0;
}




