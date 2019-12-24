#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.empty())
		{
			return num2;
		}
		if (num2.empty())
		{
			return num1;
		}
		if (num1.empty() && num2.empty())
		{
			return nullptr;
		}
		if (num1.size()<num2.size())
		{
			swap(num1, num2);
		}
		string ans;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int cy = 0;
		int sum = 0;
		for (int i = 0; i<num1.size(); i++)
		{
			if (i<num2.size())
			{
				int a = num1[i] - '0';
				int b = num2[i] - '0';
				sum = a + b + cy;
				cy = sum / 10;
				sum = sum % 10;
				ans.push_back(sum + '0');
				continue;
			}
			int c = num1[i] - '0';
			sum = c + cy;
			cy = sum / 10;
			sum = sum % 10;
			ans.push_back(sum + '0');
		}
		if (cy != 0)
		{
			ans.push_back(cy + '0');
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main()
{
	Solution s;
	cout << s.addStrings("123", "123") << endl;
	return 0;
}