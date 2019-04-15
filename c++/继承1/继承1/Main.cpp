#include <iostream>
#include <string>
using namespace std;

////class Person
////{
////protected:
////	string _name = "peter";
////	int _age = 18;
////public:
////	void Print()
////	{
////		cout << "name:" << _name << endl;
////		cout << "age:" << _age << endl;
////	}
////};
////
////class Student :public Person
////{
////protected :
////	int _stuid;  //学号
////};
////
////class Teacher :public Person
////{
////protected:
////	int _jobid;//工号
////};
////
////void Test1()
////{
////	Person p;
////	Student s;
////	s.Print();
////	Teacher t;
////	t.Print();
////	
////}
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//public:
//	string _name;
//private:
//	int _age;
//protected:
//	int _id;
//};
//
//
////private:在类外和子类都无法访问
////protected：在类外无法访问，但是在子类的内部可以访问
////public继承：不改变基类成员在子类的访问权限
////protected继承：基类成员在子类中最低访问权限为protected
////private继承：基类成员在子类中的最低访问权限为prviate
//
//
////当为public继承时
//class Student :public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		_name = "myb";
//		//当位public Person时_age不能访问
//		_age = 18;
//	}
//public:
//	int _stunnum;//学号
//private:
//	string _name;
//	int _age;
//protected:
//	int _id;
//};
//void Test2()
//{
//	Student s;
//}
//
////class Student :protected Person
////{
////	public:
////		void fun1()
////		{
////			_id = 123;
////			_name = "myb";
////			//_age  private 比protect小则不可见
////		}
////	public:
////		int _stunnum;//学号
////	private:
////		string _name;
////		//int _age;
////	protected:
////		int _id;
////};
////
////void Test3()
////{
////	Student s;
////	//因为为protec继承 则基类中的成员不能被访问
////}
//
//
//
////class Student :private Person
////{
////		public:
////			void fun1()
////			{
////				_id = 123;
////				_name = "myb";
////				//_age  private 比protect小则不可见
////			}
////		public:
////			int _stunnum;//学号
////		private:
////			string _name;
////			//int _age;
////		protected:
////			int _id;
////};
////
////void Test4()
////{
////	Student s;
////	//private 成员在任何继承中都不可见！！
////}
//
////protected 在类外无法访问，但在子类 的内部可以访问
////private  在类外和子类都不能访问
////public 不改变基类成员在子类中的访问权限
////protected  基类成员在子类中的最低访问权限
////为protected
////private 基类成员在子类中权限为private
//
//void Test5()
//{
//	Person p;
//	Student s;
//	//切片  子类对象可以赋给父类对象
//	p = s;
//	//父类对象不能赋值给子类对象
//	//s = p;
//	//子类指针可以赋给父类指针
//	Person* ptr = &s;
//	//子类可以赋给父类引用，引用底层就是指针
//	Person& ref = s;
//	//父亲的指针不能赋值给子类指针：可能会方式访问越界
//	//Student *ptr2=&p；   //因为父类的范围比子类的要小
//}
class Person
{
	public:
	string _name = "小李子"; // 姓名
	int _id = 111; // 身份证号
};
class Student :public Person
{
public:
	void Print()
	{
		cout << "姓名" << _name << endl;
		cout << "身份证号：" << _id << endl;  //出现类成员变量名相同时  就近原则
	}
public:
	int _id = 99;
};
void Test6()
{
	Person p;
	Student s;
	cout << p._id << endl;
	cout << s._id << endl;
	cout << s.Person::_id << endl;

}
int main()
{
	Test6();
	return 0;
}