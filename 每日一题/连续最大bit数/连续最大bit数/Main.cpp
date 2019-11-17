#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		int max = 0;
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			if ((1 << i)&n)
			{
				count++;
				continue;
			}
			if (max <= count)
			{
				max = count;
				count = 0;
			}
		}

		if (max <= count)
		{
			max = count;
			count = 0;
		}

			cout << max << endl;

	}

	return 0;
}