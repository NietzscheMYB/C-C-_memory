#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int maxn = 100;
struct node{
	int x, y;//位置x，y
	int step;//step 为从起点到达该位置的最少步数(即层数)
}S,T,Node;

int n, m;//n为行 m为列
char maze[maxn][maxn]; 
bool inq[maxn][maxn] = { false };//记录位置x，y是否入队
int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };

//检测位置x，y是否有效
bool test(int x, int y)
{
	//检查越界
	if (x >= n || x < 0 || y >= m || y < 0){ return false; }
	//检查墙壁
	if (maze[x][y] == '*'){ return false; }
	//检查是否入队
	if (inq[x][y] == true){ return false; }
	//有效位置
	return true;
}

int BFS()
{
	queue<node> q;
	q.push(S);
	inq[S.x][S.y] = true;
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		if (top.x == T.x&&top.y == T.y)
		{
			return top.step;
		}
		for (int i = 0; i < 4; i++)
		{
			int newx = top.x + x[i];
			int newy = top.y + y[i];
			if (test(newx, newy))
			{
				//设置Node坐标 newx，newy
				Node.x = newx;
				Node.y = newy;
				Node.step = top.step + 1;//Node层为top层+1
				q.push(Node);
				inq[newx][newy] = true; //设置位置newx newy 已入队
			}

		}
	}
	return -1;

}

int main()
{
	cin >> n >> m;
	vector<string> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			maze[i][j] = v[i][j];
		}
	}
	cin >> S.x >> S.y >> T.x >> T.y;
	S.step = 0;
	cout << BFS() << endl;
	return 0;
}