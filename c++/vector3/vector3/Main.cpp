//std::vector  �ĺ��Ŀ�ܽӿڵ�ģ��ʵ��bit::Vector
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//��ӡ�������
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> Maxtrix;//Ƕ�׶��壡��
		//vector<vector<int>>
		Maxtrix.resize(numRows);//����numRows�� //
		for (int i = 0; i < numRows; i++)
		{

			//vector<int>
			Maxtrix[i].resize(i + 1,1);//ÿһ�з���i+1���ռ�
			//Maxtrix.operator[](i).operator[](i)
			//Maxtrix[i][0] = Maxtrix[i][i] = 1;
		}
		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				Maxtrix[i][j] = Maxtrix[i - 1][j - 1] + Maxtrix[i - 1][j];
			}
		}
		//for (int i = 2; i < numRows; i++)
		//{
		//	for (int j = 1; j < i; j++)
		//	{
		//		//Maxtrix[i][j] = Maxtrix[i - 1][j - 1] + Maxtrix[i - 1][j];
		//		cout << Maxtrix[i][j] << endl;
		//	}
		//}
		return Maxtrix;
	}
};
int main()
{
	Solution s;
	


}