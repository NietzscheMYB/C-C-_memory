#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//最长不下降子序列LIS
//const int N = 100;
//int A[N], dp[N];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <=n; i++)
//	{
//		cin >> A[i];
//	}
//	int ans = -1;
//	for (int i = 1; i <= n; i++)
//	{
//		dp[i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			if (A[i] >= A[j] && dp[j] + 1>dp[i])
//			{
//				dp[i] = dp[j] + 1;
//				//dp[i] =max(dp[i],dp[j] + 1);
//			}
//		}
//		ans = max(ans, dp[i]);
//	}
//	cout << ans;
//	
//}

//最长公共字串(可以不连续)
const int N = 100;
//char A[N],B[N];
int dp[N][N]; //dp[i][j] 表示字符串A的i号位和字符串B的j号位之前的LCS长度

void test()
{
	string A;
	string B;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 0; j < B.size(); j++)
	{
		dp[0][j] = 0;
	}
	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i-1]== B[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout <<dp[A.size()][B.size()] << endl;

}
int main()
{
	test();
	return 0;
}
