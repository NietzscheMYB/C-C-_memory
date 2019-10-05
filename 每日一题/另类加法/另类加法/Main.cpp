#include<iostream>
using namespace std;
class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;
		while (B != 0)
		{
			sum = A^B;
			carry = (A&B) << 1;//×óÒÆ¶¯Ò»Î»
			A = sum;
			B = carry;
		}
		return sum;
	}

};
int main()
{
	UnusualAdd x;
	cout << x.addAB(2, 3) << endl;
	return 0;
}