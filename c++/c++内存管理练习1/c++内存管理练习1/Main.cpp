#include <iostream>
//通过new和delete操作符进行动态内存管理
//void Test()
//{
//	int* ptr4 = new int;
//	//动态申请一个int类型的空间
//
//	int* ptr5 = new int(10);
//	//动态申请一个int类型的空间并初始化为10
//
//	int* ptr6 = new int[10];
//	//动态申请10个int类型的空间
//
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//new delete 是操作符！！！

//申请和释放单个元素的空间，有new和delete操作符
//申请和释放连续的空间使用new[],delete[]
//using namespace std;
//
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
//
//private:
//	int _data;
//};
//
//void Test2()
//{
//	//申请单个Test类型的空间
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	//申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test)*10);
//	free(p2);
//
//	//申请单个Test类型的对象
//	Test* p3 = new Test;
//	delete p3;
//	//申请10个Test类型的对象
//	Test* p4 = new Test[10];
//	delete[] p4;
//}
//
////在申请自定义类型的空间时，new会调用构造函数
////delete 会调用析构函数，
////而malloc与free不会
//
//int main()
//{
//	Test2();
//	return 0;
//}

//new 和delete是用户进行动态内存申请和释放的运算符
//operator new和operator delete是系统提供的全局函数
//new在底层调用operator new全局函数来申请空间
//delete在底层通过operator delete全局函数来释放空间


//operator new:该函数实际通过malloc 来申请空间
//当malloc申请空间成功时，直接返回，申请空间失败，
//尝试再执行，如果该应对措施用户设置，则继续申请，否则抛出异常

//operator delete 该函数最终是通过free来释放空间


