//#include<iostream>
//using namespace std;
//class A{
//public:
//	A()
//	{
//		count++;
//	}
//	A(const A& x)
//	{
//		count++;
//	}
//	~A()
//	{}
//	static int count;
//private:
//	int a;
//};
//int A::count = 0;
//int main()
//{
//	A a, b, c;
//	A d(c);
//	cout << a.count << endl;
//}

#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		count++;
	}
	A(const A& x)
	{
		count++;
	}
	 static int GetCount()
	{
		return count;
	}
private:
	static int count;
};
int A::count = 0;
int main()
{
	A a, b, c;
	A d(c);
	cout << a.GetCount()<< endl;
	return 0;
}
