#include<iostream>
#include<string>
#include<vector>
using namespace std;
int fun(string& s)
{
	int count = 0;
	int index = s.rfind(' ');
	count = s.size() - index - 1;
	return count;
}
int main()
{
	string s;
	getline(cin, s);
	cout << fun(s) << endl;
	return 0;
}