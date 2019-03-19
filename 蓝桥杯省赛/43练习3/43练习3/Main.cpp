#include <iostream>
#include <cstring>
using namespace std;
int ans = 0;
int arr[50][50];
//int max = -1;
int n=0, m=0,num=0;
#define MOD 1000000007
void dfs(int x, int y,int max,int k)
{	
	if (x >= n || y >= m||k>num)
	{
		return;
	}
	int cur = arr[x][y];
	if ((x == n-1 && y == m-1))
	{
		if (num == k)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return;
		}
		else if (num == k - 1 && cur > max)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return;
		}
	}
	if (cur > max)
	{
		   //拿物品
		dfs(x, y + 1,cur,k+1);
		dfs(x + 1, y,cur,k+1);
	}
	dfs(x, y + 1,max, k);
	dfs(x+1,y,max, k);//如果价值小或者不拿
	
}
int main()
{
	memset(arr, -1, sizeof(arr));
	cin >> n >> m >> num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, 0, -1,0);
	//max = arr[0][0];
	cout << ans << endl;
	return 0;
}