#pragma once
#include<vector>
#include<iostream>

using namespace std;

enum STATE{EMPTY,DELETE,EXIST};



template < class K ,class V>
struct HashNode
{
	pair < K, V> _kv;
	STATE _state=EMPTY;
};


template <class K,class V>
class HashTable
{
public:
	typedef HashNode<K, V>  Node;
	typedef Node* pNode;
	HashTable(size_t N = 5)
	{
		_table.resize(N);  //  [ ]
		_size = 0;
	}

	bool Insert(const pair<K, V>& kv)
	{
		CheckCapacity();
		//位置映射
		size_t index = kv.first % _table.size();
		while (_table[index]._state==EXIST)
		{
			//不允许key重复
			if (_table[index]._kv.first == kv.first)
			{
				return false;
			}
			++index;
			if (index == _table.size())
			{
				index = 0;
			}
		}
		
		_table[index]._kv = kv;
		_table[index]._state = EXIST;
		++_size;
		return true;
	}
	pNode Find(const K&key)
	{
		size_t index = key% _table.size();
		while (_table[index]._state!=EMPTY)
		{
			if (_table[index]._state == EXIST&&
				_table[index]._kv.first == key)
			{
				return &_table[index];
			}
			++index;
			if (index == _table.size())
			{
				index = 0;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		pNode ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}


	void CheckCapacity()
	{ 
		//判断是否达到负载值
		if (_table.size()==0||_size*10/_table.size()>=7)                      //_size/_table.size() 负载因子  减少哈希冲突
		{
			size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();
			HashTable<K, V> newHt(newC);
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					newHt.Insert(_table[i]._kv);
				}
			}
			_table.swap(newHt._table);
		}
	}
private:
	vector<Node> _table;
	size_t _size;
};


#if 0
template <class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;
	HashNode(const V& data)
		:_next(nullptr)
		, _data(data)
	{}
};

//前置声明
template<class K, class V, class KeyOfValue, class HashFun>
class HashTable;

/*
	KeyOfValue 仿函数类，获取data对应的key
	HashFun   仿函数类   获取key对应的hash值，本质上是返回key转换之后的整数值

*/

template<class K,class V,class KeyOfValue,class HashFun>
class HashTable
{
public:
	typedef HashNode<V> Node;
	typedef Node* pNode;

private:
	vector<pNode> _table;
	size_t _size = 0;
};

#endif



