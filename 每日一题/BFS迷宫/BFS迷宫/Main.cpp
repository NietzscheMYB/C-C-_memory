#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int maxn = 100;
struct node{
	int x, y;//λ��x��y
	int step;//step Ϊ����㵽���λ�õ����ٲ���(������)
}S,T,Node;

int n, m;//nΪ�� mΪ��
char maze[maxn][maxn]; 
bool inq[maxn][maxn] = { false };//��¼λ��x��y�Ƿ����
int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };

//���λ��x��y�Ƿ���Ч
bool test(int x, int y)
{
	//���Խ��
	if (x >= n || x < 0 || y >= m || y < 0){ return false; }
	//���ǽ��
	if (maze[x][y] == '*'){ return false; }
	//����Ƿ����
	if (inq[x][y] == true){ return false; }
	//��Чλ��
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
				//����Node���� newx��newy
				Node.x = newx;
				Node.y = newy;
				Node.step = top.step + 1;//Node��Ϊtop��+1
				q.push(Node);
				inq[newx][newy] = true; //����λ��newx newy �����
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