#include<iostream>
using namespace std;
int fun(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}
	return fun(n - 1)+fun(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << fun(n) << endl;
	}

	return 0;
}