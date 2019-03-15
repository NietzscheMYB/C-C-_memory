#include <iostream>
using namespace std;
//int main()
//{
//	int *p = new int(10);
//	int *p2 = new int[10];
//	delete p;
//	delete[]p2;
//}

//new delete 是操作符，new在使用会调用全局函数operate new
//operate new在底层会调用malloc函数，如果申请失败，会再一次
//申请，如果还失败返回空
//delet 在使用会调用全局函数operatr delete 
//operate delete在底层会调用free

//在申请自定义类型的空间时，new会调用构造函数
//delete会调用析构函数！！
//new---mallco---构造
//delete-----析构-----free

//以inline修饰的函数叫内敛函数，编译c++，编译器会调用
//内敛函数的地方展开，没有函数压栈的开销
//内敛函数提升程序运行的效率

//直接展开，没有函数压栈的开销


//NULL实际是一个宏，可能被定义为字面常量0，或者被定义为
//无类型指针（void*）的常量

//c++11提供了nullptr，即nullptr代表一个指针空值常量
//nullptr是有类型的，其类型为nullptr_t
//在使用nullptr表示指针空值时，不需要包含头文件
//因为nullptr是c++11作为新的关键字引入

//如果申请的是内置类型的空间，new和malloc，delete free
//基本类似，不同的是 new/delete 申请和释放的单个
//元素的空间，new[]，delete[]申请 的是连续空间
//而且new在申请空间失败时会抛异常
//malloc会返回NULL

//new T[N]的原理
//调用operator new[]函数，在operator new[]，中实际调用
//operator new函数完成N个对象空间的申请
//在申请的空间上执行N次构造函数

//delete[]的原理
//在释放的对象的空间上执行N次析构函数，完成N个对象中的资源清理
//调用operator delete[]释放空间，实际在operator delete[]
//中调用operator delete来释放空间


//定位new表达式是在已分配的原始内存空间中
//调用构造函数初始化一个对象
#include <malloc.h>
//class Test
//{
//public:
//	Test()
//		:_data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void Test1()
//{
//	Test*pt=(Test*)malloc(sizeof(Test));
//	new(pt)Test;
//}
//int main()
//{
//	Test1();
//	return 0;
//}

//设计一个类，该类只能在堆上创建对象

//方法1
//1.将这类构造函数私有，拷贝构造声明成私有，放在别人调用拷贝在栈上生成对象
//2.提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(const HeapOnly&);

};


