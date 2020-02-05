#include<iostream>
#include<string>
using namespace std;
const int N = 700;


bool fun1(int n)
{
	return n % 7 == 0;
}

bool fun2(int n)
{
	while (n)
	{
		int tem = n % 10;
		if (tem == 7)
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	int a=0, b=0, c=0, d=0;
	int fa=0, fb=0, fc=0, fd=0;
	int count = 0;
	int flag = 0;
	while (flag != n)
	{
		count++;
		flag++;
		if (fun1(count) || fun2(count))
		{
			flag--;
			int x = count % 4;
			if (x == 1)
			{
				fa++;
			}
			else if (x == 2)
			{
				fb++;
			}
			else if (x == 3)
			{
				fc++;
			}
			else if (x == 0)
			{
				fd++;
			}
		}
	}


	std::cout<< fa << endl << fb << endl << fc << endl << fd << endl;
	return 0;
}