#include<iostream>
using namespace std;

#if 0
int main()
{
	//右值引用---->引用形式---->只能引用右值！！
	//等号左边，称为左值
	//能放在等号左边的一定称为左值
	//能放在等号右边的不一定称为右值
	//一般情况 常量称为右值

	int&& ra = 10;//右值引用的方式，ra是10的别名

	return 0;
}
#endif
void test()
{
	const int a = 10;
	const int &&ra = a;//报错，右值不能引用左值 a，被当成左值对待

	int b = 10;
	int&& rb = b + 10;
}
#if 0
//值的方式返回：
//使用ret---->创建一个临时变量(将亡值)----->函数运算结束栈空间被回收
int add(int a, int b)
{
	int ret = a + b;
	return ret;
}
void test2()
{
	int&& Ret = add(10, 20);//将亡值，生命周期要完了
}
#endif


#if 0
//c++98引用
//普通类型的引用
//const类型的引用
int main()
{
	//c++98 普通类型的引用只能引用左值
	int a = 10;
	int& ra = a;
	int& ra = a + 10;
	//int& rra = 10;

	//const类型的引用不仅能引用左值，也能引用右值
	//万能引用
	const int& cra1 = a;
	const int& cra2 = 10;
	return 0;
}
#endif

#if 0
//c++右值引用：只能引用右值--->c语言中的纯右值+将亡值
int main()
{
	int a = 10;
	int&&ra1 = a;
	int&& ra = move(a);//move 将左值转换为右值
	return 0;
}
#endif
//不能直接返回栈上的空间内容，假设函数结束，发现栈的空间内容不存在
//就会出错！！所以会拷贝一份临时的对象！
//把临时对象一拷贝，临时对象就被释放了


//原来的方式：函数中strRet--->拷贝构造temp返回对象---->拷贝构造s3
//优化：  函数中strRet--->拷贝构造temp返回对象   资源转移给temp，资源的转移-->拷贝构造s3
//移动语义！！

//移动构造 一定不能加const  因为要情况置nullptr
//String(String&& s)
//:_str(s._str)
//{
//s._str = nullptr;
//}

