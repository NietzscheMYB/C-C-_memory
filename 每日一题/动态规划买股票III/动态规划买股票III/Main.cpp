#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int dp[30000][3][2] = { 0 };
		for (int i = 0; i <= prices.size(); i++)
		{
			dp[i][0][0] = 0;
			dp[i][0][1] = -1000;
			for (int k = 2; k >= 1; k--)
			{
				if (i == 0)
				{
					dp[i][k][0] = 0;
					dp[i][k][1] = -100000;
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i - 1]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i - 1]);
			}
		}
		return dp[prices.size()][2][0];
	}
};


int main()
{
	return 0;
}