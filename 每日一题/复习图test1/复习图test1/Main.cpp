#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//ͼ���ɶ���ͱ���ɣ�ÿ���ߵ����˶���ͼ�Ķ��㣬
//G(v,e)��ʾͼG �Ķ��㼯��Ϊv���߼���Ϊe

//ͼ��Ϊ����ͼ������ͼ
//����ͼ ��ʾ���б߶��з��򣬼�ȷ���˶��㵽�����λ��
//����ͼ ��ʾ���б߶���˫��ģ� ����������ӵĶ�����Ի��ൽ��

//����ȣ��͸ö��������ߵ���������������ͼ��˵������ĳ��߳�Ϊ����ĳ��ȣ��������߳�Ϊ��������
//������߶�������һ�����ԣ����������Գ�ΪȨֵ����Ȩ����Ȩ

//ͼ�Ĵ洢:�ڽӾ���洢���ڽӱ�洢

//�ڽӾ������һ����ά����G[N][N] ���G[i][j]Ϊ1˵�������붥��֮���бߣ�
//���G[i][j]Ϊ0 ˵�������붥��֮�䲻���ڱߡ�
//������G[i][j]��ű�Ȩ���Բ����ڵı�Ȩ��Ϊ0��-1���������ܴ����
//�ڽӾ���ȽϺ�д��������Ҫ���ٸ���ά���飬�����Ŀ������Ŀ̫��
//���Գ����ڴ����ƣ�����Ӧ������Ŀ̫��

//�ڽӱ�����+����
//��ͬһ����������г��߷���һ���б��У���ôN������ͻ���N���б�
//û�г������Ӧ�ձ����N���б��Ϊͼ���ڽӱ�
//����Adj[N]  ����Adj[i]��Ŷ���i�����г�����ɵ��б�


//ͼ�ı�����
//DFS��ÿ�ζ�������·����������ǰ��ʱ�����˻ص�����Ĳ�·��
//BFS����Ҫʹ��һ�����У�ͨ������ȡ�����׶��㣬���ö���ɵ����Ϊ�����������ȫ����ӣ�ֱ������Ϊ��ʱ����������
//ǿ��ͨ��������ͨ������Ϊ��ͨ�飬����ͼ�ǽ�������ͨ��ֱ���б�����

namespace test1
{
	const int MAXV = 1000;//��󶥵���
	const int INF = 1000000;//��INFΪһ���ܴ����

	//�ڽӾ����
#if 0
	int n, G[MAXV][MAXV];//nΪ������
	bool vis[MAXV] = { false };//�������i��������vis[i]=true;

	//void DFS(int u, int depth)//uΪ��ǰ���ʵĶ����ţ�depthΪ���
	//{
	//	vis[u] = true;//����u�Ѿ�������
	//	//�����Ҫ��u����һЩ�����������������
	//	//��������д�u�����ܵ���ķ�֧�������ö��
	//	for (int v = 0; v < n; v++)
	//	{
	//		if (vis[v] == false && G[u][v] != INF)
	//		{
	//			DFS(v, depth + 1);
	//		}
	//	}
	//}
	//void DFSTrave()//����ͼ
	//{
	//	for (int u = 0; u < n; u++)
	//	{
	//		if (vis[u] == false)
	//		{
	//			DFS(u, 1);//����u��u���ڵ���ͨ�飬1��ʾ��ʼ��Ϊ1��
	//		}
	//	}
	//}
	void DFS(int u, int depth)//u��ʾ��ǰ���
	{
		//����u�Ѿ�������
		vis[u] = true;
		//��u����ز������������

		//����u���������ӵĶ���v
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
		for (int u = 0; u < n; u++)//�����ж������ͨ����з���
		{
			if (vis[u] == false)
			{
				DFS(u, 1);//�����ͼ����ͨͼ����DFSֻ��Ҫ��һ�Σ���Ϊֻ��һ����ͨ��
			}
		}
	}
#endif

#if 0
	//�ڽӱ��
	vector<int> Adj[MAXV];// ͼG���ڽӱ�
	int n;//nΪ��������MAXVΪ��󶥵���
	bool vis[MAXV] = { false };

	//void DFS(int u, int depth)
	//{
	//	vis[u] = true;
	//	//�����Ҫ��u����һЩ�����������ڴ˴�����

	//	for (int i = 0; i < Adj[u].size(); i++)
	//	{
	//		int v = Adj[u][i];//Adj[u][i]��������һ���ڵ�ı��
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
	//			DFS(u, 1);//������ͨ��
	//		}
	//	}
	//}
	void DFS(int u, int depth)
	{
		vis[u] == true;
		//��Ҫ��u���в������������
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
				DFS(u, 1);;//������ǰ��ͨ��
			}
		}
	}
#endif
	//BFS
#if 0
	//�ڽӾ���
	//int n, G[MAXV][MAXV];
	//bool inq[MAXV] = { false };
	//void BFS(int u)//uΪ������
	//{
	//	queue<int> q;
	//	q.push(u);
	//	inq[u] = true;
	//	while (!q.empty())
	//	{
	//		int u = q.front();//ȡ������Ԫ��
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
	//			BFS(u);//��ȷ�����ͨ��
	//		}
	//	}
	//}
	int n, G[MAXV][MAXV];
	int inq[MAXV] = { false };
	void BFS(int u)//uΪ��ǰ������
	{
		queue<int> q;
		q.push(u);
		inq[u] = true;
		while (!q.empty())
		{
			int u = q.front();

			//�����u���в���
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