//#include<iostream>
//using namespace std;
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}

#include<iostream>
using namespace std;
template<class T>
T add(const T& left,const T& right)
{
	return left + right;
}


//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	add(a1, a2);
//	add(d1, d2);
//
//	/*
//	add(a1,d1);
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ�����ͣ�ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��
//	d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T���������޷�ȷ���˴����׽�Tȷ��Ϊint����double������
//	*/
//
//	add(a1, (int)d1);
//	return 0;
//}

int main()
{
	int a1 = 2, a2 = 3;
	double b1 = 3.3;
	add<int>(a1, b1);//��ʾʵ����
	return 0;
}