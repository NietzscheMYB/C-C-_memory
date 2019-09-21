#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		cin >> n;
		v.push_back(n);
	}
		int a, b, c;
		a = (v[0] + v[2]) / 2;
		b = a - v[0];
		c = v[3] - b;
		if (((a-b)==v[0])&&((b-c)==v[1])&&((a+b)==v[2])&&((b+c)==v[3]))
		{
			cout << a << " " << b << " " << c << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	
	return 0;
}