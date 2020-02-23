#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	////6 10 15
public:
	int nthUglyNumber(int index) {

		// 0-6的丑数分别为0-6
		if (index < 7) return index;
		//p2，p3，p5分别为三个队列的指针，newNum为从队列头选出来的最小数
		int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
		vector<int> arr;
		arr.push_back(newNum);
		while (arr.size() < index) {
			//选出三个队列头最小的数
			newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
			//这三个if有可能进入一个或者多个，进入多个是三个队列头最小的数有多个的情况
			if (arr[p2] * 2 == newNum) p2++;
			if (arr[p3] * 3 == newNum) p3++;
			if (arr[p5] * 5 == newNum) p5++;
			arr.push_back(newNum);
		}
		return newNum;
	}
};

int main()
{
	return 0;
}