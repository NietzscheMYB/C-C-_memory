#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


int minDis(string s1, string s2)
{
	if (s1.empty() || s2.empty())
	{
		return max(s1.size(), s2.size());
	}
	if (s1.size() > s2.size())
	{
		swap(s1, s2);
	}
	vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, 0));

	for (int i = 0; i <= s1.size(); i++)
	{
		v[i][0] = i;
	}
	
	for (int i = 0; i <= s2.size(); i++)
	{
		v[0][i] = i;
	}

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				v[i][j] = 1 + min(v[i][j - 1], v[i - 1][j]);

				v[i][j] = min(v[i][j],v[i-1][j-1]);
			}
			else{
				v[i][j] = 1 + min(v[i][j-1],v[i-1][j]);

				v[i][j] = min(v[i][j], 1 + v[i - 1][j - 1]);
			}
		}
	}


	return v[s1.size()][s2.size()];

}


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << minDis(s1, s2) << endl;
	}
	return 0;
}