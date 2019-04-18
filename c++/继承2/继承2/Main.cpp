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
////继承后父类的Person的成员（成员函数+成员变量）
////都会成为子类 的一部分
//
//class Student :public Person
//{
//protected:
//	int _stuid;//学号
//};
//
//class Teacher :public Person
//{
//protected:
//	int _jobid;//工号
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
//	//1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;  //切片
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;//出现语法错误
//
//	//3.基类指针可以通过强制类型转换赋值给派生类
//	pp = &sobj;
//	Student* ps1 = (Student*)pp;//这种情况转换时可以
//	ps1->_No = 10;
//
//	pp = &pobj;
//	//基类强转称子类会可能会方式访问越界问题
//	Student* ps2 = (Student*)pp;//这种情况转换是可以的，但是存在访问越界的问题
//	ps2->_No = 10;
//}

//class Person
//{
//protected:
//	string _name = "小李子";
//		int _num = 111;
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "身份证号：" << Person::_num << endl;
//		cout << "学号：" << _num << endl;
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


//B中的fun与A中的fun不是构造函数，因为不是在同一作用域
//B中的fun和A中的fun构成隐藏，
//成员函数满足函数名相同时就构成隐藏
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
//	string _name;//姓名
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
//	int _num;//学号
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}

//实现一个不能被继承的类
//c++98中构造函数私有化，派生类中调不到
//基类的构造函数。则无法继承
class NonInherit{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit();
};
//c++11 给出了新的关键字final禁止继承
class NonInherit final
{};

int main()
{
	//Test();
	return 0;
}

