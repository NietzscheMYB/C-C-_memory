#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] != '-')
		{
			v.push_back(s[i] - '0');
		}
	}
	int k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		 k+= v[i] * arr[i];
	}
	
	k%= 11;

	char sum;
	if (k == 10)
	{
		sum = 'X';
	}
	else{
		sum = k +'0';
	}
	if (sum == s[s.size() - 1])
	{
		cout << "Right" << endl;
	}
	else{
		for (int i = 0; i < s.size() - 1; i++)
		{
			cout << s[i];
		}
		cout << sum << endl;
	}
	return 0;
}