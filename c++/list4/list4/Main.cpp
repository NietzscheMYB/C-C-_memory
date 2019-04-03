#include <iostream>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(const T&val = T())  //构造函数
	:_next(nullptr)
	, _prev(nullptr)
	, _data(val)
	{}
	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _val;
};

template <class T>
struct ConstListIterator
{
	typedef ListNode<T>* pNode;
	typedef ConstListIterator<T> self;
	pNode _node;

	//构造函数
	ConstListIterator(pNode node)
		:_node(node)
	{}

	//++iterator
	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	//移动到下一个节点的位置
	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	//--iterator
	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	//iterator--
	self operator--(int)
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	//获取节点的data值
	const T&operator*()
	{
		return _node->_val;
	}

	//iterator ->->
	const T* operator->()
	{
		return &_node->_val;
	}

	//iterator!=l.end()
	//比较两个迭代器封装的节点是否一样
	bool operator!=(const self& it)
	{
		return _node != it._node;
	}
};


template <class T>
class List
{

public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ConListIterator<T> iterator;

	//构造
	List(const T&val = T())  //全缺省val=T()
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	//拷贝构造
	List(const List<T>& lst)
	{
		//首先创建头指针
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//拷贝每一个节点，迭代器从头开始遍历每一个节点
		//插入到当前list对象中去
		for (const auto& e : list)
		{
			PushBack(e);
		}
	}
	void PushBakck(const T& val)
	{
		Insert(end(), val);
	}
	void PushFront(const T& val)
	{
		Insert(begin(), val);
	}
	void Insert(iterator pos, const T& val)
	{
		pNode newnode = new Node(val);
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}
private:
	pNode _head;
};