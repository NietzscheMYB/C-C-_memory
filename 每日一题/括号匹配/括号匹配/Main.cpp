#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(3000);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	int min = abs(n - v[0]);
	for (int i = 0; i < v.size(); i++)
	{
		if (min > abs(n - v[i]))
		{
			min = abs(n - v[i]);
		}
	}
	cout << min << endl;
	return 0;
}
 


#if 0
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		vector<char> v;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] != '('&&A[i] != ')')
			{
				return false;
			}
			if (A[i] == '(')
			{
				v.push_back(A[i]);
				continue;
			}
			if (A[i] == ')')
			{
				if (!v.empty())
				{
					char temp = v.back();
					if (temp == '(')
					{
						v.pop_back();
					}
					else {
						return false;
					}
				}
				else{
					return false;
				}

			}
		}
		return true;
	}
};
#endif



