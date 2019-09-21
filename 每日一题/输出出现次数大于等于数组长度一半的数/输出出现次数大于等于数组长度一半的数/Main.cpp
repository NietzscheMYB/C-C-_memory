#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> v;
	v.resize(101); 

	string s;
	getline(cin, s); 
	int count = 0;
	int flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			v[s[i] - '0']++;
			count++;
		}
		else
		{
			continue;
		}
	}
	int len = 0;
	int index = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (len < v[i])
		{
			len = v[i];
			index = i;
		}
		
	}
	if (v[index] >= (count / 2))
	{
		cout << index << endl;
	}
	return 0;
}

