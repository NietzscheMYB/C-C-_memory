#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	double arr[30][30];
	int i, j;
	memset(arr, 0.0, sizeof(arr));
	for (i = 0; i < 29; i++)
	{
		for (j = 0; j <= i; j++)
		{
			//scanf("%llf", &arr[i][j]);
			cin >> arr[i][j];
		}
	}
	//double half = arr[0][0];
	for (i = 1; i <=29; i++)
	{
		
		for (j = 0; j <= i; j++)
		{	
			if (j == 0)
			{
				arr[i][j] += arr[i - 1][j] / 2.0;
			}
			else
			{
				arr[i][j] += (arr[i - 1][j - 1] + arr[i - 1][j]) / 2.0;
			}
		}
	}
	double max = 0, min = 9999999;
	for (i = 0; i <= 29; i++)
	{
		if (arr[29][i]<min)
			min = arr[29][i];
		if (arr[29][i]>max)
			max = arr[29][i];
	}
	//printf("%lf\n", 2086458231 / min*max);*/
	//sort(arr[29], arr[29] + 30);
	cout << arr[29][0] << " " << arr[29][29] << endl;
	return 0;
}