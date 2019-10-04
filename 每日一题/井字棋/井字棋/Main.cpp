#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		auto v = board;
		int sum = 0;
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				sum += v[i][j];
			}
		}
		if (sum>0)
		{
			return true;
		}
		else{
			return false;
		}
	}
};