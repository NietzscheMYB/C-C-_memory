#include<iostream>
using namespace std;

#if 0
class Person 
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ--ȫƱ" << endl;
	}
};
class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ--��Ʊ" << endl;
	}
};

//�麯������д
//������麯�������������麯���ĺ������������������������ͣ�������ֵ��ͬʱ
//��˵������麯����д�˸�����麯��
//��дҲ��Ϊ����

void Func(Person& p)
{
	p.BuyTicket();
}
//���ɶ�̬��������������Ҫ����
//1.���ú����Ķ��������ָ���������
//2.�����ú����������麯������������麯������д



//�麯����д��������Э�䣬���麯���ķ���ֵ��һ��ʱ��������ֵ�����ǻ����ָ��
//�����ã��������ָ�������
//��������Ϊ��Э��

//�麯�����淶����д
//������ĳ�Ա����û�м�virtual�Ĺؼ���
int main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
	return 0;
}
#endif

//��ͨ�ļ̳У���һ��ʵ�ּ̳У�������̳��˻���ĺ���������ʹ�ú������̳е��Ǻ�����
//ʵ�֣���һ��ʵ�ּ̳С�
//�麯���ļ̳���һ�ֽӿڼ̳У��̳е��ǽӿڣ�Ŀ����Ϊ����д����ɶ�̬���̳�
//���ǽӿ�

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

//������
//���麯���ĺ���д��=0�����������Ϊ���麯�����������麯�������Ϊ������
//Ҳ�нӿ��࣬�����಻��ʵ����������
//������̳г���������û����д�麯�����Ͳ���ʵ����������
//���麯���淶�������������д�������ֳ��˽ӿڼ̳�

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
		cout << "Benz--����" << endl;
	}
};
class BWM :public Car
{
public:
	virtual void Drive()
	{
		cout << "BWM--�ٿ�" << endl;
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