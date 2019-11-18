#include<iostream>
#include<math.h>
using namespace std;
int func(int num)
{
	int t = sqrt(num);
	int flag = 0;
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		return 1;
	}
	if (flag == 1)
	{
		return -1;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		int mid = n / 2;
		int num1 = mid, num2 = mid;
		while (num1&&num2)
		{
			int ret1, ret2;
			ret1 = func(num1);
			ret2 = func(num2);
			if (ret1 == 1 && ret2 == 1)
			{
				if ((num1 + num2) == n)
				{
					cout << num1 << endl;
					cout << num2 << endl;
					break;
				}
			}
			num1--;
			num2++;
		}
	}
	return 0;
}