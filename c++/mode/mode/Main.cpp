#include <iostream>
using namespace std;
//����ģ��
template <class T1,typename T2>
T1 Add(const T1& a,const T2& b)
{
	return a + b;
}
////������ģ���������Ϊ����ʹ��
//template<class T,size_t N>
//class Array()
//{
//	T a[N];
//};
//
////��̬����
//void test1()
//{
//	//ջ�Ͽ��� ������ �˷ѿռ�
//	Array<int, 10> arr1;
//	Array<double, 10> arr2;
//
//}
template<class T>
bool isEqual(T& a, T& b)
{
	return a == b;
}
template<class T>
bool isGreater(const T &a,const T& b)
{
	return a > b;
}
//�ػ�ģ��
//1.��Ҫ��һ���Ѿ����ڵ�ͨ��ģ�庯��
//2.ģ�����Ϊ��
//3.����������Ҫ��ʾ�ػ�������
//4.�ػ������͸�ʽҪ��ͨ��ģ�������ʽһ��
//T��λ��ȫ��Ϊ�ػ�������
//5.һ�㲻ȥд����ģ����ػ��汾������ģ����ػ��Ƚϸ��ӣ��ᱨ��һЩ��ֵĴ���
//�����Ӧ����ģ�崦���˻��߱�������ͣ�ȥʵ��һ����Ӧ���͵���ͨ����
template<>
bool isGreater<char*&>( char*&const  a, char*&const b)//��const��ʱ���ֹconst���δ�λ ����д
{
	if (strcmp(a, b) > 0)                           //����д����ģ�����͵��ػ��ȽϿ�
	{											  //����������ǲ��ã�const
		return true;
	}
	return false;
}
//��һ���������ͨ���͵ľͲ������ģ�庯��
bool isGreater(char*&  a, char*& b)
{
	if (strcmp(a, b) > 0)
	{
		return true;
	}
	return false;
}
void test2()
{
	int a = 1, b = 1;
	cout << isEqual(a, b) << endl;
	char* str1 = "hello";
	char* str2 = "world";
	cout << isEqual(str1, str2) << endl;//�Ƚϵ�ַ ջ�������� ��ַ��С
	char* str3 = "hello";
	cout << isGreater(str1, str3) << endl;
	cout << isGreater(str1, str3) << endl;
}

//��ģ���ػ�
//1.ȫ�ػ�
//

template<class T1, class T2> class Data 
{ public:   Data() 
	{ 
		cout << "Data<T1, T2>" << endl;
	} 
private:    T1 _d1;    T2 _d2; 
};

template<> class Data<int, char> { public:    Data() { cout << "Data<int, char>" << endl; } private:    T1 _d1;    T2 _d2; };

//���ػ�
//��ĳ�����ͽ����ػ���һ���������ػ���һ����û���ػ�
//1.�����ػ�
//2.��ģ���������һ�������� //ֻҪ����һ�¾ͻ����Ӧ����


//�������ݣ�����
//memcpy��һƬ�ڴ濽����Ч�ʸ�
//��ֵ���� =��ÿ��Ԫ�����ο�����Ч�ʵף�o(n)
// STL ��������·��
// 1.�������� memcpy  2.�Զ������� ��ֵ����
//pod: plain old data---�������� �ϵ����ͣ�������е����ͣ�   ��Ե� �Զ������� �µ�
template<class T>
void Copy(T* dst, const T* src,size_t sz, bool isPoDtype)
{
	if (isPoDtype)
	{
		memccpy(dst, src, sizoef(T)*sz);
	}
	else
	{
		for (int i = 0; i < sz; i++)
		{
			dst[i] = src[i];
		}
	}
}

struct TrueType{
	static bool Get()
	{
		return true;
	}
};
struct FalseType
{
	static bool Ger()
	{
		return false;
	}
};


//������ȡ
template <class T>
struct TypeTraits
{
	typedef FalseType _isPodType;

};

//ģ���ػ�
template<>
struct TypeTraits<char>
{
	typedef TrueType _isPodType;
};



//RTTI: run time type information/ indetification
//RTTI: typeid typeid(a).name
//bool isPODType���� ȱ��Ч�ʵ� ʱ�临�Ӷ�Ϊo(n2)
bool isPODType(const char* tp)  //o(n2) Ч�ʵ�
{
	static char* typyArr[] = { "int", "double", "float", "char", "..." };
	for (int i = 0; i < sizeof(typyArr) / sizeof(typyArr[0]); i++)
	{
		if (strcmp(tp, typyArr[i]))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//test1();
	test2();
	return 0;
}