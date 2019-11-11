#include<iostream>
#include<vector>
using namespace std;

#if 0
class Solution {
public:
	int Fibonacci(int n) {
		int arr[3000];
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i < 3000; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n - 1];
	}
};
#endif 

#include<algorithm>
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		sort(rotateArray.begin(), rotateArray.end());
		return rotateArray[0];
	}
};


int main()
{
	return 0;
}