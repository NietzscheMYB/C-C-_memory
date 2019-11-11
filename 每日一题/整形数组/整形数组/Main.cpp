#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
using namespace std;


/*�ڱ�֤��ʼ����ṹ���������£�����ͨ�����桰arraySort��һ������ʵ����Ŀ��Ҫ��Ҳ����ͨ���������ʵ��*/

/*=============��������������Ҫ��д����ĵط�����������Ĵ��붼����ɾ��==================*/

/*��ں���������ɾ������Ϊ���·��е���*/
vector < int > arraySort(vector < int > arr) {
	vector<int>temp(arr);
	sort(temp.begin(),temp.end());
	return temp;

}
/*�����������Դ�����д��*/

/*=============��������������Ҫ��д����ĵط�����������Ĵ��붼����ɾ��==================*/



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


/*�ڱ�֤��ʼ����ṹ���������£�����ͨ�����桰char_count��һ������ʵ����Ŀ��Ҫ��Ҳ����ͨ���������ʵ��*/

/*=============��������������Ҫ��д����ĵط�����������Ĵ��붼����ɾ��==================*/

/*��ں���������ɾ������Ϊ���·���main���������е���*/
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
/*�����������Դ�����д��*/

/*=============��������������Ҫ��д����ĵط�����������Ĵ��붼����ɾ��==================*/


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