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
////ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�̬�����ܱ�֤
////p1 p2ָ��Ķ�����ȷ�ĵ�����������
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//}

////1.final ���λ�����麯�����ܱ���������д
//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive(){
//		cout << "Benz-����" << endl;
//	}
//};

class Car
{
public:
	virtual void Drive()
	{
	}
};

//2.override �����������麯��ǿ�������д�����û����д�ᱨ��
class Benz :public Car
{
public:
	virtual void Drive() override
	{
		cout << "Benz-����" << endl;
	}
};