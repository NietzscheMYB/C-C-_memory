#include<iostream>
using namespace std;

class Base{
public:
	virtual void func1(){ cout << "func1" << endl; }
	virtual void func2(){ cout << "func2" << endl; }
private:
	int a;
};

class Derive :public Base{
public:
	virtual void func1(){ cout << "Derive:func1" << endl; }
	virtual void func2(){ cout << "Derive:func3" << endl; }
	virtual void func3(){ cout << "Derive:func4" << endl; }
private:
	int b;
};

typedef void(*VFPTR)();
void PrintVTable(VFPTR vTable[])
{
	//依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << "虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址:0x%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	//思路：取出b，d对象的头4个bytes，就是虚表的指针，前面我们说了
	//虚函数表本质是一个存虚函数指针的指针数组，这个数组最后放了一个nullptr
	//1.先取b的地址，强制转成一个int*的指针
	//2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
	//3.再强制转换成VFPTR* ，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组
	//4.虚表指针传递给Print函数进行打印虚表
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);

	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);

	return 0;
}