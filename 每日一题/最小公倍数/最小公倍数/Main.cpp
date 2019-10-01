#include<iostream>
#include<vector>
using namespace std;
//求最小公倍数，两数想× 再除以最大公约数就ok！！！

int Get(int a, int b)
{
	int r = 0;
	//辗转相除法求出最大公因数
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << a*b / Get(a, b);
	return 0;
}