#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		//ûһ��ʹ�ö��ֲ��ң�����
		//����ʱ�临�Ӷ�Ϊnlgn����
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
		while (j<array[0].size() && i >= 0)//��Ϊ���ݾ�������ԣ����һ���������½ǵ�ֵ��Ļ����϶������½��ұߣ�
			//�����½ǵ�ֵС�Ļ����϶������½ǵ����� �������ƣ������ҵ�����
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
	vector<vector<int>> x(5);//�������������5�У���
	for (int i = 0; i < x.size(); i++)
	{
		x[i].resize(3);//ÿһ��3�У���
	}

	return 0;
}