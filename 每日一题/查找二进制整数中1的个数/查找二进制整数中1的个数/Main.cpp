#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if (1 << i&n)
			{
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}