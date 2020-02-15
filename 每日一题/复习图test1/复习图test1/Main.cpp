#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//图是由顶点和边组成，每条边的两端都是图的顶点，
//G(v,e)表示图G 的顶点集合为v，边集合为e

//图分为有向图与无向图
//有向图 表示所有边都有方向，即确定了顶点到顶点的位置
//无向图 表示所有边都是双向的， 无向边所连接的顶点可以互相到达

//顶点度：和该顶点相连边的条数，对与有向图来说，顶点的出边称为顶点的出度，顶点的入边称为顶点的入度
//顶点与边都可以有一定属性，量化的属性称为权值，点权，边权

//图的存储:邻接矩阵存储与邻接表存储

//邻接矩阵就是一个二维数组G[N][N] 如果G[i][j]为1说明顶点与顶点之间有边，
//如果G[i][j]为0 说明顶点与顶点之间不存在边。
//可以令G[i][j]存放边权，对不存在的边权设为0，-1，或其他很大的数
//邻接矩阵比较好写，但是需要开辟个二维数组，如果题目顶点数目太大
//可以超过内存限制，不适应顶点数目太大

//邻接表：数组+链表
//把同一个顶点的所有出边放在一个列表中，那么N个顶点就会有N个列表
//没有出边则对应空表，这个N个列表称为图的邻接表
//记作Adj[N]  其中Adj[i]存放顶点i的所有出边组成的列表。


//图的遍历：
//DFS，每次都是沿着路径到不能再前进时，才退回到最近的岔路口
//BFS，需要使用一个队列，通过反复取出队首顶点，将该顶点可到达的为曾经入过顶点全部入队，直到队列为空时遍历结束。
//强连通分量，连通分量称为连通块，遍历图是将所有连通块分别进行遍历。

namespace test1
{
	const int MAXV = 1000;//最大顶点数
	const int INF = 1000000;//设INF为一个很大的数

	//邻接矩阵版
#if 0
	int n, G[MAXV][MAXV];//n为顶点数
	bool vis[MAXV] = { false };//如果顶点i被访问则，vis[i]=true;

	//void DFS(int u, int depth)//u为当前访问的顶点标号，depth为深度
	//{
	//	vis[u] = true;//设置u已经被访问
	//	//如果需要对u进行一些操作，可以在这进行
	//	//下面对所有从u出发能到达的分支顶点进行枚举
	//	for (int v = 0; v < n; v++)
	//	{
	//		if (vis[v] == false && G[u][v] != INF)
	//		{
	//			DFS(v, depth + 1);
	//		}
	//	}
	//}
	//void DFSTrave()//遍历图
	//{
	//	for (int u = 0; u < n; u++)
	//	{
	//		if (vis[u] == false)
	//		{
	//			DFS(u, 1);//访问u和u所在的连通块，1表示初始化为1层
	//		}
	//	}
	//}
	void DFS(int u, int depth)//u表示当前编号
	{
		//设置u已经被访问
		vis[u] = true;
		//对u的相关操作在这里进行

		//访问u的其他连接的顶点v
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				DFS(v, depth + 1);
			}
		}
	}
	void DFSTrave()
	{
		for (int u = 0; u < n; u++)//对所有顶点的连通块进行访问
		{
			if (vis[u] == false)
			{
				DFS(u, 1);//如果该图是连通图，则DFS只需要走一次，因为只有一个连通块
			}
		}
	}
#endif

#if 0
	//邻接表版
	vector<int> Adj[MAXV];// 图G的邻接表
	int n;//n为顶点数，MAXV为最大顶点数
	bool vis[MAXV] = { false };

	//void DFS(int u, int depth)
	//{
	//	vis[u] = true;
	//	//如果需要对u进行一些操作，可以在此处进行

	//	for (int i = 0; i < Adj[u].size(); i++)
	//	{
	//		int v = Adj[u][i];//Adj[u][i]存在着下一个节点的编号
	//		if (vis[v] == false)
	//		{
	//			DFS(v, depth + 1);
	//		}
	//	}
	//}
	//void DFSTrave()
	//{
	//	for (int u = 0; u < n; u++)
	//	{
	//		if (vis[u] == false)
	//		{
	//			DFS(u, 1);//访问连通块
	//		}
	//	}
	//}
	void DFS(int u, int depth)
	{
		vis[u] == true;
		//需要对u进行操作，在这进行
		for (int i = 0; i < Adj[u].size(); i++)
		{
			int v = Adj[u][i];
			if (vis[v] == false)
			{
				DFS(v, depth + 1);
			}
		}
	}
	void DFSTrave()
	{
		for (int u = 0; u < n; u++)
		{
			if (vis[u] == false)
			{
				DFS(u, 1);;//遍历当前连通块
			}
		}
	}
#endif
	//BFS
#if 0
	//邻接矩阵
	//int n, G[MAXV][MAXV];
	//bool inq[MAXV] = { false };
	//void BFS(int u)//u为顶点编号
	//{
	//	queue<int> q;
	//	q.push(u);
	//	inq[u] = true;
	//	while (!q.empty())
	//	{
	//		int u = q.front();//取出队首元素
	//		q.pop();
	//		for (int v = 0; v < n; v++)
	//		{
	//			if (inq[v] == false && G[u][v] != INF)
	//			{
	//				q.push(v);
	//				inq[v] = true;
	//			}
	//		}
	//	}
	//}
	//void BFSTrave()
	//{
	//	for (int u = 0; u < n; u++)
	//	{
	//		if (inq[u] == false)
	//		{
	//			BFS(u);//广度访问连通块
	//		}
	//	}
	//}
	int n, G[MAXV][MAXV];
	int inq[MAXV] = { false };
	void BFS(int u)//u为当前顶点编号
	{
		queue<int> q;
		q.push(u);
		inq[u] = true;
		while (!q.empty())
		{
			int u = q.front();

			//在这对u进行操作
			q.pop();
			for (int v = 0; v < n; v++)
			{
				if (inq[v] == false && G[u][v] != INF)
				{
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
		void BFSTrave()
		{
			for (int u = 0; u < n; u++)
			{
				if (inq[u] == false)
				{
					BFS(u);
				}
			}
		}
#endif
	vector<int> Adj[MAXV];
	int n;
	bool inq[MAXV] = { false };
	void BFS(int u)
	{
		queue<int> q;
		q.push(u);
		inq[u] = true;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = 0; i < Adj[u].size(); i++)
			{
				int v = Adj[u][i];
				if (inq[v] == false)
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	void BFSTrave()
	{
		for (int u = 0; u < n; u++)
		{
			if (inq[u] == false)
			{
				BFS(u);

			}
		}
	}


}
int main()
{

	return 0;
}