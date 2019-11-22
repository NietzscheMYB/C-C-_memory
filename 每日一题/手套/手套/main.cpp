#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum=0, right_sum=0;
		int left_min = INT_MAX, right_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				sum+=left[i]+right[i];

			}
			else
			{
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);

				left_sum += left[i];
				right_sum += right[i];
			}

		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{
	Gloves s;
	vector<int> left;
	left.push_back(0);
	left.push_back(7);
	left.push_back(1);
	left.push_back(6);

	vector<int> right;
	right.push_back(1);
	right.push_back(5);
	right.push_back(0);
	right.push_back(6);



	cout << s.findMinimum(4, left, right) << endl;
	return 0;
}