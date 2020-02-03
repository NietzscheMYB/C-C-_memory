#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//vector<vector<int>> v(105, vector<int>(105, 0));
	int v[105][105];
	for (int i = 0; i < 105; i++)
	{
		//sum += count(v[i],v[i]+105, 1);
		for (int j = 0; j < 105; j++)
		{
			v[i][j] = 0;
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				v[i][j] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 105; i++)
	{
		 //sum += count(v[i],v[i]+105, 1);
		for (int j = 0; j < 105; j++)
		{
			if (v[i][j] == 1)
			{
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}