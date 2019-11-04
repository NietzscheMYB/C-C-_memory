#include<iostream>
using namespace std;

#if 0
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}

void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}

void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}

void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}


template<typename T>
void PerfectForward(T &&t)
{
	Fun(std::forward<T>(t));
}

int main()
{
	PerfectForward(10);//rvalue ref

	int a;
	PerfectForward(a);//lvaue ref
	PerfectForward(std::move(a));//rvalue ref

	const int b = 8;
	PerfectForward(b);//const lvalue ref
	PerfectForward(std::move(b));//const rvalue ref

	return 0;
}
#endif

#include<algorithm>
#include<functional>
#include<string>
#if 0
int main()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };

	//Ĭ���������򣡣�
	sort(array, array + sizeof(array) / sizeof(array[0]));
	
	//�ı�����Ž���
	sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
	return 0;
}
#endif


#if 0
//���������Ԫ�����Զ������ͣ���Ҫ�û�����ʱ����ȽϹ���

struct Goods
{
	string _name;
	double _price;
};

struct Compare
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};

int main()
{
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	//sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());//Compare()�º������������󣬾��Ƕ�operator()��ʹ�ã����ɴ���һ����������Ȼ��ʹ��operator()

	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& l,const Goods& r){
		return l._price < r._price; });

	return 0;
}
#endif


#if 0
int main()
{
	//��򵥵�lambda���ʽ����lambda���ʽû���κ�����
	[]{};

	//ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint

	int a = 3, b = 4;
	[=]{return a + 3; };

	//ʡ���˷���ֵ���ͣ��޷���ֵ����
	auto fun1 = [&](int c){b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;

	//�����ֶ������Ƶ�lambda����
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;

	//���Ʋ�׽x
	int x = 10;
	auto add_x = [x](int a)mutable{x *= 2; return a + x; };
	cout << add_x(10) << endl;

	return 0;
}
#endif

#if 0
typedef void(*PF)()  ;
int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };

	//f1=f2;//����ʧ��---->��ʾ�Ҳ���operator=()

	auto f3(f2);
	f3();

	//���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
	PF x= f2;
	x();
	return 0;
}
#endif

class Rate
{
public:
	Rate(double rate)
		:_rate(rate)
	{}
	double operator()(double money,int year)
	{
		 return money*_rate*year;
	  
	}
private:
	 double _rate;
};

int main()
{
	//��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);
	 
	//�º���
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);
	return 0;
}















