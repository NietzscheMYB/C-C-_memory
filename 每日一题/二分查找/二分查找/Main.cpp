#include<iostream>
using namespace std;
bool BinarySearch(int arr[],int left,int right,int n)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//防止溢出！！！如果是right+left时，可能会很多造成溢出！！
		if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else if (arr[mid] == n)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i <= 15; i++)
	{
		if (BinarySearch(arr, 0, 9, i))
		{
			cout << "查找成功" << i<<endl;
		}
		else{
			cout << "查找失败" << i<<endl;
		}
	}
	return 0;
}