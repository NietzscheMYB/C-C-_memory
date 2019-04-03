#include <iostream>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(const T&val = T())  //���캯��
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

	//���캯��
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
	//�ƶ�����һ���ڵ��λ��
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
	//��ȡ�ڵ��dataֵ
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
	//�Ƚ�������������װ�Ľڵ��Ƿ�һ��
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

	//����
	List(const T&val = T())  //ȫȱʡval=T()
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	//��������
	List(const List<T>& lst)
	{
		//���ȴ���ͷָ��
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		//����ÿһ���ڵ㣬��������ͷ��ʼ����ÿһ���ڵ�
		//���뵽��ǰlist������ȥ
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