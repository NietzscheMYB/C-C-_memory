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
typedef void(*VFPTR)();         //�ض��壬����ָ�룬�����ǿգ�����ֵ��void

void Print(VFPTR v[])
{
	//����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ������ ���ĸ�����
	cout << "����ַ>" << v << endl;
	for (int i = 0; v[i] != nullptr; i++)
	{
		printf("��%d���麯����ַ0x%x,->", i, v[i]);
		VFPTR f = v[i];//�õ������ĵ�ַ
		//ִ���������
		f();
	}
	cout << endl;
}

int main()
{
	Base b;
	//��Ϊvs2013ƽ̨�£������ǰ4���ֽ����麯����ĵ�ַ����ȡ�����ǰ4���ֽ�
	
	//1.��ȡb�ĵ�ַ��ǿ��ץ����һ��int* ��ָ��
	//2.�ٽ����ã���ȡ����b����4bytes��ֵ�����ֵ����ָ������ָ��
	//3.��ǿ��ת����VFPTR*����Ϊ������һ����VFPTR���͵�(�麯��ָ������)����
	//4.���ָ�봫�ݸ�PrintVTable ���д�ӡ���
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

typedef void(*VFPTR)();//�ض��庯��ָ��

void Print(VFPTR v[])
{
	cout << "�麯����ĵ�ַ��" << v << endl;
	for (int i = 0; v[i] != nullptr; i++)
	{
		printf("��%d���麯����ַ��0X%x,->", i, v[i]);
		VFPTR f = v[i];//��ȡ�����ĵ�ַ
		//���ú���
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


