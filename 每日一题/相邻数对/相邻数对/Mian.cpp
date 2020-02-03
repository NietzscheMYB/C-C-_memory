#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] - v[i - 1] == 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;


}