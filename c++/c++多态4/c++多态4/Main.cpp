#include<iostream>
using namespace std;

#if 0
class Base{
public:
	virtual void func1(){ cout << "Base::func1" << endl; }
	virtual void func2(){ cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base
{
public:
	virtual void func1(){ cout << "Derive::func1" << endl; }
	virtual void func3(){ cout << "Derive::func3" << endl; }
	virtual void func4(){ cout << "Derive::func4" << endl; }
private:
	int b;
};
typedef void(*VFPTR)();         //重定义，函数指针，参数是空，返回值是void

void Print(VFPTR v[])
{
	//依次取虚表中的虚函数指针打印并调用。调用就可以看出存的 是哪个函数
	cout << "虚表地址>" << v << endl;
	for (int i = 0; v[i] != nullptr; i++)
	{
		printf("第%d个虚函数地址0x%x,->", i, v[i]);
		VFPTR f = v[i];//得到函数的地址
		//执行这个函数
		f();
	}
	cout << endl;
}

int main()
{
	Base b;
	//因为vs2013平台下，对象的前4个字节是虚函数表的地址，则取对象的前4个字节
	
	//1.先取b的地址，强制抓换成一个int* 的指针
	//2.再解引用，就取到了b对象4bytes的值，这个值就是指向虚表的指针
	//3.再强制转换成VFPTR*，因为虚表就是一个存VFPTR类型的(虚函数指针类型)数组
	//4.虚表指针传递给PrintVTable 进行打印虚表
	VFPTR* v = (VFPTR*)*(int*)&b;
	Print(v);

	Derive d;
	VFPTR* v2 = (VFPTR*)*(int*)&d;
	Print(v2);
	return 0;
}
#endif


class Base1
{
public:
	virtual void func1(){ cout << "Base1::func1" << endl; }
	virtual void func2(){ cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2
{
public:
	virtual void func1(){ cout << "Base2::func1" << endl; }
	virtual void func2(){ cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive :public Base1, public Base2
{
public:
	virtual void func1(){ cout << "Derive::func1" << endl; }
	virtual void func3(){ cout << "Derive::func3"<<endl; }
private:
	int d1;
};

typedef void(*VFPTR)();//重定义函数指针

void Print(VFPTR v[])
{
	cout << "虚函数表的地址：" << v << endl;
	for (int i = 0; v[i] != nullptr; i++)
	{
		printf("第%d个虚函数地址：0X%x,->", i, v[i]);
		VFPTR f = v[i];//获取函数的地址
		//调用函数
		f();
	}
	cout << endl;
}

int main()
{
	Base1 b1;
	VFPTR* v1 = (VFPTR*)*(int*)&b1;
	Print(v1);
	Base2 b2;
	VFPTR* v2 = (VFPTR*)*(int*)&b2;
	Print(v2);
	Derive d;
	VFPTR* v3 = (VFPTR*)*(int*)&d;
	Print(v3);

	VFPTR* v4 = (VFPTR*)*(int*)((char*)&d+sizeof(Base1));
	Print(v4);

	return 0;
}


