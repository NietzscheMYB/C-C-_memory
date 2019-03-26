#include <iostream>
#include <string>
#include <assert.h>
#include <cstring>
using namespace std;
void test1()
{
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("/w");//str.find()可以找字符串
	cout << start << endl;

	//删除url的协议前缀
	size_t pos1 = url.find("://");
	size_t pos2 = url.find("/re");
	url.erase(pos2);
	url.erase(0, pos1 + 3);
	cout << url << endl;
}

//string类的模拟实现
//class String
//{
//public:
//	String(const char *str = "")
//	{
//		//构造string类对象时，如果传递nullptr指针，认为程序非法
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};

//void TestString()
//{
//	String s1("hello bit!");
//	String s2(s1);
//
//
//	/*这样写有问题 s2需要调用String
//	类拷贝构造函数来创建，该类没有显示定义
//	则使用系统合成的默认拷贝构造函数
//
//	当TestString函数结束时，需要将s1与s2销毁调，
//	先销毁s2（后压栈），s2将其_ptr所指的空间释放掉
//	，s2对象成功销毁，但s1中_ptr成为野指针，当
//	销毁s1时出错
//	*/
//
//	//s1 s2公用一块内存空间，在释放同一空间时
//	//被多次释放引起程序崩溃
//	//浅拷贝
//}

/*浅拷贝 也成为位拷贝，编译器只是将对象中的值
拷贝过来。如果对象中管理资源，最后就会导致
多个对象共享一份资源，当一个对象销毁时就会将该
资源释放掉，而此时另一些对象不知道该资源已经被释放，
以为还有效，所以当继续对资源进行操作时，就会发生访问违规
*/


//深拷贝
//给每个对象独立分配资源
//保证多个对象之间
//不会因共享资源而造成多次释放造成程序崩溃问题

class String
{
public:
	String(const char *str = "")
	{
		//构造string类对象时，如果传递nullptr指针，认为程序非法
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String&s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String&s)
	{
		if (this != &s)//放在自己给自己赋值
		{
			char *pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	String s1("hello world");
	String s2(s1);
	String s3 = s1;
	
	return 0;
}