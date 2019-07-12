//#include<iostream>
////namespace关键字，后面跟命名空间的名字
//namespace N
//{
//	//命名空间既可以定义变量，也可以定义函数
//	//也可以嵌套
//	int a = 10;
//	int b = 10;
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//	//命名空间就是开辟一段新的作用3域
//	namespace M
//	{
//		int a = 100;
//	}
//}
//
////命名空间的三种使用方式
////1.加命名空间名称及作用域限定符
////2.使用using将命名空间的成员引入
////3.使用using namespac 命名空间名称引入
//
//using namespace N::M;
////int main()
////{
////	printf("%d\n",N::a);//命名空间名称+作用域限定符（::）对命名空间的成员进行访问
////	printf("%d\n", a);
////	return 0;
////}
//
//
////为了和c头文件进行区分，也为了正确使用命名空间
////规定c++头文件不带.h
//
//
////缺省参数-----备胎
////缺省参数是声明或者定义函数时为函数的参数指定一个默认值
////在调用函数时，没有指定实参则采用该默认值
////否则使用指定的实参
//
////int xx(int x = 1, int y = 1)
////{
////	return x + y;
////}
////
////int main()
////{
////	std::cout << xx() << std::endl;
////	std::cout << xx(22, 323) << std::endl;
////}
//
////缺省参数
////分为全缺省与半缺省
////全缺省指的是所以参数都有指定的值
////半缺省是一些有指定的值
//
//
////半缺省参数必须从右向左依次来给出，不能间隔着给
////缺省参数不能在定义和声明中同时出现
////缺省值必须是常量或者全局变量
//
//
//
//
//
//
//
#include<vector>
#include<iostream>
#include<list>
#include<map>
using namespace std;


int fun2()
{
	int a = 10;
	return a;
}
void test()
{
	//a，b,c,10,fun2返回值
	//左值：既可以出现赋值符号的左边，也可以出现在赋值符号的右边，或者说可以取地址（有争议）
	//右值：只能出现在赋值符号的右边，或者说不是左值的都是右值（有争议）
	

	//右值：常量，临时变量，将亡值（生命周期马上结束）
	//


	int a;
	int b = 10;
	int c = a;
	int d = fun2();
}


int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v1;
	vector<int>v2(10, 1);
	vector<int> v3(a, a + 4);

	//c++11
	vector<int> v = { 1, 2, 3, 4 };
	list<int> lst = { 4, 5, 6, 7 };
	list<int> lst1{ 4, 5, 6, 7 };
	map<int, int> m{ { 1, 1 }, { 2, 2 }, { 3, 3 } };


	decltype(1 + 2)  a;//运行时确定类型

	//final:定义类：不能被继承的类
	//final:定义函数，函数不能被重写，实现继承
	//虚函数+override：子类必须重写父类的一个虚函数，接口继承

	//委派构造函数 ，构造函数直接可以调用，减少代码冗余
	//用了委派的构造函数，就不能成员初始化了
	//强制编译器生成一个默认构造
	//c()=default;

	//强制编译器不生产拷贝构造，防拷贝
	//c(const c&c) delete;
	//c&operator=(const C& c)=delete;
	return 0;
}





