#include<iostream>
#include<algorithm>
using  namespace std;

const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> f[i][j];
		}
	}

	//±ß½ç
	for (int j = 1; j <= n; j++)
	{
		dp[n][j] = f[n][j];
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i >= 1 && i <= n&&j >= 1 && j <= n)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
			}
		}
	}
	cout << dp[1][1] << endl;

}