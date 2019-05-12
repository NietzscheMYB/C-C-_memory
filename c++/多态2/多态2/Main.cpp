#include <iostream>
using namespace std;
//class Person{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student:public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
////只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证
////p1 p2指向的对象正确的调用析构函数
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//class Car
//{
//public:
//	virtual void Drive() = 0;
//
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//}

////1.final 修饰基类的虚函数不能被派生类重写
//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive(){
//		cout << "Benz-舒适" << endl;
//	}
//};

class Car
{
public:
	virtual void Drive()
	{
	}
};

//2.override 修饰派生类虚函数强制完成重写，如果没有重写会报错
class Benz :public Car
{
public:
	virtual void Drive() override
	{
		cout << "Benz-舒适" << endl;
	}
};