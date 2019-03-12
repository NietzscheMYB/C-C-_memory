#include <iostream>
using namespace std;
class MyClass
{
public:
	MyClass(int x=0,int y=0)
	{
		_x = x;
		_y = y;
	}
	void Display1()
	{
		printf("%d %d\n", _x, _y);
	}
	void Display2()
	{
		printf("%d\n", _x+_y);
	}

private:
	int _x;
	int _y;
};
int main()
{
	MyClass my1(3, 5);
	my1.Display1();
	my1.Display2();

	MyClass my2;
	my2.Display1();
	my2.Display2();

	return 0;
}