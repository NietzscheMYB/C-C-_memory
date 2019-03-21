//
// Created by zhengwei.
//
/*
���⣺��������

С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
�����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��

����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�

����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��

����
----
һ�����ڣ���ʽ��"AA/BB/CC"��  (0 <= A, B, C <= 9)

���
----
������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�

��������
----
02/03/04

�������
----
2002-03-04
2004-02-03
2004-03-02

��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

ע�⣺
main������Ҫ����0;
ֻʹ��ANSI C/ANSI C++ ��׼;
��Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
���������ĺ���������ȷ����Դ�ļ��� #include <xxx>
����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύ����ʱ��ע��ѡ�����������������ͺͱ��������͡�

*/

//1960��1��1����2059��12��31��
//AA/BB/CC
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include <set>
void i2s(int i, string &s)
{
	stringstream ss;
	ss << i;
	ss >> s;
}

bool check(int a)
{
	return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}
string f(int a, int b, int c)
{
	if (a >= 0 && a <= 59)a += 2000;
	else if (a >= 60 && a <= 99)a += 1900;
	else return "";
	bool Is_Leap = check(a);
	if (b<1 || b>12)
	{
		return "";
	}
	if (c<1 || c>31)
	{
		return "";
	}
	switch (b)
	{
	case 2:
		if (Is_Leap&&c > 29) return "";
		if (!Is_Leap&&c > 28) return "";
		break;
	case 4:
		if (c > 30) return "";
		break;
	case 6:
		if (c > 30) return "";
		break;
	case 9:
		if (c > 30) return "";
		break;
	case 11:
		if (c > 30) return "";
		break;
	}
	string _a, _b, _c;
	i2s(a, _a);
	i2s(b, _b);
	i2s(c, _c);
	if (_b.length() == 1)_b = "0" + _b;
	if (_c.length() == 1)_c = "0" + _c;

	return _a + "-" + _b + "-" + _c;
}
int main()
{
	string in;
	cin >> in;
	int a = 0, b = 0, c = 0;
	a = (in[0] - '0') * 10 + (in[1] - '0');
	b = (in[3] - '0') * 10 + (in[4] - '0');
	c = (in[6] - '0') * 10 + (in[7] - '0');

	string case1 = f(a, b, c);
	string case2 = f(c, a, b);
	string case3 = f(c, b, a);

	set<string>ans;
	if (case1 != "") ans.insert(case1);
	if (case2 != "") ans.insert(case2);
	if (case3 != "") ans.insert(case3);

	for (set<string>::iterator iter = ans.begin(); iter != ans.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}