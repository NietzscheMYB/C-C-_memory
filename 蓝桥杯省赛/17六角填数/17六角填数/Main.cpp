#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void check(vector<int> v)
{
	int r1 = 1 + v[0] + v[3] + v[5];
	int r2 = 1 + v[1] + v[4] + v[8];
	int r3 = 8 + v[0] + v[1] + v[2];
	int r4 = 11 + v[3] + v[6];
	int r5 = 3 + v[2] + v[4] + v[7];
	int r6 = v[5] + v[6] + v[7] + v[8];
	if (r1 == r2&&r2 == r3&&r3 == r4&&r4 == r5&&r5 == r6)
	{
		for (int i = 0; i < 9; ++i) {
			cout << v[i] << " " << endl;
		}
	}
}

int main()
{
	vector<int> v;
	v.push_back(2);
	for (int i = 4; i <= 7; i++)
	{
		v.push_back(i);
	}
	for (int i = 9; i <= 12; i++)
	{
		v.push_back(i);
	}
	do
	{
		check(v);
	} while (next_permutation(v.begin(),v.end()));
	return 0;


}