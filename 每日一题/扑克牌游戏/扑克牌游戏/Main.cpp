#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string line;

	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
		}
		else{
			string s1, s2;
			int index = line.find('-');
			s1 = line.substr(0, index);
			s2 = line.substr(index + 1);

			int c1 = count(s1.begin(), s1.end(), ' ');//统计空格数，排的总数为空格数+1，即c1+1
			int c2 = count(s2.begin(), s2.end(), ' ');

			string first1 = s1.substr(0, s1.find(' '));
			string first2 = s2.substr(0, s2.find(' '));
			string str = "345678910JQKA2jokerJOKER";

			if (c1 == c2)
			{
				if (str.find(first1)>str.find(first2))
				{
					cout << s1 << endl;
				}
				else{
					cout << s2 << endl;
				}
			}
			else{//二者不等于的情况
				if (c1 == 3) //s1是炸弹
				{
					cout << s1 << endl;
				}
				else if (c2 == 3){//s2是炸弹
					cout << s2 << endl;
				}
				else{
					cout << "ERROR" << endl;
				}
			}

		}
	}
	return 0;
}