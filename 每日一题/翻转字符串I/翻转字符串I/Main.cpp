#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.size() == 0)
		{
			return;
		}
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return;
	}
};

int main()
{
	return 0;
}