#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#if 0
int main()
{
	int x1, x2, x3,x4;
	cin >> x1 >> x2 >> x3>>x4;

	int a = (x1 + x3) / 2;
	int b = (x2 + x4) / 2;
	int c = x4 - b;
	if (x1 == (a - b) && x2 == (b - c) && x3 == (a + b) && x4 == (b + c))
	{
		cout << a << " " << b << " " << c << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}
#endif 

int main()
{
	char *arr= {"0123456789ABCDEF"};
	int m, n;
	cin >> m >> n;
	string s;
	int k = m;
	if (k < 0)
	{
		k = -k;
	}
	while (k)
	{
		s += arr[k%n];
		k /= n;
	}
	reverse(s.begin(), s.end());
	if (m < 0)
	{
		cout <<"-"<<s << endl;
		return 0;

	}
	cout << s << endl;

	return 0;
}