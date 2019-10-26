#include<iostream>
#include<map>
#include<string>
using namespace std;
void TestMap()
{
	map<string, string> m;//��map
	//������ǲ����ֵ�ԣ��ȹ����ֵ��
	m.insert(pair<string, string>("�ν�", "��ʱ��"));//�����ֵ��
	m.insert(pair<string, string>("����", "������"));//�����ֵ��

	//insert �����Ǹ�pair<iterator,bool>
	//iterator:����map key---value �ļ�ֵ��
	//bool : insert �����Ƿ�ɹ�

	//�����ֵ��2��
	//1.pair  2.make_pair
	//ֱ��make�����ֵ��
	auto ret = m.insert(make_pair("�����","ĸҹ��"));
	if (ret.second)
	{
		cout << ret.first->first << "--->" << ret.first->second << endl;
	}
	ret = m.insert(pair<string, string>("����", "��ţ"));
	if (ret.second)
	{
		cout << ret.first->first << "--->" << ret.first->second << endl;
	}
	cout << ret.first->first << "--->" << ret.first->second << endl;


	cout << m.size() << endl;
	cout << m["����"] << endl;//�±����������
	//�û��ṩkey--->[]  ����key��Ӧ��value
	m["����"] = "��ţ"; //�±������
	cout << m["����"] << endl;
	m["�ֳ�"] = "����ͷ";//��Ҳ�ǲ�����������key�����ڣ�Ҳ���в���

	cout << m.size() << endl;

}
void TestMap2()
{
	int array[] = {3,1,9,4,0,7,6,2};
	map<int, int> m;
	for (auto e : array)
	{
		m.insert(make_pair(e, e));
	}
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.erase(1);
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}

}
int main()
{
	TestMap2();

	return 0;
}