#include<iostream>
#include<stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> v;
		for (auto x : A)
		{
			switch (x)
			{
			case '(':v.push(x); break;
			case ')':{
						 if (v.empty() || v.top() != '(')
						 {
							 return false;
						 }
						 else{
							 v.pop();
						 }
			}break;
			default:
				return false;
			}
		}
		return true;

	}
};

int main()
{

	return 0;
}