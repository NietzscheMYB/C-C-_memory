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
			if (-arr[i]>x&&arr[i] < 0)    //�ҵ����������ߵ����� �������򿴳����� 
			{
				ans++;
			}
		}
		if (ans != 1)  //˵�����ҵ�������ϱ���Ⱦ
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
			if (arr[i]>0 && arr[i] < -x)  //�ҵ����������ߵ����� ������ð
			{
				ans++;
			}
		}
		if (ans != 1)   //˵���Ѿ�ʹ���������ߵ����ϸ�ð ���ж������ð���ϵĺ���
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