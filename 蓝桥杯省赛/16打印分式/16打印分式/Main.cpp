#include <iostream>
using namespace std;
int ans = 0;
int gnd(int a, int b)
{
	if (b == 0)
		return a;
	return gnd(b, a%b);
}
int main()
{
	double a, b, c, d, num1, num2;
	for (a = 1.0; a <= 9.0; a++)
	{
		for (b = 1.0; b <= 9.0; b++)
		{
			if (a == b)
			{
				continue;
			}
			for (c = 1.0; c <= 9.0; c++)
			{
				for (d = 1.0; d <= 9.0; d++)
				{
					if (c == d)
					{
						continue;
					}
					num1 = a*c*(b * 10 + d);
					num2 = b*d*(a * 10 + c);
					//if (num1 == num2)
						if((a*c/num1==(b*10+d)/num2)&&(b*d/num1==(a*10+d)/num2))
					{
						ans++;
					}
				}
			}
		}
	}
	cout << gnd(8,16) << endl;
	cout << ans << endl;
}