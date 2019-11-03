#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		//没一行使用二分查找！！！
		//所以时间复杂度为nlgn！！
		for (int i = 0; i < array.size(); i++)
		{
			int left = 0;
			int right = array[i].size()-1;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (array[i][mid] > target)
				{
					right = mid - 1;
				}
				else if (array[i][mid] < target)
				{
					left = mid + 1;
				}
				else if (array[i][mid] == target)
				{
					return true;
				}
			}
		}
		return false;
	}
};

class Solution2{
public:
	bool  Find(int target, vector<vector<int> > array){
		int i = array.size()-1;
		int j = 0;
		while (j<array[0].size() && i >= 0)//因为根据矩阵的特性，如果一个数比左下角的值大的话，肯定在左下角右边，
			//比左下角的值小的话，肯定在左下角的上面 依次类推，就能找到！！
		{

			if (target > array[i][j])
			{
				j++;
			}
			else if (target < array[i][j])
			{
				i--;
			}
			else if (target == array[i][j])
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> x(5);//这个是首先有了5行！！
	for (int i = 0; i < x.size(); i++)
	{
		x[i].resize(3);//每一行3列！！
	}

	return 0;
}