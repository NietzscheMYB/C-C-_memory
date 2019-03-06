#include <iostream>
using namespace std;
int main()
{
	int  n;
	cin >> n;
	int  arr[50]={0};
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int x = arr[0];
	if (x>0)
	{
		int ans = 1;
		for (i = 0; i < n; i++)
		{
			if (-arr[i]>x&&arr[i] < 0)    //找到从右向左走的蚂蚁 相遇反向看出穿过 
			{
				ans++;
			}
		}
		if (ans != 1)  //说明从右到左的蚂蚁被感染
		{
			for (i = 0; i < n; i++)
			{
				if (arr[i]>0&&arr[i]<x)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (x < 0)
	{
		int ans = 1;
		for (i = 0; i < n; i++)
		{
			if (arr[i]>0 && arr[i] < -x)  //找到从左向右走的蚂蚁 让它感冒
			{
				ans++;
			}
		}
		if (ans != 1)   //说明已经使从左向右走的蚂蚁感冒 再判断最初感冒蚂蚁的后面
		{
			for (i = 0; i < n; i++)
			{
				if (arr[i]<0 && -arr[i]>-x)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	
}