#include <iostream>
#include <map>
#include<functional>
#include<string>
#include<set>
using namespace std;

void testMap()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(2, 3));
	m1.insert(make_pair(0, 1));
	m1[5] = 1;
	auto dit = m1.begin();

	//operator[]
	//�ȴ���pair Ȼ�����һ�����룬����һ��pair Ȼ���õ�����first �õ������� �ڽ����� Ȼ���õ�second  ���=�Ž����޸�


	//map��ֵ�������ظ�����
	while (dit != m1.end())
	{
		cout << dit->first<<""<<dit->second<<endl;
		dit++;
	}

}

void testmap()
{
	//map<int, string> m1; //greater<int> ����º��� �Ӵ�С����
	map<int, string, greater<int>> m1;
	m1[8] = "�й�";
	m1[2] = "����";
	m1[1] = "de��";
	m1[2] = "����";
	m1[2] = "ee��";
	m1[3] = "����";
	for (const auto& e : m1)
	{
		cout << e.first << ""<< e.second << endl;
	}
	//����������ʱ�临�Ӷ�Ϊlog��n)���߶��й�
	int key;
	//count �жϼ�ֵ�治���ڣ���
	/*while (cin>>key)
	if (m1.count(key))
	{
		cout << key << "---->" << m1[key] << endl;
	}
	else
	{
		cout << "not dind key:" << key << endl;
	}*/
	cin >> key;
	if (m1.find(key) != m1.end())
	{
		cout << m1[key] << endl;
	}
}
void test()
{
	//multimap<int, string, greater<int>> m1;
	multimap<int, string> m1;
	//multimap ���ṩ[]��������Ϊkey��Ψһ
	m1.insert(make_pair(1, "�й�"));
	m1.insert(make_pair(2, "����"));
	m1.insert(make_pair(3, "����"));
	m1.insert(make_pair(4, "�¹�"));
	/*cout << m1.count(1) << endl;
	for (const auto &e : m1)
	{
		cout << e.first << "--->" << e.second << endl;
	}*/

	//low_bound ���ص�һ��<= �ĵ�����
	auto mit = m1.lower_bound(3);
	cout << mit->first << "" << mit->second << endl;
	cout << endl;

	//upper_bound ���ص�һ��>�ĵ�����
	mit = m1.upper_bound(3);
	cout << mit->first << "" << mit->second << endl;
}
void testSet()
{
	////set  ֵ�������޸�  ֻ����ɾ�������
	//set<int> s1;
	//s1.insert(1);
	//s1.insert(10);
	//s1.insert(18);
	//s1.insert(1);
	//s1.insert(2);
	//s1.insert(3);
	////set ȥ�ظ�
	//for (const auto&e : s1)
	//{
	//	cout << e << endl;
	//}
	multiset<int> s1;
	s1.insert(1);
	s1.insert(10);
	s1.insert(18);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	//set ȥ�ظ�
	for (const auto&e : s1)
	{
		cout << e << endl;
	}
}
int main()
{
	testSet();
	return 0;
}