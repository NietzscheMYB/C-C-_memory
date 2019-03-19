#include <iostream>
#include <cstring>
using namespace std;
int ans = 0;
int dire[][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
int vis[7][7];

void dfs(int x, int y)
{
	if (x == 0 || y == 0 || x == 6 || y == 6)
	{
		ans++;
		return;
	}
	//��ǰ�ĵ���Ϊ�Է���
	vis[x][y] = 1;
	//�ԳƵ�Ҳ������
	vis[6 - x][6 - y] = 1;

	for (int k = 0; k < 4; ++k)
	{
		int nx = x + dire[k][0];
		int ny = y + dire[k][1];
		//������
		if (nx<0 || nx>6 || ny<0 || ny>6)
		{
			continue;
		}
		if (!vis[nx][ny])
		{
			dfs(nx,ny);
		}
	}
	vis[x][y] = 0;
	vis[6 - x][6 - y] = 0;//����Ϊ0��
}

int main()
{
	memset(vis, 0, sizeof(vis));
	dfs(3, 3);
	cout << ans / 4 << endl;
	return 0;
}