#include<iostream>
#include<vector>
#include<string>
using namespace std;

int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };
int flag = 0;
int vis[100][100] = { 0 };
class Solution {
public:
	bool test(vector<vector<char>>& board, int vis[100][100],int x,int y)
	{
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
		{
			return false;
		}
		if (vis[x][y] == 1)
		{
			return false;
		}
		return true;
	}
	void DFS(vector<vector<char>>& board, string word, string s, int depth, int x, int y, int vis[100][100])
	{
		s += board[x][y];
		vis[x][y] = 1;
		if (s == word){flag=1;return;}
		if (depth == word.size()||board[x][y]!=word[depth-1]){ return; }

		for (int i = 0; i < 4; i++)
		{
			int newx = x + X[i];
			int newy = y + Y[i];
			if (test(board, vis, newx, newy))
			{
				DFS(board, word, s, depth + 1, newx, newy, vis);
			}
		}
		vis[x][y] = 0;
	}
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0])
				{
					string s;
					DFS(board, word, s,1,i,j,vis);
					if (flag == 1)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
};


#if 0
ABCE
SFCS
ADEE
ABCCED

abcd
#endif
int main()
{
	vector<vector<char>> b(2,vector<char>(2,'A'));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> b[i][j];
		}
	}
	Solution s;
	string t = "acdb";
	if (s.exist(b, t))
	{
		cout << 1<< endl;

	}
	
	return 0;
}