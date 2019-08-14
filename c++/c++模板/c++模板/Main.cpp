//#include<iostream>
//using namespace std;
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}

#include<iostream>
using namespace std;
template<class T>
T add(const T& left,const T& right)
{
	return left + right;
}


//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	add(a1, a2);
//	add(d1, d2);
//
//	/*
//	add(a1,d1);
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型，通过实参a1将T推演为int，通过实参
//	d1将T推演为double类型，但模板参数列表中只有一个T。编译器无法确定此处到底将T确定为int或是double而报错
//	*/
//
//	add(a1, (int)d1);
//	return 0;
//}

int main()
{
	int a1 = 2, a2 = 3;
	double b1 = 3.3;
	add<int>(a1, b1);//显示实例化
	return 0;
}