#include <iostream>
#include <vector>
using namespace std;

void PrintVector( vector<int>&  v)   //��ӡ������  ��ֹ���ɵ�ֵ̫��
{
	//ʹ��const���������б�����ӡ
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}
int main()
{
	vector<int> v;//vector�������� ʹ��Ҫ������
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//ʹ�õ��������б�����ӡ
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	
	//ʹ�õ����������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);
	return 0;

}