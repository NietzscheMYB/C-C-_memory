#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a+sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test2()
{
	int a[] = { 1, 2, 3, 4 };
	vector <int> v(a, a + sizeof(a) / sizeof(int));
	//ʹ��find����3���ڵ�λ�õ�iteator
	vector<int>::iterator pos =find(v.begin(), v.end(), 3);
	//ɾ��posλ�õ����ݣ�����pos������ʧЧ
	v.erase(pos);
	cout << *pos << endl;//�˴ε��·Ƿ�����

	//��posλ�ò������ݣ�������pos������ʧЧ
	//insert�ᵼ�µ�����ʧЧ������Ϊinsert
	//���ܻ����ݣ����ݺ�pos��ָ��ԭ���Ŀռ�
	//��ԭ���Ŀռ��Ѿ��ͷŵ���
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl;//�˴����·Ƿ�����


}
int main()
{
	/*size_t sz;
	std::vector <int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}*/

	/*size_t sz;
	std::vector <int> foo;
	sz = foo.capacity();
	foo.reserve(100);
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}*/
	test1();
	return 0;
}