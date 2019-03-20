#include <iostream>
#include <string>
using namespace std;

void test1()
{
	string s;
	string s2("keda");
	s.push_back('h');  //插入字符
	s += 'e';
	s.append("helllo");//插入字符串
	s += "hello";
	s += s2;          //+=  既能添加字符，又能加字符串  相当于尾插！！！
	cout << s << endl;
	s2.assign(s);  //assign 改变自身的内容
	
	cout << s2 << endl;
}
//insert
void test2()
{
	string s("world");
	s.insert(1, "hello ");//从某个位置开始插入字符串
	cout << s << endl;
	//string s2;
	//s2.insert(0,s, 3, 5);//从某个位置开始插入某个字符串的某个长度
	//cout << s2 << endl;
	//s.erase(0, 1);//从某个位置删除几个字符
	//cout << s << endl;
	//s.erase(0,15);  //从某个位置删除几个字符
	//cout << s << endl;
	string s4("bite");
	//s.replace(0, 2, s4);  //从第0个位置数两个，换成s4


	//swap(s, s4);  //这个是模板！！！
	//cout << s << endl;
	//cout << s4 << endl;
	//s.swap(s4);//交换指针！！
	//cout << s << endl;
	//cout << s4 << endl;

	//const char *ps=s4.c_str();//c_str返回一个字符串首地址
	//cout << ps << endl;
}
void test3()
{
	string file("test.cpp");
	//string s = file.substr(4, 4);//从第4个开始 拿4个不算第4个
	size_t pos = file.find('.');
	string s = file.substr(pos, file.size() - pos);
	cout << s << endl;

	//s.find()///可以找字符串！！！！
}

//全在cplusplus网上看看就行！！！！
//常用接口
//迭代器 正向 beign end
//容量    size capacity  reserve(增容)
//元素访问 operate[]
//改变  operate+=  insert erease
//string operations c_str()获取c风格的字符串 find refind substr
//非成员 了解吧1

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
	string::iterator sit = s.begin();    //getline(cin,s)!!!遇到空格不结束 cin 遇到空格结束
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

