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
		//��ʼ����������
	}
private:
	int _type;
	char _name;
};
//�������캯�����˳�ʼ���б�֮ͬ�⣬�������ֶ������Ƶģ������ظ�
#endif



#if 0
class Info
{
public:
	//Ŀ�깹�캯��
	Info()
		:_type(0)
		, _a('a')
	{
		InitRSet();
	}
	//ί�ɹ��캯��
	Info(int type)
		:Info()
	{
		_type = type;
	}
	//ί�ɹ��캯��
	Info(char a)
		:Info()
	{
		_a = a;
	}

private:
	void InitRSet()
	{
		//��ʼ����������
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







