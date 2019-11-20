#include<iostream>
#include<vector>
using namespace std;
int func(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int arr[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int year, month, day;
	while (cin >> year >> month >> day)
	{	
		if (month > 12 || month < 1)
		{
			cout << -1 << endl;
			return 0;
		}
		int ret = func(year);
		int num = 0;
		num += arr[month - 2] + day;
		if (month>2 && ret == 1)
		{
			num++;
			cout << num << endl;
			return 0;
		}
		cout << num << endl;
		return 0;
	}
}