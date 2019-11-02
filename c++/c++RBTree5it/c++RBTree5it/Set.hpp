#pragma once

#include "RBTree.h"

namespace bite
{
	//只需要封装一个红黑树
	template<class K>
	class set
	{
		typedef K ValueType;//往红黑树中实际存放的元素
		struct KeyOfValue
		{
			const K& operator()(const ValueType&data)
			{
				return data;
			}
		};
	public:
		//牵扯到作用域取别名要加typename，否则编译器可能会当成静态成员处理！！
		typename typedef RBTree<ValueType, KeyOfValue>::iterator iterator;
	public:
		set()
			:_t()
		{

		}
		//set的迭代器与红黑树的迭代器类型应是一样的！！
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		pair<iterator,bool> insert(const ValueType&data)
		{
			return _t.Insert(data);
		}
		size_t size()const
		{
			return _t.Size();
		}
		bool empty()const
		{
			return _t.Empty();
		}
		iterator find(const K&key)
		{
			return _t.Find(key);
		}

	private:
		RBTree<ValueType,KeyOfValue> _t;
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
	m.insert("b111");
	m.insert("a111");
	m.insert("m111");
	m.insert("汉");
	m.insert("m111");

	cout << m.size() << endl;
	for (auto e : m)
	{
		cout << e << " " << endl;
	}
	cout << endl;

}