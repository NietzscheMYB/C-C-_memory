#include <iostream>
#include <string>
using namespace std;

void test1()
{
	string s;
	string s2("keda");
	s.push_back('h');  //�����ַ�
	s += 'e';
	s.append("helllo");//�����ַ���
	s += "hello";
	s += s2;          //+=  ��������ַ������ܼ��ַ���  �൱��β�壡����
	cout << s << endl;
	s2.assign(s);  //assign �ı����������
	
	cout << s2 << endl;
}
//insert
void test2()
{
	string s("world");
	s.insert(1, "hello ");//��ĳ��λ�ÿ�ʼ�����ַ���
	cout << s << endl;
	//string s2;
	//s2.insert(0,s, 3, 5);//��ĳ��λ�ÿ�ʼ����ĳ���ַ�����ĳ������
	//cout << s2 << endl;
	//s.erase(0, 1);//��ĳ��λ��ɾ�������ַ�
	//cout << s << endl;
	//s.erase(0,15);  //��ĳ��λ��ɾ�������ַ�
	//cout << s << endl;
	string s4("bite");
	//s.replace(0, 2, s4);  //�ӵ�0��λ��������������s4


	//swap(s, s4);  //�����ģ�壡����
	//cout << s << endl;
	//cout << s4 << endl;
	//s.swap(s4);//����ָ�룡��
	//cout << s << endl;
	//cout << s4 << endl;

	//const char *ps=s4.c_str();//c_str����һ���ַ����׵�ַ
	//cout << ps << endl;
}
void test3()
{
	string file("test.cpp");
	//string s = file.substr(4, 4);//�ӵ�4����ʼ ��4�������4��
	size_t pos = file.find('.');
	string s = file.substr(pos, file.size() - pos);
	cout << s << endl;

	//s.find()///�������ַ�����������
}

//ȫ��cplusplus���Ͽ������У�������
//���ýӿ�
//������ ���� beign end
//����    size capacity  reserve(����)
//Ԫ�ط��� operate[]
//�ı�  operate+=  insert erease
//string operations c_str()��ȡc�����ַ��� find refind substr
//�ǳ�Ա �˽��1

void ReverseString(string& s)
{
	if (s.empty())
	{
		return;
	}
	/*string::iterator sit1 = s.begin();
	string::iterator sit2 = s.end();
	int len = s.size();
	for (int i = 0; i <len/2; i++)
	{
		swap(*sit1, *sit2);
	}*/
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		end--;
		start++;
	}
	//return s;
}
int  GetLen(string& s)
{
	int count = 0;
	string::iterator sit = s.begin();    //getline(cin,s)!!!�����ո񲻽��� cin �����ո����
	while (*sit != ' ')
	{
		sit--;
		count++;
	}
	return count;
}

int main()
{
	string s("hello world");
	//string s2;
	//ReverseString(s);
	//int count = GetLen(s);
	//cout << count << endl;
	string s1("bitekeji");
	string::iterator sit = s1.begin();
	while (sit != s1.end())
	{
		cout << *sit << endl;
		++sit;
	}
	return 0;
}

