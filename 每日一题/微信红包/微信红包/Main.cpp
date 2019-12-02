#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int index1 = n / 2;
		int index2 = index1 + 1, index3 = index1 - 1;
		if (gifts[index1] == gifts[index2] && gifts[index1] == gifts[index3])
		{
			return gifts[n / 2];
		}
		else{
			return 0;
		}
	}
};

int main()
{
	return 0;
}