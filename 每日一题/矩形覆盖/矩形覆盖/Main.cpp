#include<iostream>
using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number <=0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		if (number == 2)
		{
			return 2;
		}
		if (number == 3)
		{
			return 3;
		}
		return rectCover(number - 1) + rectCover(number - 2);
	}
};

int main()
{
	return 0;
}