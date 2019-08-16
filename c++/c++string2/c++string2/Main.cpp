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

	//s2[0]='H' ; 编译失败，因为const类型对象不能修改
}

void TestString2()
{
	string str;
	str.push_back(' ');//在str后面插入空格
	str.append("hello");//在str后面追加一个字符串hello
	str += 'b';//在str后追加一个字符‘b’
	str += "it";//在str后追加一个字符串“it”

	cout << str << endl;
	cout << str.c_str() << endl;//以c语言的方式来打印字符串

	//获取file的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');//从后开始找字符为.
	string suffix(file.substr(pos, file.size() - pos));//截取字符串
	cout << suffix << endl;

	//nops是string里面的一个静态成员变量
	//static const size_t npos=-1；
	//取出url中的域名
	//url统一资源定位符
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");//找到：//的位置
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);//从start位置开始找到第一个/的位置
	string address = url.substr(start, finish - start);
	cout << address << endl;

	//删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;



}


//利用reserve提高插入数据的效率，避免增容带来的开销
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