#include<iostream>
using namespace std;
#if 0
class Base1{
public:
	virtual void func1(){ cout << "Base1::func1()" << endl; }
	virtual void func2(){ cout << "Base1::func2()" << endl; }
private:
	int b1;
};
class Base2{
public:
	virtual void func1(){ cout << "Base2::func1()" << endl; }
	virtual void func2(){ cout << "Base2::func2()" << endl; }
private:
	int b2;
};

class Derive :public Base1, public Base2
{
public:
	virtual void func1(){ cout << "Derive::func1()" << endl; }
	virtual void func3(){ cout << "Derive::func3()" << endl; }
private:
	int d1;
};
typedef void(*VFPTR)();  //�ض��庯��ָ��
void Print(VFPTR vTable[])
{
	cout << "����ַ>" << vTable<<endl;
	for (int i = 0; vTable[i] != nullptr; i++)
	{
		printf("��%d���麯����ַΪ:0X%x,->", i, vTable[i]);
		VFPTR v = vTable[i];
		v();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)*(int*)&d;
	Print(vTableb1);

	VFPTR* vTableb2 = (VFPTR*)*(int*)((char*)&d+sizeof(Base1)); //d�������ƫ��һЩBase1��С�ľ��룬���ݶ���ģ�ͷ����麯����
	Print(vTableb2);
	return 0;
}
#endif

class Base{
public:
	virtual void func1(){ cout << "Base::func1()" << endl; }
	virtual void func2(){ cout << "Base::func2()" << endl; }
	virtual void func3(){ cout << "Base::func3()" << endl; }
private:
	int b;
};

class D:public Base{
public:
	virtual void func1(){ cout << "D::func1()" << endl; }
	virtual void func3(){ cout << "D::func3()" << endl; }
private:
	int d;
};

typedef void(*VFPTR)();

void Print(VFPTR vt[])
{
	cout << "���ĵ�ַ->" << vt << endl;
	for (int i = 0; vt[i] != nullptr; i++)
	{
		printf("��%d���麯��->OX%x", i, vt[i]);
		VFPTR f = vt[i];
		f();//ִ�к���
	}
}

int main()
{
	D d;
	VFPTR* v = (VFPTR*)*(int*)&d;
	Print(v);
	return 0;
}

 

