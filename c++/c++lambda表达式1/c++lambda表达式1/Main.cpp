#include<iostream>
using namespace std;

#if 0
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}

void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}

void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}

void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}


template<typename T>
void PerfectForward(T &&t)
{
	Fun(std::forward<T>(t));
}

int main()
{
	PerfectForward(10);//rvalue ref

	int a;
	PerfectForward(a);//lvaue ref
	PerfectForward(std::move(a));//rvalue ref

	const int b = 8;
	PerfectForward(b);//const lvalue ref
	PerfectForward(std::move(b));//const rvalue ref

	return 0;
}
#endif

#include<algorithm>
#include<functional>
#include<string>
#if 0
int main()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };

	//默认是排升序！！
	sort(array, array + sizeof(array) / sizeof(array[0]));
	
	//改变规则，排降序
	sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
	return 0;
}
#endif


#if 0
//如果待排序元素是自定义类型，需要用户排序时定义比较规则

struct Goods
{
	string _name;
	double _price;
};

struct Compare
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	//sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());//Compare()仿函数，函数对象，就是对operator()的使用，理解成创建一个无名对象，然后使用operator()

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& l,const Goods& r){
		return l._price < r._price; });

	return 0;
}
#endif


#if 0
int main()
{
	//最简单的lambda表达式，该lambda表达式没有任何意义
	[]{};

	//省略参数列表和返回值类型，返回值类型由编译器推导为int

	int a = 3, b = 4;
	[=]{return a + 3; };

	//省略了返回值类型，无返回值类型
	auto fun1 = [&](int c){b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;

	//各部分都很完善的lambda函数
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;

	//复制捕捉x
	int x = 10;
	auto add_x = [x](int a)mutable{x *= 2; return a + x; };
	cout << add_x(10) << endl;

	return 0;
}
#endif

#if 0
typedef void(*PF)()  ;
int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };

	//f1=f2;//编译失败---->提示找不到operator=()

	auto f3(f2);
	f3();

	//可以将lambda表达式赋值给相同类型的函数指针
	PF x= f2;
	x();
	return 0;
}
#endif

class Rate
{
public:
	Rate(double rate)
		:_rate(rate)
	{}
	double operator()(double money,int year)
	{
		 return money*_rate*year;
	  
	}
private:
	 double _rate;
};

int main()
{
	//函数对象
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	 
	//仿函数
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);
	return 0;
}















