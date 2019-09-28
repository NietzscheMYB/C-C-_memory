#include<iostream>
using namespace std;

#if 0
class Person 
{
public:
	virtual void BuyTicket()
	{
		cout << "买票--全票" << endl;
	}
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票--半票" << endl;
	}
};

//虚函数的重写
//子类的虚函数如果跟父类的虚函数的函数名，函数参数（个数类型），返回值相同时
//就说子类的虚函数重写了父类的虚函数
//重写也称为覆盖

void Func(Person& p)
{
	p.BuyTicket();
}
//构成多态的条件是首先是要基础
//1.调用函数的对象必须是指针或者引用
//2.被调用函数必须是虚函数，且完成了虚函数的重写



//虚函数重写的特例，协变，当虚函数的返回值不一样时，但返回值必须是基类的指针
//或引用，派生类的指针或引用
//称这种行为是协变

//虚函数不规范的重写
//派生类的成员函数没有加virtual的关键字
int main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
	return 0;
}
#endif

//普通的继承，是一种实现继承，派生类继承了基类的函数，可以使用函数，继承的是函数的
//实现，是一种实现继承。
//虚函数的继承是一种接口继承，继承的是接口，目的是为了重写，达成多态，继承
//的是接口

#if 0
class Person
{
public:
	virtual ~Person()
	{
		cout << "Person()" << endl;
	}
};

class Student :public Person
{
public:
	virtual ~Student()
	{
		cout << "Student()" << endl;
	}
};

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;

	delete p1;
	delete p2;
	
 
	return 0;
}
#endif

//抽象类
//在虚函数的后面写上=0，这个函数称为纯虚函数，包含纯虚函数的类称为抽象类
//也叫接口类，抽象类不能实例化出对象，
//派生类继承抽象类后，如果没有重写虚函数，就不能实例化出对象
//纯虚函数规范了派生类必须重写，更体现出了接口继承

class Car
{
public:
	virtual void Drive() = 0;
};

class Benz:public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz--舒适" << endl;
	}
};
class BWM :public Car
{
public:
	virtual void Drive()
	{
		cout << "BWM--操控" << endl;
	}
};

int main()
{
	Car* p1 = new Benz;
	p1->Drive();
	Car* p2 = new BWM;
	p2->Drive();
	return 0;
}