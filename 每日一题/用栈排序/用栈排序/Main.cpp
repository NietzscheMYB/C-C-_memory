#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:
	void sort()
	{
		int arr[] = { 1, 3, 4, 2};
		stack<int> s1;
		for (int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++)
		{
			s1.push(arr[i]);
		}

		stack<int> ans;
		int temp;
		int j = 0;
		while (!s1.empty())
		{
			temp = s1.top();
			s1.pop();
			while (!ans.empty() && ans.top() < temp)
			{
				s1.push(ans.top());
				ans.pop();
			}
			ans.push(temp);
		}
		while (!ans.empty())
		{
			s1.push(ans.top());
			ans.pop();
		}
	}
};

int main()
{
	Solution s;
	s.sort();


	return 0;
}