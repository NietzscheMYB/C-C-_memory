#include <iostream>
#include <string>
using namespace std;

//class Person{
//public:
//	string _name;//����
//};
//class Student :public Person
//{
//protected:
//	int _num;//ѧ��
//};
//class Teacher :public Person
//{
//protected:
//	int _id;//ְ�����
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;//���޿γ�
//};
//
//void Test()
//{
//	//���������������޷���ȷ������һ��
//	Assistant a;
//	//a._name = "peter";//��֪��������һ��
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class Person
//{
//public:
//	string _name;//����
//};
//
//class Student :virtual public Person
//{
//protected:
//	int _num;//ѧ��
//};
//
//class Teacher :virtual public Person
//{
//protected:
//	int _id;//ְ����
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;//���޿γ�
//};
//
//void Test()
//{
//	Assistant a;
//	//ʹ������̳н�����ζ����Ժ�������������
//	a._name = "peter";
//}

class A
{
public:
	int _a;
};
class B : virtual public A
//class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
//class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};

void Test()
{
		D d;
		d.B::_a = 1;
		d.C::_a = 2;
		d._b = 3;
		d._c = 4;
		d._d = 5;
}
int main()
{
	Test();
	return 0;
}