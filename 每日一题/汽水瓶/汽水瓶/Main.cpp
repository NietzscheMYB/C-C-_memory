#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 11;
	vector<int> v;
	v.resize(n);
	for (int j = 0; j < v.size(); j++)
	{
		while (cin >> v[j])
		{
			for (int i = 0; i < v.size() && v[i] != 0; i++)
			{
				int ans = 0;
				int count = v[i];
				while (count >= 3)
				{
					if (count % 3 == 0)
					{
						ans += count / 3;
						count = count / 3;
					}
					else{
						ans += count / 3;
						int x = count % 3;
						count = count / 3+x;
					}
				}
				if (count == 2)
				{
					ans++;
				}
				cout << ans << endl;
			}
		}
		v.clear();
		j = 0;
	}


	return 0;
}