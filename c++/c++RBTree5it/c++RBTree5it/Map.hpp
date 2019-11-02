#pragma once

#include"RBTree.h"

namespace bite
{
	//ֻ��Ҫ��װһ�������
	template<class K, class V>
	class map
	{
	public:
		typedef pair<K, V> ValueType;//���ɫ��ʵ�ʴ�ŵ�Ԫ��
		struct KeyOfValue
		{
			const K& operator()(const ValueType&data)
			{
				return data.first;
			}
		};
	public:
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;
	public:
		map()
			:_t()
		{}
		//map�ĵ���������������������������һ���ģ���
		//�����ʹ�þ���
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		//���룡��
		//�����ǲ����ֵ�ԣ���
		//����map��insert���뷵��ֵ��pair<iterator,bool>
		//���ԣ���
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
		}
		bool empty()
		{
			return _t.Empty();
		}
		//map���ң���
		//ͨ��key�ҵ�value����
		iterator find(const K&key)
		{
			return _t.Find(make_pair(key, V()));
		}
		size_t size()
		{
			return _t.Size();
		}
	private:
		RBTree<ValueType, KeyOfValue> _t;
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

	cout << m.size() << endl;

	for (auto e : m)
	{
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;

}