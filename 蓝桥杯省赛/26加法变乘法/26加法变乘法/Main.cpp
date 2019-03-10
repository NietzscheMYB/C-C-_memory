//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[49];
//	int i = 0,j=1,m=0,a=0,b=0,c=0;
//	int num1 = 0, num2 = 0,num3=0,num4=0,num5=0;
//	for (i = 0; i < 49; i++,j++)
//	{
//		arr[i] = j;
//	}
//	for (i = 0; i < 49; i++)
//	{
//		if ((i + 1) == 49)
//		{
//			break;
//		}
//		for (a = i - 1; a >= 0; a--)
//		{
//			num4 += arr[a];
//		}
//		num1 = arr[i] * arr[i + 1];
//		for (j = i + 2; j < 49; j++)
//		{
//			for (b = i + 2; b <= j - 1; b++)
//			{
//				num5 += arr[b];
//			}
//			if ((j + 1) == 49)
//			{
//				continue;
//			}
//			num2 = arr[j] * arr[j + 1];
//			for (m = j + 2; m < 49; m++)
//			{
//				num3 += arr[m];
//			
//			}
//			if ((num1 + num2+num3+num4+num5) == 2015)
//				{
//					printf("%d\n",i);
//				}
//			num3 = 0, num2 = 0, num1 = 0;
//			num4 = 0, num5 = 0;
//		}
//		
//	}
//}
#include <iostream>
using namespace std;     //因为与上式相比，只是＋变*，因此只算差值即可
int main()
{
	for (int i = 0; i <= 46; i++)
	{
		for (int j = i + 2; j <= 48; j++)
		{
			if ((i*(i + 1) + j*(j + 1) -i-(i+1)-j-(j+1))== 2015 - 1225)
			{
				cout << i << " " << j << endl;
			}
		}
	}


	return 0;
}