#include<iostream>
#include<vector>
using namespace std;
#if 1
int fun(int n)
{
	if (n <= 2)
	{
		return -1;
	}
	if ((1 + n - 2)%2==0)
	{
		return 2;
	}
	else{
		return 3;
	}
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
#endif

