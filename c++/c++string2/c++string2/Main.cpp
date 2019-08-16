#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	char a1[] ="";
//	char a2[] = { '\0' };
//	char a3[] = { '\\0' };
//	char b1[] = "\0";
//	char b2[] = "\\0";
//	cout << b2[0] << endl;
//	return 0;
//}

void TestString()
{
	string s1("hello world");
	const string s2("hello world");
	cout<<s1<< " "<< s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	
	s1[0] = 'H';
	cout << s1 << endl;
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}

	//s2[0]='H' ; ����ʧ�ܣ���Ϊconst���Ͷ������޸�
}

void TestString2()
{
	string str;
	str.push_back(' ');//��str�������ո�
	str.append("hello");//��str����׷��һ���ַ���hello
	str += 'b';//��str��׷��һ���ַ���b��
	str += "it";//��str��׷��һ���ַ�����it��

	cout << str << endl;
	cout << str.c_str() << endl;//��c���Եķ�ʽ����ӡ�ַ���

	//��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');//�Ӻ�ʼ���ַ�Ϊ.
	string suffix(file.substr(pos, file.size() - pos));//��ȡ�ַ���
	cout << suffix << endl;

	//nops��string�����һ����̬��Ա����
	//static const size_t npos=-1��
	//ȡ��url�е�����
	//urlͳһ��Դ��λ��
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");//�ҵ���//��λ��
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);//��startλ�ÿ�ʼ�ҵ���һ��/��λ��
	string address = url.substr(start, finish - start);
	cout << address << endl;

	//ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;



}


//����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
//
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		cout << s << endl;
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}



int main()
{
	TestPushBack();
	return 0;
}