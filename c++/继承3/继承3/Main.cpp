#include <iostream>
using namespace std;
//class Person{
//public:
//	friend void Display(const Person& p,const Student& s);
//	friend void Display1(const Person& p);
//private:
//	int _name;//姓名
//};
//class Student :public Person
//{
//protected:
//	int _stuNum;//学号
//};
//void Display1(const Person& p)
//{
//	cout << p._name << endl;
//}
//void Display(const Person&p,const Student& s)
//{
//	//不能访问
//	//cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}

class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name;//姓名
public:
	static int _count;//统计人的个数
};
int Person::_count = 0;
class Student :public Person
{
protected:
	int _stuNum;//学号
};
class Graduate :private Student
{
public:
	static int x;
protected:
	string _seminarCourse;//研究科目
};
int Graduate::x = 0;

void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "人数：" << Person::_count << endl;
	Student::_count = 0;
	cout << "人数：" << Person::_count << endl;
}
int main()
{
	TestPerson();
	return 0;
}







