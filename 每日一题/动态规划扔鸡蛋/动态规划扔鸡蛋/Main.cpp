#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int eggNum, floorNum;//M¥������N�Ǽ����ĸ���
	cin >> eggNum >> floorNum;

	//F(M,N) ��ʾ��ǰM�㣬N��������������£����ĳ��Դ���
	vector<vector<int>> f(eggNum+1, vector<int>(floorNum+1, 0));

	for (int i = 1; i <= eggNum; i++)
	{
		f[1][i] = 1;
	}

	////��ÿ��Ԫ�س�ʼ�������ĳ��Դ���
	for (int i = 1; i <= eggNum; i++)
	{
		for (int j = 1; j <= floorNum; j++)
		{
			f[i][j] = j;
		}
	}

	for (int i = 2; i <= eggNum; i++)
	{
		for (int j = 1; j <= floorNum; j++)
		{
			for (int k = 1; k < j; k++)
			{
				f[i][j]= min(f[i][j],max(f[i - 1][k - 1] + 1, f[i][j-k] + 1));
			}
		}
	}
	cout << f[eggNum][floorNum] << endl;
	return 0;
}