#include<iostream>
#include<string>
using namespace std;
class MyClass
{
public:
	MyClass(string s)
	{
		_s = s;
	}
	~MyClass()
	{}
	void Deal()
	{
		string s1;
		for (int i = 0; i < _s.size(); i++)
		{
			if (_s[i] >= 'F'&&_s[i] <= 'Z')
			{
				s1 += _s[i] - 5;
				continue;
			}
		/*	if (_s[i] == 'A')
			{
				s1 += 'V';
				continue;

			}
			if (_s[i] == 'B')
			{
				s1 += 'W';
				continue;
			}
			if (_s[i] == 'C')
			{
				s1 += 'X';
				continue;
			}
			if (_s[i] == 'D')
			{
				s1 += 'Y';
				continue;
			}
			if (_s[i] == 'E')
			{
				s1 += 'Z';
				continue;
			}
			s1 += _s[i];*/
			if (_s[i] >= 'A'&&_s[i] <= 'E')
			{
				s1 += _s[i] +21;
				continue;
			}
			s1 += _s[i];
		}
		cout << s1 << endl;
	}
private:
	string _s;
};

int main()
{
	string x;
	while (getline(cin, x))
	{
		MyClass xx(x);
		xx.Deal();
	}
	return 0;
}

