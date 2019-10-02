#include<iostream>
using namespace std;
int xx = 0;
void Count(int n, int m)
{
	if (n<1 || m<1)
	{
		return;
	}
	if (n == 1 && m == 1)
	{
		xx++;
		return;
	}
	if (n >= 1 && m >= 1)
	{
		Count(n, m - 1);
		Count(n - 1, m);
	}
	return;
}

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		Count(n + 1, m + 1);
		cout << xx << endl;
		xx = 0;
	}
	return 0;
}