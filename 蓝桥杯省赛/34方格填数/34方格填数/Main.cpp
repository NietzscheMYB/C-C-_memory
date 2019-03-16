#include <iostream>
#include<math.h>
#include <algorithm>
using namespace std;
int arr[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
int ans = 0;
int check(int arr[])
{
	if (abs(arr[0] - arr[1]) == 1 || (abs(arr[0] - arr[3]) == 1) || abs(arr[0] - arr[4]) == 1 || abs(arr[0] - arr[5]) == 1 ||
		abs(arr[1] - arr[2]) == 1 || (abs(arr[1] - arr[4]) == 1) || abs(arr[1] - arr[5]) == 1 || abs(arr[1] - arr[6]) == 1 ||
		abs(arr[2] - arr[5]) == 1 || (abs(arr[2] - arr[6]) == 1) ||
		abs(arr[3] - arr[4]) == 1 || (abs(arr[3] - arr[7]) == 1) || abs(arr[3] - arr[8]) == 1 ||
		abs(arr[4] - arr[0]) == 1 || (abs(arr[4] - arr[1]) == 1) || abs(arr[4] - arr[3]) == 1 || abs(arr[4] - arr[5]) == 1 ||
		abs(arr[4] - arr[7]) == 1 || (abs(arr[4] - arr[8]) == 1) || abs(arr[4] - arr[9]) == 1 ||
		abs(arr[5] - arr[1]) == 1 || (abs(arr[5] - arr[6]) == 1) || abs(arr[5] - arr[8]) == 1 || abs(arr[5] - arr[9]) == 1 ||
		abs(arr[6] - arr[9]) == 1 ||
		(abs(arr[7] - arr[8]) == 1) ||
		abs(arr[8] - arr[9]) == 1)
	{
		return 0;
	}
	return 1;

}
//void f(int k,int arr[])
//{
//	if (k == 10)
//	{
//		if (check(arr))
//		{
//			ans++;
//		}
//		return;
//	}
//	for (int i = k; i < 10; i++)
//	{
//		{
//			int t = arr[i];
//			arr[i] = arr[k];
//			arr[k] = t;
//		}
//		f(k + 1, arr);
//		{
//			int t = arr[i];
//			arr[i] = arr[k];
//			arr[k] = t;
//		}
//	}
//
//}

int main()
{
	//f(0, arr);
	do{
		if (check(arr))
		{
			ans++;
		}
	} while (next_permutation(arr,arr+10));

	cout << ans << endl;
	return 0;
}