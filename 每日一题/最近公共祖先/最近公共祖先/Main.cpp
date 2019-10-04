#include<iostream>
using namespace std;
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			if (a<b)
			{
				b /= 2;
			}
			else{
				a /= 2;
			}
		}
		return a;
	}
};