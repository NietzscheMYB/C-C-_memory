#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; v[i] <= 0; i++)
	{
		if (binary_search(v.begin(), v.end(), -v[i]))
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}