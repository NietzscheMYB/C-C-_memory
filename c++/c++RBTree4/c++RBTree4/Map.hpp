#pragma once

#include "RBTree.h"


namespace bite
{
	//ֻ��Ҫ��װһ�������
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;//���������ʵ�ʴ�ŵ�Ԫ��
		struct  KeyOfValue
		{
			const K& operator()(const ValueType&data)
			{
				return data.first;
			}
		};
	public:
		//ǣ����������ȡ����Ҫ��typename��������������ܻص��ɾ�̬��Ա������
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;

	public:
		map()
			:_t()
		{}
		//map����������������������Ӧ����һ���ģ���
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
		}

		size_t size()const
		{
			return _t.Size();
		}

		bool empty()const
		{
			return  _t.Empty();
		}

		iterator find(const K& key)
		{
			return _t.Find(make_pair(key,V()));
		}

		//V& operator[](const K& key)
		//{
		//	return (*((this->insert(make_pair(key, V()))).first));
		//}

	private:
		RBTree<ValueType,KeyOfValue> _t;
	};
}

#include<string>
using namespace std;
#include<iostream>
void TestMap()
{
	bite::map<string, string> m;
	m.insert(pair<string, string>("2222", "1111"));
	m.insert(make_pair("1111", "1111"));

	//m["0000"] = "0000";
	
	cout << m.size() << endl;
	//�Լ�д����������ʹ��auto��ӡ�Ļ�
	//����ʹ��begin��end
	for (auto e : m)
	{
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;

}