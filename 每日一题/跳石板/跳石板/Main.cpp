#include<iostream>
using namespace std;

int func(int m)
{
	int flag = 0;
	for (int i = 2; i < m; i++)
	{
		if (m%i == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int maxfun(int n)
{
	for (int i = n - 1; i > 1; i--)
	{
		if (n%i == 0&&i%2==0)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int N, M;
	cin >> N >> M;
	if (func(M) == 0||func(N)==0)
	{
		cout << -1 << endl;
		return 0;
	}
	int num = N;
	int count = 0;
	while (num != M&&num<M)
	{
		int max = maxfun(num);
		num += max;
		count++;
	}


	cout << count << endl;

	return 0;
}