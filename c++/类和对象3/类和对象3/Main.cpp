#include <iostream>
using namespace std;
class A
{
public:
	A(){ ++_scount; }
	A(const A&t)
	{
		++_scount;
	}
	static int GetACount()
	{
		return _scount;
	}
private:
	static int _scount;
};

int A::_scount = 0;

void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
	
	
}
int main()
{
	TestA();
}


//友元函数可以直接访问类的私有成员，他是定义在类外部的普通函数，不属于任何类
//但需要在类 的内部声明，声明时需要+friend关键字
//友元函数可以访问类 的私有成员，但不是类的成员函数
//友元函数不能被const修饰
//友元函数可以在类定义的任何地方声明，不受类访问限定符限制
//一个函数可以是多个类的友元函数
//友元函数的调用与普通函数的调用和原理相同
