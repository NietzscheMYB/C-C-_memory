#include<iostream>
#include<string>
using namespace std;
#if 0
int main()
{
	string s;
	cin >> s;
	string maxs;
	string temp;
	int countmax=0;
	int count = 0;
	int i = 0;
	for (i = 0; i < s.size()-1; i++)
	{
		if ((s[i + 1] - s[i]) == 1)
		{
			temp += s[i];
			count++;
		}
		else
		{
			temp += s[i];
			count++;
			if (countmax < count)
			{
				countmax = count;
				maxs.clear();
				maxs = temp;
				count = 0;
			}
			temp.clear();
			count = 0;
		}
	}
	temp += s[i];
	count++;
	if (countmax < count)
	{
		countmax = count;
		maxs.clear();
		maxs = temp;
		count = 0;
	}
	cout << maxs << endl;
	return 0;
}
#endif
#include<vector>
#include<algorithm>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		sort(numbers.begin(), numbers.end());
		int x = numbers[length / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == x)
			{
				count++;
			}
		}
		if (count>(length / 2))
		{
			return numbers[length / 2];
		}

		return 0;
	}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);

	Solution x;
	int ret=x.MoreThanHalfNum_Solution(v);
	cout << ret << endl;
	return 0;
}