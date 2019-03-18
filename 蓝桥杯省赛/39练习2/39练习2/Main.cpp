#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//char arr[100][100] = {'0'};
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0,j=0;
//	//vector <int> v;
//	//memset(arr, 0, sizeof(arr));
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", &arr[i]);
//	}
//	return 0;
//}
#include <cstring>

//int main()
//{
//	char arr1[1000] = { '0' };
//	char arr2[1000] = { '0' };
//	scanf("%s", &arr1);
//	scanf("%s", &arr2);
//	int len1 = strlen(arr1), len2 = strlen(arr2);
//	int i = 0, j = 0;
//	int pos[100];
//	int step = 0;
//	memset(pos, 0, sizeof(pos));
//	for (i = 0; i < len1; i++)
//	{
//		if (arr1[i] != arr2[i])
//		{
//			pos[j++] = i;
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		step = pos[i + 1] - pos[i];
//		i = i + 1;
//	}
//	cout << step << endl;   //经过分析不同处肯定是偶数 所以拿下标找规律！
//	return 0;
//}
#include <algorithm>
#include <cstring>
#include <cstdlib>
//string s = {"123456789"};
//int pares(const char *arr, int pos, int len)
//{
//	int ans = 0;
//	int t = 1;
//	for (int i = pos + len - 1; i >= pos; i--)
//	{
//		ans += (arr[i] - '0')*t;
//		t *= 10;
//	}
//	return ans;
//}
//int main()
//{
//	int i = 0;
//	int ans = 0;
//	int n = 0;
//	scanf("%d", &n);
//	do{
//		const char *str = s.c_str();  //c_str()将string对象变成字符串！！ 返回一个const
//		for (int i = 1; i <= 7; i++)
//		{
//			//string a = s.substr(0,i);
//			//int inta = atoi(a.c_str());
//			int inta = pares(str, 0, i);
//			if (inta >= n)
//			{
//				break;
//			}
//			for (int j = 1; j <= 9 - i-1; j++)
//			{
//				int intb = pares(str, i, j);
//				int intc = pares(str, i + j, 9 - i - j);
//				//string b = s.substr(i , j);
//				//string c = s.substr(i+j);
//				//int intb = atoi(b.c_str());
//				//int intc = atoi(c.c_str());
//				if ((intb%intc == 0) && (inta + intb / intc) == n)
//				{
//					ans++;
//				}
//			}
//		}
//	} while (next_permutation(s.begin(), s.end()));
//	cout << ans << endl;
//	return 0;
//}

//int main()
//{
//	double a = 2.3, b = 1.9, sum = 82.3;
//	double num1 = sum / 2.3,num2=sum/1.9;
//	for (double i = 1.0; i <num1; i++)
//	{
//		for (double j = 1.0; j < num2; j++)
//		{
//			if ((a*j) + (b*i) == sum)
//			{
//				printf("%llf %llf\n", i, j);
//			}
//		}
//	}  //11 30
//	return 0;
//}

//1025

//int ans = 0;
//void f(int dian,int hua,int jiu)
//{
//	if (dian < 0 || hua < 0 || jiu < 0)
//	{
//		return ;
//	}
//	if (dian==0&&hua==0&&jiu==1)
//	{
//		ans++;
//	}
//	f(dian - 1, hua,jiu*2);
//	f(dian, hua-1,jiu-1);
//}
//
//int main()
//{
//	f(5,9,2);
//	cout << ans << endl;   //21
//	return 0;
//}


//int ans = 0;
//int gnd(int a, int b)
//{
//	if (b == 0)
//	{
//		return a;
//	}
//	return gnd(b, a%b);
//}
//int main()
//{
//	double a=0.0, b=0.0, c=0.0, d=0.0;
//	for (a = 1.0; a <10.0; a++)
//	{
//		for (b = 1.0; b <10.0; b++)
//		{
//			if (a == b)
//			{
//				continue;
//			}
//			for (c = 1.0; c <10.0; c++)
//			{
//				/*if (a == c || b == c)
//				{
//					continue;
//				}*/
//				for (d = 1.0; d <10.0; d++)
//				{
//					if ( c == d)
//					{
//						continue;
//					}
//					double num1 = a*c*(b * 10 + d);//出发转换成乘法
//					double num2 = (a * 10 + c)*b*d;
//					//double g1 = gnd(a*c,b*d);    //判断两个分数相等 ，用最大公约数判断！！
//					//double g2 = gnd((a * 10 + c), (b * 10 + d));
//					
//			/*		double num1 = a / b;
//					double num2 = c / d;
//					double num3 = a * 10 + c;
//					double num4 = b * 10 + d;*/
//				/*	if ((a*c)/g1==(a*10+c)/g2&&(b*d)/g1==(b*10+d)/g2)
//					{
//						cout << a << b << c << d << endl;
//						ans++;
//					}*/
//					if (num1 == num2)
//					{
//						cout << a << b << c << d << endl;
//						ans++;
//					}
//				/*	if ((num1*num2) == (num3 / num4))
//					{
//						cout << a << b << c << d << endl;
//						ans++;
//					}*/
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
//


int arr[] = { 2, 4, 5, 6, 7, 9, 10, 11, 12 };
int ans = 0;
int check(int arr[])
{
	int r1 = 1 + arr[0] + arr[3] + arr[5];
	int r2 = 8 + arr[0] + arr[1] + arr[2];
	int r3 = 1 + arr[1] + arr[4] + arr[8];
	int r4 = arr[2] + arr[4] + arr[7] + 3;
	int r5 = arr[5] + arr[6] + arr[7] + arr[8];
	int r6 = 8 + arr[3] + arr[6] + 3;
	if (r1==r2&&r2==r3&&r3==r4&&r4==r5&&r5==r6)
	{
		return 1;
	}
	return 0;
}
int main()
{
	do
	{
		if (check(arr))
		{
			cout << arr[3] << endl;
		}

	} while (next_permutation(arr, arr + 9));
	return 0;
}