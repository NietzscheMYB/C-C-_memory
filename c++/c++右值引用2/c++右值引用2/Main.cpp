#include<iostream>
using namespace std;

#if 0
class Info
{
public:
	Info()
		:_type(0)
		, _name('a')
	{
		InitRSet();
	}
	Info(int type)
		:_type(type)
		, _name('a')
	{
		InitRSet();
	}
	Info(char a)
		:_type(0)
		, _name(a)
	{
		InitRSet();
	}
private:
	void InitRSet()
	{
		//初始化其他变量
	}
private:
	int _type;
	char _name;
};
//上述构造函数除了初始化列表不同之外，其他部分都是类似的，代码重复
#endif



#if 0
class Info
{
public:
	//目标构造函数
	Info()
		:_type(0)
		, _a('a')
	{
		InitRSet();
	}
	//委派构造函数
	Info(int type)
		:Info()
	{
		_type = type;
	}
	//委派构造函数
	Info(char a)
		:Info()
	{
		_a = a;
	}

private:
	void InitRSet()
	{
		//初始化其他变量
	}
private:
	int _type = 0;
	char _a = 'a';
};
#endif


#include<string>
class Person
{
public:
	Person(char* name,char* sex,int age)
		:_name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		:_name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 1
	/*Person(Person&& p)
		:_name(p._name)
		,_sex(p._sex)
		, _age(p._age)
	{}*/
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif

private:
	string _name;
	string _sex;
	int _age;
};

Person GetTempPerson()
{
	Person p1("prety", "male", 18);
	return p1;
}

int main()
{
	Person p2(GetTempPerson());
	return 0;
}







