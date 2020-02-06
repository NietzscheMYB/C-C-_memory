#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100;//��Ʒ������
const int maxv = 1000;//v������
int w[maxn], c[maxn], dp[maxn][maxv];




//01����
//int main()
//{
//	int n, V;
//	cin >> n >> V;
//	for (int i = 1; i <=n; i++)
//	{
//		cin >> w[i];
//	}
//	for (int i = 1; i <=n; i++)
//	{
//		cin >> c[i];
//	}
//
//	for (int i = 0; i <= V; i++)
//	{
//		dp[0][i] = 0;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int v = w[i]; v <= V; v++)
//		{
//			dp[i][v] = max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (ans < dp[i][V])
//		{
//			ans = dp[i][V];
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//��ȫ����
int main()
{
	int n, V;
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}

	for (int i = 1; i <=V; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int v = w[i]; v <= V; i++)
		{
			dp[i][v] = max(dp[i-1][v],dp[i][v-w[i]]+c[i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans < dp[i][V])
		{
			ans = dp[i][V];
		}
	}

	cout << ans << endl;


	return 0;
}