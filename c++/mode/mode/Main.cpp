#include <iostream>
using namespace std;
//类型模板
template <class T1,typename T2>
T1 Add(const T1& a,const T2& b)
{
	return a + b;
}
////非类型模板参数，作为常量使用
//template<class T,size_t N>
//class Array()
//{
//	T a[N];
//};
//
////静态数组
//void test1()
//{
//	//栈上开辟 不适用 浪费空间
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
//特化模板
//1.需要有一个已经存在的通用模板函数
//2.模板参数为空
//3.函数名后面要显示特化的类型
//4.特化的类型格式要和通用模板参数格式一致
//T的位置全化为特化的类型
//5.一般不去写函数模板的特化版本，函数模板的特化比较复杂，会报出一些奇怪的错误
//建议对应函数模板处理不了或者报错的类型，去实现一个对应类型的普通函数
template<>
bool isGreater<char*&>( char*&const  a, char*&const b)//加const的时候防止const修饰错位 这样写
{
	if (strcmp(a, b) > 0)                           //不用写函数模板类型的特化比较坑
	{											  //这个函数还是不用＋const
		return true;
	}
	return false;
}
//有一个定义的普通类型的就不会调用模板函数
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
	cout << isEqual(str1, str2) << endl;//比较地址 栈向下增长 地址减小
	char* str3 = "hello";
	cout << isGreater(str1, str3) << endl;
	cout << isGreater(str1, str3) << endl;
}

//类模板特化
//1.全特化
//

template<class T1, class T2> class Data 
{ public:   Data() 
	{ 
		cout << "Data<T1, T2>" << endl;
	} 
private:    T1 _d1;    T2 _d2; 
};

template<> class Data<int, char> { public:    Data() { cout << "Data<int, char>" << endl; } private:    T1 _d1;    T2 _d2; };

//半特化
//对某个类型进行特化，一部分类型特化，一部分没有特化
//1.部分特化
//2.对模板参数做进一步的限制 //只要类型一致就会调对应类型


//容器增容，拷贝
//memcpy：一片内存拷贝，效率高
//赋值拷贝 =，每个元素依次拷贝，效率底：o(n)
// STL 拷贝分两路：
// 1.内置类型 memcpy  2.自定义类型 赋值拷贝
//pod: plain old data---内置类型 老的类型（本身就有的类型）   相对的 自定义类型 新的
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


//类型萃取
template <class T>
struct TypeTraits
{
	typedef FalseType _isPodType;

};

//模板特化
template<>
struct TypeTraits<char>
{
	typedef TrueType _isPodType;
};



//RTTI: run time type information/ indetification
//RTTI: typeid typeid(a).name
//bool isPODType（） 缺陷效率低 时间复杂度为o(n2)
bool isPODType(const char* tp)  //o(n2) 效率低
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