#include<iostream>
using namespace std;
void test()
{
	//开辟1个int 大小的空间
	int* ptr1 = new int;
	//开辟1个int 大小的空间并初始化为10；
	int* ptr2 = new int(2);
	//开辟10个int 大小的空间
	int* ptr3 = new int[10];
	delete ptr1;
	delete ptr2;
	delete[] ptr3;
}
class Test{
public:
	Test()
		:_data(0)
	{
		cout << "Test()" <<this<< endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _data;
};
void Test2()
{
	//申请单个Test类型的对象
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	//申请10个Test类型的对象
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test3()
{
	//申请单个test类型的对象
	Test* p1 = new Test;
	delete p1;
	//申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}

class HeapOnly{
public:
	 static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	 static HeapOnly xx()
	 {
		 return HeapOnly();
	 }
private:
	HeapOnly(){
		cout << "heapOnly()" << endl;
	}

	//c++98 
	//1.只声明，不实现。
	//2.声明称私有
	HeapOnly(const HeapOnly&);
};

class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	};
	//在栈上创建，即在堆上不能创建，因此将new的功能屏蔽调
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{
	HeapOnly* ptr=HeapOnly::CreateObject();
	//HeapOnly xx = HeapOnly::xx();//拷贝构造
	StackOnly x = StackOnly::CreateObject();
	return 0;
}




