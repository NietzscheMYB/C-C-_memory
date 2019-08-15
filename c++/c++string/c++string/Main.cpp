#include<iostream>
#include<string>
using namespace std;
void TestString()
{
	string s1;//构造一个string空类对象s1
	string s2("hello bit");//用c字符串的形式构造一个string类s2
	string s3(10, 'a');//用10个字符‘a’构造string类对象s3
	string s4(s2);//拷贝构造s4
	string s5(s3, 5);//用s3中前5个字符构造string对象s5
}
void TestString1()
{
	string s("hello world");
	//string s;
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的字符串清空，注意情空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;


	//将s中有效字符个数增加到10个，多出位置用‘a’进行填充
	//‘aaaaaaaaaa’
	s.resize(10,'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中有效字符个数增加到15个，多出位置用缺省值‘\0’进行填充
	//'aaaaaaaaaa\0\0\0\0\0'
	//注意此时s中有效字符个数已经增加到15个
	//s.resize(15,'1');
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将s中的有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;


	//增大
	s.resize(16);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}


void TestString2()
{
	string s;
	//测试reserve是否会改变string中有效元素的个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	//测试resever参数小于string的底层大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

int main()
{
	TestString2();
	return 0;
}