#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		if (s.empty())
		{
			return -1;
		}
		int arr[267] = { 0 };
		for (int i = 0; i<s.size(); i++)
		{
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (arr[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{

	return 0;
}