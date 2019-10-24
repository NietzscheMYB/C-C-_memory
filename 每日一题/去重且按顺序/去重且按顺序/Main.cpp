#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	while (cin >> s)
	{
		for (int i = 0; i<s.size(); i++)
		{
			arr1[s[i] - '0']++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			arr2[i] = s[i] - '0';
		}
		for (int i = 0; i<s.size(); i++)
		{

			if ((arr1[arr2[i]])>0)
			{
				arr1[arr2[i]] = 0;
				cout << s[i];
			}
		}
		cout << endl;
	}

	return 0;
}