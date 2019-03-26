#include <iostream>
#include <string>
#include <assert.h>
#include <cstring>
using namespace std;
void test1()
{
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("/w");//str.find()�������ַ���
	cout << start << endl;

	//ɾ��url��Э��ǰ׺
	size_t pos1 = url.find("://");
	size_t pos2 = url.find("/re");
	url.erase(pos2);
	url.erase(0, pos1 + 3);
	cout << url << endl;
}

//string���ģ��ʵ��
//class String
//{
//public:
//	String(const char *str = "")
//	{
//		//����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ�
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
//	/*����д������ s2��Ҫ����String
//	�࿽�����캯��������������û����ʾ����
//	��ʹ��ϵͳ�ϳɵ�Ĭ�Ͽ������캯��
//
//	��TestString��������ʱ����Ҫ��s1��s2���ٵ���
//	������s2����ѹջ����s2����_ptr��ָ�Ŀռ��ͷŵ�
//	��s2����ɹ����٣���s1��_ptr��ΪҰָ�룬��
//	����s1ʱ����
//	*/
//
//	//s1 s2����һ���ڴ�ռ䣬���ͷ�ͬһ�ռ�ʱ
//	//������ͷ�����������
//	//ǳ����
//}

/*ǳ���� Ҳ��Ϊλ������������ֻ�ǽ������е�ֵ
������������������й�����Դ�����ͻᵼ��
���������һ����Դ����һ����������ʱ�ͻὫ��
��Դ�ͷŵ�������ʱ��һЩ����֪������Դ�Ѿ����ͷţ�
��Ϊ����Ч�����Ե���������Դ���в���ʱ���ͻᷢ������Υ��
*/


//���
//��ÿ���������������Դ
//��֤�������֮��
//����������Դ����ɶ���ͷ���ɳ����������

class String
{
public:
	String(const char *str = "")
	{
		//����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ�
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
		if (this != &s)//�����Լ����Լ���ֵ
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