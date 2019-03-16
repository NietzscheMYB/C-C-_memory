#include <iostream>
#include <algorithm>
using namespace std;

//algorithm
//algorithm
//algorithm
//next_permutation  next_permutation  全排列时必须是升序排序！！！
int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int ans = 0;
int  check(int arr[])
{
	int x = arr[3] * 100 + arr[4] * 10 + arr[5];
	int y = arr[6] * 100 + arr[7] * 10 + arr[8];
	if ((arr[1] * y + arr[2] * x) % (arr[2] * y) == 0 && (arr[0] + ((arr[1] * y + arr[2] * x)/(arr[2] * y))) == 10)
	//if ((arr[1] * y + arr[2] * x) % (y * arr[2]) == 0 && arr[0] + (arr[1] * y + arr[2] * x) / (y * arr[2]) == 10)
	{
		return 1;
	}
	return 0;
}

//递归+回溯  手动生成全排列
void f(int k,int arr[])
{
	if (k == 9)
	{
		if (check(arr))
		{
			ans++;
		}
	}
	for (int i = k; i < 9; i++)
	{
		{ int t = arr[i]; arr[i] = arr[k]; arr[k]=t; }
		f(k + 1,arr);
		{int t = arr[i]; arr[i] = arr[k]; arr[k] = t; }
	}

}

int main()
{
	/*do{
		if (check(arr) == 1)
		{
			ans++;
		}
	} while (next_permutation(arr, arr + 9));*/
	f(0,arr);
	cout << ans << endl;
	return 0;
}