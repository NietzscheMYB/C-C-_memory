#include <iostream>
using namespace std;
//class Person{
//public:
//	friend void Display(const Person& p,const Student& s);
//	friend void Display1(const Person& p);
//private:
//	int _name;//����
//};
//class Student :public Person
//{
//protected:
//	int _stuNum;//ѧ��
//};
//void Display1(const Person& p)
//{
//	cout << p._name << endl;
//}
//void Display(const Person&p,const Student& s)
//{
//	//���ܷ���
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
	string _name;//����
public:
	static int _count;//ͳ���˵ĸ���
};
int Person::_count = 0;
class Student :public Person
{
protected:
	int _stuNum;//ѧ��
};
class Graduate :private Student
{
public:
	static int x;
protected:
	string _seminarCourse;//�о���Ŀ
};
int Graduate::x = 0;

void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "������" << Person::_count << endl;
	Student::_count = 0;
	cout << "������" << Person::_count << endl;
}
int main()
{
	TestPerson();
	return 0;
}







