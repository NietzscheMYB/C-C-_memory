#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	int flag = 0;
	int x = 0, y = 0;
	vector<vector<int>> tem(2*n-1, vector<int>());
	for (int i = 0; i <n - 1; i++)
	{
		x = 0;
		y = i;
		while (x >= 0 && y >= 0 && x < n && y < n)
		{
			tem[flag].push_back(v[x][y]);
			x++;
			y--;
		}
		flag++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		x = n-i-1;
		y = n-1;
		while (x >= 0 && y >= 0 && x < n && y < n)
		{
			tem[flag].push_back(v[x][y]);
			x++;
			y--;
		}
		flag++;
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j <tem[i].size(); j++)
			{
				if (tem[i][j] != -1)
				{
					cout << tem[i][j] << " ";
				}
			}
		}
		else{
			for (int j = tem[i].size()-1; j >= 0; j--)
			{
				if (tem[i][j] != -1)
				{
					cout << tem[i][j] << " ";
				}
			}
		}
	}


	return 0;

}