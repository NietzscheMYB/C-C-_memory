
#include<iostream>
using namespace std;

#if 0
int count(int n)
{
	int i = 0;
	int count[50] = { 0 };
	while (n)
	{
		count[i] = n % 2;
		n /= 2;
		i++;
	}
	int sum = 0;
	for (i = 0; i<50; i++)
	{
		sum += count[i];
	}

	return sum;
}
#endif

int count(int n)
{
	int flag = 1;
	int count[50] = { 0 };
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i<8; i++)
	{
		if (flag&(n >> i))
		{
			sum1 += 1;
		}
		else if (sum2 <= sum1)
		{
			sum2 = sum1;
			sum1 = 0;
		}
	}
	if (sum1 >= sum2)
	{
		return sum1;
	}
	else{
		return sum2;
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}



	return 0;
}