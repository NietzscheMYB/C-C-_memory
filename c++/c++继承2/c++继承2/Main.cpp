#include<iostream>
#include<string>
using namespace std;

#if 0
class person
{
public:
	int num;
	char tel[15];
};

class student:public person
{
public:
	int id_;
};

int main()
{
	person p1;
	student s1;
	person* q;
	q = &p1;
	q = &s1;
	

	return 0;
}
#endif


#if 0
class Person
{
public:
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person(const char* name = perter)" << endl;
	}
	Person(const Person&p)
		:_name(p._name)
	{
		cout << "Person(const Person&p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	string _name;//����
};

class Student :public Person
{
public:
	Student()
	{}
	Student(const char* name,int num)
		:Person(name)
		,_num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student&s)" << endl;
	}
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num;//ѧ��
};

void  Test()
{
	Student s0;
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}

int main()
{
	Test();
	return  0;
}
#endif

#if 0
class Person{
public:
	string _name;//����
};
class Student :public Person
{
protected:
	int _num;//ѧ��
};
class Teacher: public Person
{
protected:
	int _id;//ְ�����
};

class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse;//���޿γ�
};

void Test()
{
	//�������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	//a._name = "peter"; ����֪��������һ��

	//��Ҫ��ʾָ�������Ǹ�����ĳ�Ա���Խ������������
	//�����������������޷����
	a.Student::_name = "xxx";
	a.Student::_name = "yyy";
}
#endif

class A
{
public:
	int _a;
};

class B :virtual public A
{
public:
	int _b;
};

class C :virtual public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	return 0;
}



