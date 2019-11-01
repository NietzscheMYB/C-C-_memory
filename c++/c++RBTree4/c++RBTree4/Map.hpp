#pragma once

#include "RBTree.h"


namespace bite
{
	//只需要封装一个红黑树
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;//往红黑树中实际存放的元素
		struct  KeyOfValue
		{
			const K& operator()(const ValueType&data)
			{
				return data.first;
			}
		};
	public:
		//牵扯到作用域取别名要加typename，否则编译器可能回当成静态成员处理！！
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;

	public:
		map()
			:_t()
		{}
		//map迭代器与红黑树迭代器类型应该是一样的！！
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
	//自己写的容器，想使用auto打印的话
	//必须使用begin，end
	for (auto e : m)
	{
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;

}