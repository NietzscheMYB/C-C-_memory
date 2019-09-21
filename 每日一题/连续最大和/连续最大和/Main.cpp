//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	vector<int> v;
//	cin >> n;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	int sum1 = 0, sum2 = 0, result = v[0];
//
//	//sum[i]=max(sum[i-1],0)+v[i];//i是当前的最大值 它等于i-1的最大值加上i的值
//	for (int i = 0; i < v.size(); i++)
//	{
//		sum2 = sum1>=0 ? sum1 + v[i] : v[i];
//		if (sum2>result)
//		{
//			result = sum2;
//		}
//		if (sum2 < 0)
//		{
//			sum2 = 0;
//		}
//		sum1 = sum2;
//	}
//
//	cout << sum2 << endl;
//
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
int main() 
{
	int size;    
	cin >> size;    
	vector<int> nums(size);    
	for (size_t i = 0; i < size; ++i)        
		cin >> nums[i];       
	int result = nums[0];    
	int sum1 = 0, sum2 = 0;    
	for (int i = 0; i < nums.size(); i++)    
	{       // 计算到num[i]的子数组的最大和       
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];       
		if(sum2 > result)           
			result = sum2; 

		if (sum2 < 0)           
			sum2 = 0;                
		sum1 = sum2;
	}       
	cout << result << endl;         
	return 0;
}