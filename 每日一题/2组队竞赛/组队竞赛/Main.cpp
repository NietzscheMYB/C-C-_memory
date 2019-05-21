//#include <iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	//Ì°ÐÄËã·¨
//	int n;
//	while (cin >> n)
//	{
//		long long sum = 0;
//		vector<int> a;
//		a.resize(3 * n);
//		for (int i = 0; i < 3 * n; i++)
//		{
//			cin >> a[i];
//		}
//		sort(a.begin(), a.end());
//		int k = n;
//		int x = a.size() - 1;
//		while (n)
//		{
//			sum += a[x - 1];
//			x -= 2;
//			n--;
//		}
//		cout << sum << endl;
//	}
//
//	return 0;
//}
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		vector<int> arr;
		arr.resize(3 * n);
		for (int i = 0; i < arr.size(); i++)
		{
			//int x = 0;
			cin >> arr[i];
			//arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		int y = n;
		long long sum = 0;
		int index = arr.size()-1;
		while (y)
		{
			sum += arr[index - 1];
			index -= 2;
			y--;
		}
		cout << sum << endl;
	}
	return 0;
}