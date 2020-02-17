#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	int x;
	int y;
	Node(int a, int b)
	{
		x = a;
		y = b;
	}
};
bool inq[11][11] = { false };
int X[4] = { 0, 0, 1, -1 };
int Y[4] = { 1, -1, 0, 0 };
class Solution {
public:

	bool test(Node tem, int a, int b, vector<vector<int>>& grid)
	{
		if (tem.x > a || tem.x <= 0 || tem.y > b || tem.y <= 0)
		{
			return false;
		}
		if (inq[tem.x][tem.y] == true || grid[tem.x - 1][tem.y - 1] == 0)
		{
			return false;
		}
		return true;
	}
	int ans = 0;
	queue<Node> q;

public:
	void BFS(vector<vector<int>>& grid)
	{
		int flag = 0;
		while (!q.empty())
		{
			Node tem = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int newx = tem.x + X[i];
				int newy = tem.y + Y[i];
				Node newnode(newx, newy);
				if (test(newnode, grid.size(), grid[0].size(), grid))
				{
					flag = 1;
					grid[newx - 1][newy - 1] = 2;
					q.push(newnode);
					inq[newnode.x][newnode.y] = true;
				}
			}
			if (flag == 1)
			{
				ans++;
				flag = 0;
			}
		}
	}
	int orangesRotting(vector<vector<int>>& grid) {
		for (int i = 1; i <= grid.size(); i++)
		{
			for (int j = 1; j <= grid[0].size(); j++)
			{
				if (grid[i - 1][j - 1] == 2)
				{
					q.push(Node(i, j));
					inq[i][j] = true;
				}
			}
		}
		BFS(grid);

		for (int i = 1; i <= grid.size(); i++)
		{
			for (int j = 1; j <= grid[0].size(); j++)
			{
				if (grid[i-1][j-1] == 1)
				{
					return -1;
				}
			}
		}        

		return ans;
	}
};

int main()
{
	vector<vector<int>> v(1, vector<int>(2, 0));
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> v[i][j];
		}
	}
	Solution s;
	cout << s.orangesRotting(v) << endl;
	return 0;
}

