#include <iostream>
using namespace std;

int division(int a, int b)
{
	if (b == 0)
	{
		//throw "sdjwod";//改变这个 对应不同的catch
		//throw 5;
		throw 'c';
	}
	return a / b;
}

void fun()
{
	try
	{
		division(10, 0);
	}
	catch (const char *str)
	{
		cout << str << endl;
	}
}

int main()
{
	try{
		fun();
	}
	
	catch (int n)
	{
		cout << "heheheej" << endl;
	}
	catch (...)
	{
		cout << "meiyl" << endl;
	}
	cout << "heh" << endl;
	return 0;
}

