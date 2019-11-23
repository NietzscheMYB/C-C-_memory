#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	void reOrderArray(vector<int> &array) {
//		vector<int> v1;
//		vector<int> v2;
//		for (int i = 0; i < array.size(); i++)
//		{
//			if (array[i] % 2 == 0)
//			{
//				v1.push_back(array[i]);
//			}
//			else
//			{
//				v2.push_back(array[i]);
//			}
//		}
//		for (int i = 0; i < v2.size(); i++)
//		{
//			array[i] = v2[i];
//		}
//		for (int i = v2.size(),j=0; i < array.size()&&j<v2.size(); i++)
//		{
//			array[i] = v1[j++];
//		}
//	}
//};

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int i = 0, j = 0;
		for (i = 0; i < array.size(); i++)
		{
			int  key = array[i];
			if (key % 2 == 0)
			{
				for (j = i - 1; j >= 0&&array[j]%2==0&&key<array[j]; j--)
				{

					array[j + 1] = array[j];

				}
				array[j + 1] = key;

			}
			else if (key % 2 != 0)
			{
				for (j = i - 1; j >= 0 && array[j] % 2 == 0; j--)
				{
					array[j + 1] = array[j];
				}
				for (; j >= 0&& key<array[j]; j--)
				{

					array[j + 1] = array[j];
				}
				array[j + 1] = key;
			}
			
		}
	}
};

int main()
{
	vector<int> v;
	for (int i = 1; i <= 7; i++)
	{
		v.push_back(i);
	}
	Solution s;
	s.reOrderArray(v);
	return 0;
}