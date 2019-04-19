#include <iostream>
#include <string>
using namespace std;

//class Person{
//public:
//	string _name;//姓名
//};
//class Student :public Person
//{
//protected:
//	int _num;//学号
//};
//class Teacher :public Person
//{
//protected:
//	int _id;//职工编号
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;//主修课程
//};
//
//void Test()
//{
//	//会有这样二义性无法明确访问哪一个
//	Assistant a;
//	//a._name = "peter";//不知道访问哪一个
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class Person
//{
//public:
//	string _name;//姓名
//};
//
//class Student :virtual public Person
//{
//protected:
//	int _num;//学号
//};
//
//class Teacher :virtual public Person
//{
//protected:
//	int _id;//职工号
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;//主修课程
//};
//
//void Test()
//{
//	Assistant a;
//	//使用虚拟继承解决菱形二义性和数据冗杂问题
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