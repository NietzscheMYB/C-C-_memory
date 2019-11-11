#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
using namespace std;


/*在保证初始代码结构不变的情况下，可以通过下面“arraySort”一个函数实现题目的要求，也可以通过多个函数实现*/

/*=============这里往下是你主要编写代码的地方，此区域外的代码都不能删除==================*/

/*入口函数，不能删除，因为在下方有调用*/
vector < int > arraySort(vector < int > arr) {
	vector<int>temp(arr);
	sort(temp.begin(),temp.end());
	return temp;

}
/*其他函数可以从这里写起*/

/*=============这里往上是你主要编写代码的地方，此区域外的代码都不能删除==================*/



int main() {
	vector < int > res;

	int _arr_size = 0;
	cin >> _arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _arr;
	int _arr_item;
	for (int _arr_i = 0; _arr_i<_arr_size; _arr_i++) {
		cin >> _arr_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_arr.push_back(_arr_item);
	}



	res = arraySort(_arr);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << endl;;
	}

	return 0;

}
#endif


#if 0

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
using namespace std;


/*在保证初始代码结构不变的情况下，可以通过下面“char_count”一个函数实现题目的要求，也可以通过多个函数实现*/

/*=============这里往下是你主要编写代码的地方，此区域外的代码都不能删除==================*/

/*入口函数，不能删除，因为在下方“main”函数中有调用*/
string char_count(string str) {
	string temp;
	int count = 0;
	int i = 1;
	for ( i = 1; i < str.size(); i++)
	{
		if (str[i - 1] == str[i])
		{
			count++;
		}
		else{
			temp += count+1+'0';
			temp += str[i - 1];
			count = 0;
		}
	}
	temp += count+1 + '0';
	temp += str[i - 1];
	return temp;
	
}
/*其他函数可以从这里写起*/

/*=============这里往上是你主要编写代码的地方，此区域外的代码都不能删除==================*/


int main() {
	string res;

	string _str;
	getline(cin, _str);

	res = char_count(_str);
	cout << res << endl;

	return 0;

}
#endif


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
	vector<vector<int>> sum;
	sum.resize(size);
	for (int i = 0; i < sum.size(); i++)
	{
		sum[i].resize(size);
	}
	for (int i = 0; i < sum.size(); i++)
	{
		for (int j = 0; j < sum[i].size(); j++)
		{
			sum[i][j] = 0;
		}
	}
	for (int i = 0; i < sum.size(); i++)
	{
		for (int j = i; j < sum[i].size(); j++)
		{
			if (i == j)
			{
				sum[i][j] = nums[j];
				continue;
			}
			sum[i][j] = sum[i][j - 1] + nums[j];
		}
	}
	int max = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		for (int j = i; j < sum[i].size(); j++)
		{
			if (max<sum[i][j])
			{
				max = sum[i][j];
			}
		}
	}
	cout << max << endl;

	return 0;
}