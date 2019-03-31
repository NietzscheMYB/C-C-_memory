//std::vector  的核心框架接口的模拟实现bit::Vector
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//打印杨辉三角
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> Maxtrix;//嵌套定义！！
		//vector<vector<int>>
		Maxtrix.resize(numRows);//分配numRows行 //
		for (int i = 0; i < numRows; i++)
		{

			//vector<int>
			Maxtrix[i].resize(i + 1,1);//每一行分配i+1个空间
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