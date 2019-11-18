#include<iostream>
using namespace std;

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};

int main()
{

	return 0;
}