#include <iostream>
//#include "a.h"
#include <fstream>
using namespace std;

//int main()
//{
//	//int d;
//	////无论什么类型，都调用同一个函数，需要指明变量的类型
//	//scanf("%d", &d);
//	//char c;
//	//scanf("%c", &c);
//	////cin 类型：istream
//	////istream 重载了>>运算符
//	////对于不同的内置类型，cin 调用的是不同的>>运算符重载函数,不需要指定变量的类型
//	//cin >> d;
//	//cin >> c;
//	//cin.operator>>(d);
//	//cin.operator>>(c);
//	cout << "cout" << endl;
//	cerr << "cerr" << endl;
//	clog << "clog" << endl;
//}


//fopen fwrite  fread
struct Info
{
	char ip[20];
	int port;
};
class Config{
public:
	Config(string filename)
		:_filename(filename){}
	void ReadBin(Info& info)
	{
		ifstream fin(_filename.c_str());
		fin.read((char*)&info, sizeof(info));
		fin.close();
		cout << info.ip << endl;
		cout << info.port << endl;
	}
	void WriteBin(Info& info)
	{
		ofstream fout(_filename.c_str());
		fout.write((char*)&info, sizeof(info));
		fout.close();
		
	}
private:
	string _filename;
};
void test1()
{
	Info info;
	strcpy(info.ip, "www.baidu.com");
	info.port = 80;
	Config cfg("Config.txt");
}
int main()
{
	test1();
	return 0;
}