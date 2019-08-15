#include<iostream>
#include<string>
using namespace std;
void TestString()
{
	string s1;//����һ��string�������s1
	string s2("hello bit");//��c�ַ�������ʽ����һ��string��s2
	string s3(10, 'a');//��10���ַ���a������string�����s3
	string s4(s2);//��������s4
	string s5(s3, 5);//��s3��ǰ5���ַ�����string����s5
}
void TestString1()
{
	string s("hello world");
	//string s;
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;


	//��s����Ч�ַ��������ӵ�10�������λ���á�a���������
	//��aaaaaaaaaa��
	s.resize(10,'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ��\0���������
	//'aaaaaaaaaa\0\0\0\0\0'
	//ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	//s.resize(15,'1');
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//��s�е���Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;


	//����
	s.resize(16);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}


void TestString2()
{
	string s;
	//����reserve�Ƿ��ı�string����ЧԪ�صĸ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	//����resever����С��string�ĵײ��Сʱ���Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

int main()
{
	TestString2();
	return 0;
}