#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n,-1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int left = 0, right = 0;
	int ans = 0;
	for (left = 0; left < n; left++)
	{
		int minHeigh = v[left];
		for (right = left; right < n; right++)
		{
			minHeigh =min(minHeigh, v[right]);
			ans = max(ans, (right - left + 1)*minHeigh);
		}
	}
	cout << ans << endl;
}