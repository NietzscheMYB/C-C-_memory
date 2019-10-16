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
	//����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << "����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("��%d���麯����ַ:0x%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	//˼·��ȡ��b��d�����ͷ4��bytes����������ָ�룬ǰ������˵��
	//�麯��������һ�����麯��ָ���ָ�����飬�������������һ��nullptr
	//1.��ȡb�ĵ�ַ��ǿ��ת��һ��int*��ָ��
	//2.�ٽ�����ȡֵ����ȡ����b����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
	//3.��ǿ��ת����VFPTR* ����Ϊ������һ����VFPTR����(�麯��ָ������)������
	//4.���ָ�봫�ݸ�Print�������д�ӡ���
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);

	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);

	return 0;
}