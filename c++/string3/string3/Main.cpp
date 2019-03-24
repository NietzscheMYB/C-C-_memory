#include <iostream>
#include <string>
using namespace std;

void TestString()
{
	string str;
	str.push_back(' ');//在str后插入空格
	str.append("hello");//在str后面追加一个字符
	str += 'b';//在str后面追加一个字符
	str += "it";//在str后面追加一个字符串"it"

	//size_t是一种数据相关的无符号类型，它被设计的足够大以便能够
	//内存中任意对象的大小

	//cout << str << endl;
	//cout << str.c_str() << endl;

	//获取file的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');


	//str.substr()  截取字符串函数 得到一个字符串
	//参数是下标，
	//str.substr(3,5)//从下标为3的位置包括3 截取5个字符，
	//str.substr(3)//从下标为3的位置包括3，截取到末尾
	string sufffix(file.substr(pos, file.size() - pos));
	cout << sufffix << endl;
	cout << file.substr(6);

}
void TestString2()
{
	//nops是string里面的一个静态成员变量
	//static const size_t npos=-1;
	//取出url中的域名
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