#include <iostream>
#include <string>
using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//	/*	int i = 0;
//		if (num1.length() >= num2.length())
//		{
//			i = num1.length();
//		}
//		else
//		{
//			i = num2.length();
//		}
//		int j = 0, tmp = 0, wei = 0, flag = 0;
//		string s;
//		for (j = 0; j<i; j++)
//		{
//			tmp = num1[j] - '0' + num2[j] - '0' + wei;
//			if (tmp>9)
//			{
//				wei = tmp - 10;
//			}
//			else
//			{
//				wei = 0;
//			}
//			tmp = tmp / 10;
//		}*/
//		int len1 = num1.size() - 1;
//		int len2 = num2.size() - 1;
//		int step = 0,sum=0;
//		string ret = "";
//		while (len1 >= 0 || len2 >= 0)
//		{
//			sum = 0;
//			//当前位的和 : num1[len1]+num2[lne2]+step
//			sum += step; //现加上一位的进位
//			if (len1 >= 0)
//			{
//				sum += num1[len1]-'0';
//			}
//			if (len2 >= 0)
//			{
//				sum += num2[len2]-'0';
//			}
//			//获取当前为的值
//			if (sum > 9)
//			{
//				sum -= 10;//减比模效率高
//				//更新进位
//				step = 1;
//			}
//			else
//			{
//				step = 0;
//			}
//			//当前位置的值保存到字符串中 头插
//			ret.insert(0, 1, sum + '0');  //在0的位置插入一个字符！！！
//			//计算下一位
//			len1--;
//			len2--;
//		}
//		if (step == 1)
//		{
//			ret.insert(0, 1, '1');
//		}
//		return ret;
//	}
//};
//int main()
//{
//	Solution s;
//	string s1;
//	string s2;
//	while (cin>>s1>>s2)
//	{
//		cout << s.addStrings(s1, s2) << endl;
//	}
//	return 0;
//}
