//#include<iostream>
//#include<string>
//#include<cstring>
//#include<assert.h>
//using namespace std;
//class String
//{
//public:
//	String(const char* str="")
//	{
//		//����string������������nullptrָ�룬��Ϊ����Ƿ����˴�������
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str)+1];
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
//
//void TestString()
//{
//	String s1("hello world!!");
//	String s2(s1);
//}
//
//int main()
//{
//	TestString();
//	return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<string>
//#include<assert.h>
//using namespace std;
////��ͳд����String��
//class String{
//public:
//	String(const char* str="")
//	{
//		//����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����ж���
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])//��������ռ䣬������������ռ�
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this !=&s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;  //�ͷ�ԭ���ռ�
//			_str = pStr;//���µĿռ�ĵ�ַ
//		}
//		return *this;
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

//#include<iostream>
//#include<cstring>
//#include<string>
//#include<assert.h>
//using namespace std;
//class String{
//public:
//	String(const char* str="")
//	{
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str,str);
//	}
//	String(const String&s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(String s)
//	{
//		swap(_str, s._str);
//		return *this;
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


#include<iostream>
#include<cstring>
#include<string>
#include<assert.h>
using namespace std;
class String
{
public:
	typedef char* Iterator;
	friend ostream& operator<<(ostream&_cout,String&s);

	String(const char* str = "")
	{
		//����string�����ʱ���������nullptrʱ����Ϊ�Ƿ������϶���
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_size = strlen(str);  //ȷ������
		_capacity = _size;//ȷ������
		_str = new char[_capacity+1];//����ռ�
		strcpy(_str, str);//����ֵ
	}
	String(const String&s)
		:_str(new char[s._capacity+1]) //�����µĿռ�
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);//ֵ����
	}
	String& operator=(const String& s)
	{
		if (this != &s) //����������
		{
			char* pStr = new char[s._capacity+1];//������һ������
			strcpy(pStr, s._str);
			this->_size = s._size;
			this->_capacity = s._capacity;
			delete[] this->_str;
			this->_str = pStr;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	//Iterator
	Iterator Begin()
	{
		return _str;
	}
	Iterator End()
	{
		return _str + _size;
	}
	//modify
	void PushBack(char c)
	{
		if (_size == _capacity)//�������
		{
			Reserve(_capacity * 2);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	void Append(size_t n, char c)
	{
		for (size_t i = 0; i < n; ++i)
		{
			PushBack(c);
		}
	}
	String& operator+=(char c)
	{
		//if (_size == _capacity)//�������
		//{
		//	Reserve(_capacity * 2);
		//}
		//this->_str[_size++] = c;
		//this->_size = '\0'
		PushBack(c);
		return *this;
	}
	void Clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	const char* C_str() const
	{
		return _str;
	}

	//capacity;
	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}
	bool Empty() const
	{
		return 0 == _size;
	}
	void Resize(size_t newSize, char c = char())
	{
		if (newSize > _size)
		{
			//���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
			if (newSize > _capacity)
			{
				Reserve(newSize);
			}
			memset(_str+_size,c,newSize-_size);
		}
		_size = newSize;
		_str[newSize] = '\0';
	}
	void Reserve(size_t newCapacity)
	{
		//������������ھ��������򿪱ٿռ�
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);

			//�ͷžɿռ䣬ʹ���¿ռ�
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

ostream& operator<<(ostream&_cout, String& s)
{
	cout << s._str;
	return _cout;
}

void Test1()
{
	String s1;
	String s2("hello world");
	String s3(s2);
	s1 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

void Test2()
{
	String s1("hello world");
	s1.PushBack('x');
	s1.PushBack('q');
	s1.Append(3,'6');
	cout << s1 << endl;
	s1 += '8';
	cout << s1 << endl;
	cout << s1.Capacity() << endl;
	cout << s1.Size() << endl;
	cout << s1.C_str() << endl;
}

int main()
{
	Test2();
	return 0;
}
