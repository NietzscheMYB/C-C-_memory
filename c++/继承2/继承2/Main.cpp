#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter";
//	int _age = 18;
//};
//
////�̳к����Person�ĳ�Ա����Ա����+��Ա������
////�����Ϊ���� ��һ����
//
//class Student :public Person
//{
//protected:
//	int _stuid;//ѧ��
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobid;//����
//};

//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	string _age;
//};
//
//class Student :public Person
//{
//public:
//	int _No;
//};
//void Test()
//{
//	Student sobj;
//	//1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;  //��Ƭ
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.��������ܸ�ֵ�����������
//	//sobj = pobj;//�����﷨����
//
//	//3.����ָ�����ͨ��ǿ������ת����ֵ��������
//	pp = &sobj;
//	Student* ps1 = (Student*)pp;//�������ת��ʱ����
//	ps1->_No = 10;
//
//	pp = &pobj;
//	//����ǿת���������ܻ᷽ʽ����Խ������
//	Student* ps2 = (Student*)pp;//�������ת���ǿ��Եģ����Ǵ��ڷ���Խ�������
//	ps2->_No = 10;
//}

//class Person
//{
//protected:
//	string _name = "С����";
//		int _num = 111;
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "������" << _name << endl;
//		cout << "���֤�ţ�" << Person::_num << endl;
//		cout << "ѧ�ţ�" << _num << endl;
//	}
//protected:
//	int _num = 999;
//};
//
//void Test()
//{
//	Student s1;
//	s1.Print();
//
//}


//B�е�fun��A�е�fun���ǹ��캯������Ϊ������ͬһ������
//B�е�fun��A�е�fun�������أ�
//��Ա�������㺯������ͬʱ�͹�������
//class A
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "fun(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//}
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name= p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;//����
//};
//class Student :public Person
//{
//public:
//	Student(const char* name,int num)
//		:Person(name), _num(num)
//	{
//		cout << "Student(const char* name,int num)" << endl;
//	}
//	Student(const Student& s)
//		: Person(s),_num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = _num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num;//ѧ��
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}

//ʵ��һ�����ܱ��̳е���
//c++98�й��캯��˽�л����������е�����
//����Ĺ��캯�������޷��̳�
class NonInherit{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit();
};
//c++11 �������µĹؼ���final��ֹ�̳�
class NonInherit final
{};

int main()
{
	//Test();
	return 0;
}

