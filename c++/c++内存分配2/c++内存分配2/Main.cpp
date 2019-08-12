#include<iostream>
using namespace std;
void test()
{
	//����1��int ��С�Ŀռ�
	int* ptr1 = new int;
	//����1��int ��С�Ŀռ䲢��ʼ��Ϊ10��
	int* ptr2 = new int(2);
	//����10��int ��С�Ŀռ�
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
	//���뵥��Test���͵Ķ���
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	//����10��Test���͵Ķ���
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test3()
{
	//���뵥��test���͵Ķ���
	Test* p1 = new Test;
	delete p1;
	//����10��Test���͵Ķ���
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
	//1.ֻ��������ʵ�֡�
	//2.������˽��
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
	//��ջ�ϴ��������ڶ��ϲ��ܴ�������˽�new�Ĺ������ε�
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{
	HeapOnly* ptr=HeapOnly::CreateObject();
	//HeapOnly xx = HeapOnly::xx();//��������
	StackOnly x = StackOnly::CreateObject();
	return 0;
}




