//X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。
//地宫的入口在左上角，出口在右下角。
//小明被带到地宫的入口，国王要求他只能向右或向下行走。
//走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。
//当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。
//请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。
//【数据格式】
//输入一行3个整数，用空格分开：n m k(1 <= n, m <= 50, 1 <= k <= 12)
//接下来有 n 行数据，每行有 m 个整数 Ci(0 <= Ci <= 12)代表这个格子上的宝物的价值
//要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。
//例如，输入：
//2 2 2
//1 2
//2 1
//程序应该输出：
//2
//再例如，输入：
//2 3 2
//1 2 3
//2 1 5
//程序应该输出：
//14


#include <iostream>
#include <cstring>
using namespace std;
int arr[50][50] = { 0 };
int n, m, k;
int count = 0;
//int ans = 0;
int MOD = 1000000007;
//void dfs(int x, int y, int max, int count)    //深度优先搜索
//{
//	if (x == n || y == m)
//	{
//		return;
//	}
//	int cur = arr[x][y];
//	if (x == n - 1 && y == m - 1) //到达终点
//	{
//		if (count == k)
//		{
//			ans++;
//			if (ans > MOD)
//			{
//				ans %= MOD;
//			}
//
//		}
//		if (count == k - 1&&cur>max)
//		{
//			ans++;
//			if (ans > MOD)
//			{
//				ans %= MOD;
//			}
//		}
//	}
//
//	if (cur > max) //拿宝贝
//	{
//		dfs(x + 1, y, cur, count + 1);
//		dfs(x, y + 1, cur, count + 1);
//	}
//	//不想拿宝贝或者cur<max
//	dfs(x + 1, y, max, count );
//	dfs(x, y + 1, max, count );
//}
long long cachae[50][50][14][13];

long long dp(int x, int y, int max, int count)//动态规划 记忆性递归
{
	if (cachae[x][y][max+1][count] != -1)
	{
		return cachae[x][y][max + 1][count];
	}
	if (x == n || y == m)
	{
		return 0;
	}
	
	
	long long  ans = 0;
	int cur = arr[x][y];
	if (x == n - 1 && y == m - 1)   //到达最后一个为置
	{
		if (count == k)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return ans;
		}
		if (count == k - 1 && cur > max)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return ans;
		}
	}
	
	if (cur > max)             //当前位置宝贝贵 拿上
	{
		ans+=dp(x + 1, y, cur, count + 1);
		ans+=dp(x, y + 1, cur, count + 1);
	}
	//不想拿宝贝 或者 位置宝贝价值小
	ans+=dp(x + 1, y, max, count);
	ans+=dp(x, y + 1, max, count);
	cachae[x][y][max+1][count] = ans%MOD;
	return ans;

}
int main()
{
	cin >> n;
	cin >> m;
	cin >> k;
	int i = 0,j=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(cachae, -1, sizeof(cachae));
	cout <<dp(0, 0, -1, 0)<< endl;
}