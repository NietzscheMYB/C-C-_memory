#include<iostream>
#include<vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int sum = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				sum += board[i][j];
			}
		}
		if (sum>0)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}