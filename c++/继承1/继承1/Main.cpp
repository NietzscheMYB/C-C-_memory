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
////	int _stuid;  //ѧ��
////};
////
////class Teacher :public Person
////{
////protected:
////	int _jobid;//����
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
////private:����������඼�޷�����
////protected���������޷����ʣ�������������ڲ����Է���
////public�̳У����ı�����Ա������ķ���Ȩ��
////protected�̳У������Ա����������ͷ���Ȩ��Ϊprotected
////private�̳У������Ա�������е���ͷ���Ȩ��Ϊprviate
//
//
////��Ϊpublic�̳�ʱ
//class Student :public Person
//{
//public:
//	void fun1()
//	{
//		_id = 123;
//		_name = "myb";
//		//��λpublic Personʱ_age���ܷ���
//		_age = 18;
//	}
//public:
//	int _stunnum;//ѧ��
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
////			//_age  private ��protectС�򲻿ɼ�
////		}
////	public:
////		int _stunnum;//ѧ��
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
////	//��ΪΪprotec�̳� ������еĳ�Ա���ܱ�����
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
////				//_age  private ��protectС�򲻿ɼ�
////			}
////		public:
////			int _stunnum;//ѧ��
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
////	//private ��Ա���κμ̳��ж����ɼ�����
////}
//
////protected �������޷����ʣ��������� ���ڲ����Է���
////private  ����������඼���ܷ���
////public ���ı�����Ա�������еķ���Ȩ��
////protected  �����Ա�������е���ͷ���Ȩ��
////Ϊprotected
////private �����Ա��������Ȩ��Ϊprivate
//
//void Test5()
//{
//	Person p;
//	Student s;
//	//��Ƭ  ���������Ը����������
//	p = s;
//	//��������ܸ�ֵ���������
//	//s = p;
//	//����ָ����Ը�������ָ��
//	Person* ptr = &s;
//	//������Ը����������ã����õײ����ָ��
//	Person& ref = s;
//	//���׵�ָ�벻�ܸ�ֵ������ָ�룺���ܻ᷽ʽ����Խ��
//	//Student *ptr2=&p��   //��Ϊ����ķ�Χ�������ҪС
//}
class Person
{
	public:
	string _name = "С����"; // ����
	int _id = 111; // ���֤��
};
class Student :public Person
{
public:
	void Print()
	{
		cout << "����" << _name << endl;
		cout << "���֤�ţ�" << _id << endl;  //�������Ա��������ͬʱ  �ͽ�ԭ��
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