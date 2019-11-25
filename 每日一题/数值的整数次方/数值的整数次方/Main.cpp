#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
		{
			return 1;
		}
		int n = exponent, x = base;
		if (n < 0)
		{
			n = -n;
		}
		double ret=base;

		for (int i = 1; i<n; i++)
		{
			ret *= base;
		}
		return exponent>0 ? ret : (1 / ret);

	}
};

int main()
{
	Solution s;
	cout << s.Power(10,3) << endl;

	return 0;
}