#include <iostream>
#include <string>
using namespace std;

void TestString()
{
	string str;
	str.push_back(' ');//��str�����ո�
	str.append("hello");//��str����׷��һ���ַ�
	str += 'b';//��str����׷��һ���ַ�
	str += "it";//��str����׷��һ���ַ���"it"

	//size_t��һ��������ص��޷������ͣ�������Ƶ��㹻���Ա��ܹ�
	//�ڴ����������Ĵ�С

	//cout << str << endl;
	//cout << str.c_str() << endl;

	//��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');


	//str.substr()  ��ȡ�ַ������� �õ�һ���ַ���
	//�������±꣬
	//str.substr(3,5)//���±�Ϊ3��λ�ð���3 ��ȡ5���ַ���
	//str.substr(3)//���±�Ϊ3��λ�ð���3����ȡ��ĩβ
	string sufffix(file.substr(pos, file.size() - pos));
	cout << sufffix << endl;
	cout << file.substr(6);

}
void TestString2()
{
	//nops��string�����һ����̬��Ա����
	//static const size_t npos=-1;
	//ȡ��url�е�����
	string ur1("http://www.cplusplus.com/reference/string/string/substr/");
	cout << ur1 << endl;

	size_t start = ur1.find("://");
	if (start == string::npos)
	{
		cout << "invalid ur1" << endl;
		return;
	}



}
int main()
{
	TestString2();
	return 0;
}