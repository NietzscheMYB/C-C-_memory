#pragma once

#include "RBTree.h"


namespace bite
{
	//ֻ��Ҫ��װһ�������
	template<class K>
	class set
	{
		typedef K  ValueType;//���������ʵ�ʴ�ŵ�Ԫ��
		struct  KeyOfValue
		{
			const K& operator()(const ValueType&data)
			{
				return data;
			}
		};
	public:
		//ǣ����������ȡ����Ҫ��typename��������������ܻص��ɾ�̬��Ա��������
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;

	public:
		set()
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
			return _t.Find(key);
		}


	private:
		RBTree<ValueType, KeyOfValue> _t;
	};
}

#include<string>
using namespace std;
#include<iostream>
void TestSet()
{
	bite::set<string> m;
	m.insert("2222");
	m.insert("1111");

	//m["0000"] = "0000";

	cout << m.size() << endl;
	//�Լ�д����������ʹ��auto��ӡ�Ļ�
	//����ʹ��begin��end
	for (auto e : m)
	{
		cout << e  <<" " << endl;
	}
	cout << endl;

}