#include<iostream>

using namespace std;

class LCA {
public:
	int getLCA(int a, int b) {
		if (a == b)
		{
			return a;
		}
		while ((a / 2) != (b / 2))
		{
			if (a > b)
			{
				a /= 2;
			}
			else if(a<b){
				b /= 2;
			}
		}
		return a / 2;
	}
};

int main()
{
	return 0;
}