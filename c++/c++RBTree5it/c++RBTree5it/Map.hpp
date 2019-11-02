#pragma once

#include"RBTree.h"

namespace bite
{
	//只需要封装一个红黑树
	template<class K, class V>
	class map
	{
	public:
		typedef pair<K, V> ValueType;//红黑色中实际存放的元素
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
		//map的迭代器类型与红黑树迭代器类型是一样的！！
		//则继续使用就行
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		//插入！！
		//插入是插入键值对！！
		//根据map的insert插入返回值是pair<iterator,bool>
		//所以！！
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
		}
		bool empty()
		{
			return _t.Empty();
		}
		//map查找！！
		//通过key找到value！！
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