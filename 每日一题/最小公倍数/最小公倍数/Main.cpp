#include<iostream>
#include<vector>
using namespace std;
//����С��������������� �ٳ������Լ����ok������

int Get(int a, int b)
{
	int r = 0;
	//շת���������������
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << a*b / Get(a, b);
	return 0;
}