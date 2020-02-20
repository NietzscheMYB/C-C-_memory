#include<iostream>
#include<vector>
using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };

class Solution {
public:
	bool judeg(int x, int y, int m, int n, vector<vector<bool>>&vis,int k)
	{
		if (x<0 || x >= m || y<0 || y >= n){return false;}
		if (vis[x][y] == true){return false;}
		if ((Cal(x) + Cal(y)) > k){ return false; }
		return true;
	}
public:
	int Cal(int m)
	{
		int key = 0;
		while (m)
		{
			key+= m % 10;
			m/= 10;
		}
		return key;
	}
	void DFS(int x,int y,int& ans,int k,vector<vector<bool>>& vis,int m,int n)
	{
		ans++;
	
		for (int i = 0; i < 4; i++)
		{
			int newx = x + X[i];
			int newy = y + Y[i];
			if (judeg(newx, newy, m, n, vis,k))
			{
				vis[newx][newy] = true;
				DFS(newx, newy, ans, k, vis, m, n);
			}
		}
	}
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> vis(m, vector<bool>(n, false));
		//int count = 0;
		vis[0][0] = true;
		DFS(0, 0, ans, k, vis, m, n);
		return ans;
	}
	int ans = 0;
};

int main()
{
	Solution s;
	cout << s.movingCount(3, 1, 0) << endl;
	return 0;
}