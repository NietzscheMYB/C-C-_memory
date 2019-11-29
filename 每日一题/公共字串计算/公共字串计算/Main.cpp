#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size())
	{
		swap(s1, s2);
	}
	
	int len1 = s1.size();
	int len2 = s2.size();

	vector<vector<int>> v(len1+1, (vector<int>(len2+1,0)));
	
	int i = 1, j = 1;
	int maxlen = 0;
	for (i = 1; i <=len1; i++)
	{
		for (j = 1; j <=len2; j++)
		{

			if (s1[i] == s2[j])
			{
				v[i][j] = v[i - 1][j - 1] + 1;

			}
			if (maxlen < v[i][j])
			{
				maxlen = v[i][j];
			}
		}
	}
	cout << maxlen << endl;

}