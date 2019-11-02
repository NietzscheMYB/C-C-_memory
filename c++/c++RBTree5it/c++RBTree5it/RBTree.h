#pragma once
#include<iostream>
using namespace std;
enum COLOR
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), COLOR color = RED)
	:_data(data)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _color(color)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	COLOR _color;
};


//封装迭代器
//1.象指针一样
//2.++ --
//3.比较
//针对不同的类，它的迭代器封装是不一样的
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* pNode=nullptr)
		:_pNode(pNode)
	{}

	//1.像指针一样，具有指针的操作
	T* operator->()
	{
		return &_pNode->_data;
	}
	T& operator*()
	{
		return _pNode->_data;
	}

	//2.移动++ --
	Self& operator++()
	{
		//向后移动！！！根据具体的数据结构类型移动！！
		Increament();
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		Inreament();
		return temp;
	}
	Self& operator--()
	{
		DeIncreamnet();
		return *this;
	}
	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}
	//3.比较
	bool operator==(const Self& s)
	{
		return _pNode == s._pNode;
	}
	bool operator!=(const Self& s)
	{
		return _pNode != s._pNode;
	}
private:
	//++找比当前迭代器节点值大的节点
	//1.一个是在当前节点的右孩子
	//2.一个是当前节点的父亲节点
	//显然先从右孩子节点上找
	void Increament()
	{
		//右子树存在
		if (_pNode->_pRight)
		{
			//右子树中的所有节点都是比当前节点大
			//所以找到右子树中最小的节点，即右子树中最左侧的节点
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		//右子树不存在！！
		else{
			//比_pNode大的元素可能在其双亲中！！
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//根节点没有右子树，并且迭代器刚好在跟节点的位置
			if (_pNode->_pRight != pParent)
			{
				_pNode = pParent;
			}
			//特殊情况
			//最后一次++ 到了头节点！！ end处
		}
	}
	void DeIncreament()
	{
		//第一个条件判断当前节点是在根节点还是在头节点
		//在头节点的话 就是end end -- 变成最后一个节点 即头节点的right！！
		if (_pNode->_pParent->_pParent == _pNode&&RED == _pNode->_color)
		{
			_pNode = _pNode->_pRight;
		}
		//与++相反，现在左子树中找最右的节点
		else if (_pNode->_pLeft)
		{
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		else {
			//向上找
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
			//begin 不能--，所以不用考虑这种情况！！！
			
			//但是要考虑node在头节点！！
		}
	}
private:
	Node* _pNode;
};

//struct  KeyOfValue
//{
//public:
//	int operator()(const int data)
//	{
//		return data;
//	}
//};



//1.给出迭代器类，并给迭代器取一个别名！！
//2.给出begin和end的方法！！！

template<class T,class KOFV>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
		:_size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	iterator begin()
	{
		return iterator(_pHead->_pLeft);
	}
	iterator end()
	{
		return iterator(_pHead);
	}
#if 0
	pair<iterator,bool> Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if (nullptr == pRoot)
		{
			pNewNode =pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			
		}
		else
		{
			//根据二叉搜索树的性质找到要要插入的位置
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (KOFV()(data) < KOFV()(pCur->_data))
				{
					pCur = pCur->_pLeft;
				}
				else if (KOFV()(data)>KOFV()(pCur->_data))
				{
					pCur = pCur->_pRight;
				}
				else{
					return make_pair(iterator(pCur),false);
				}
			}
			pNewNode=pCur = new Node(data);
			if (KOFV()(data) < KOFV()(pParent->_data))
			{
				pParent->_pLeft = pCur;
			}
			else{
				pParent->_pRight = pCur;
			}
			pCur->_pParent = pParent;

			//插入成功，判断是否满足红黑树的性质
			//插入的节点肯定是红色的！！，则先判断它的父亲节点的颜色
			while (pParent != _pHead&&RED == pParent->_color)
			{
				Node* granderFather = pParent->_pParent;
				Node* uncle = nullptr;
				if (pParent == granderFather->_pLeft)
				{
					//两大类情况
					//先是父亲左孩子，叔叔右孩子
					uncle = granderFather->_pRight;

					//分3种情况
					//1.父亲与叔叔都是红的，爷爷是黑的
					//2.cur是左孩子，父亲是红色，叔叔是黑色或者叔叔不存在，爷爷是黑的
					//3.cur是有孩子，父亲是红色，叔叔是黑色或者叔叔不存在，爷爷是黑的


					//叔叔的颜色将1，2和3情况分出来
					//根据cur将情况二三分出来
					if (uncle&&RED == uncle->_color)
					{
						//情况一：叔叔
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//向上检查
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else{
						//这个就是情况二和情况三
						if (pCur == pParent->_pRight)
						{
							//用pCur在右边就是情况3
							//左旋变成情况2
							RotateLeft(pParent);
							swap(pParent, pCur);
						}
						//现在是情况二
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateRight(granderFather);
					}
				}
				else{
					//再是父亲右孩子，叔叔左孩子
					uncle = granderFather->_pLeft;
					if (uncle&&uncle->_color == RED)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//继续向上调整！！
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else{
						//叔叔不存在，或者叔叔是黑色就是情况二与情况三
						if (pCur == pParent->_pLeft)
						{
							RotateRight(pParent);
							swap(pParent, pCur);
						}
						//情况二！！
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateLeft(granderFather);
					}
				}
			}
		}
		++_size;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode),true);
	}
#endif
	pair<iterator, bool> Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		Node* pNewNode = nullptr;
		if (nullptr == pRoot)
		{
			pNewNode = pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;

		}
		else{
			//根据二叉搜索树的性质找到要要插入的位置
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (KOFV()(data) < KOFV()(pCur->_data))
				{
					pCur = pCur->_pLeft;
				}
				else if (KOFV()(data)>KOFV()(pCur->_data))
				{
					pCur = pCur->_pRight;
				}
				else{
					return make_pair(iterator(pCur), false);
				}
			}
			pNewNode = pCur = new Node(data);
			if (KOFV()(data) < KOFV()(pParent->_data))
			{
				pParent->_pLeft = pCur;
			}
			else{
				pParent->_pRight = pCur;
			}
			pCur->_pParent = pParent;

			//插入成功，判断是否满足红黑树的性质
			//插入的节点肯定是红色的！！，则先判断它的父亲节点的颜色
			while (pParent != _pHead&&RED == pParent->_color)
			{
				Node* granderFather = pParent->_pParent;
				Node* uncle = nullptr;
				if (pParent == granderFather->_pLeft)
				{
					//两大类情况
					//先是父亲左孩子，叔叔右孩子
					uncle = granderFather->_pRight;

					//分3种情况
					//1.父亲与叔叔都是红的，爷爷是黑的
					//2.cur是左孩子，父亲是红色，叔叔是黑色或者叔叔不存在，爷爷是黑的
					//3.cur是有孩子，父亲是红色，叔叔是黑色或者叔叔不存在，爷爷是黑的


					//叔叔的颜色将1，2和3情况分出来
					//根据cur将情况二三分出来
					if (uncle&&RED == uncle->_color)
					{
						//情况一：叔叔
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//向上检查
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else{
						//这个就是情况二和情况三
						if (pCur == pParent->_pRight)
						{
							//用pCur在右边就是情况3
							//左旋变成情况2
							RotateLeft(pParent);
							swap(pParent, pCur);
						}
						//现在是情况二
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateRight(granderFather);
					}
				}
				else{
					//再是父亲右孩子，叔叔左孩子
					uncle = granderFather->_pLeft;
					if (uncle&&uncle->_color == RED)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//继续向上调整！！
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else{
						//叔叔不存在，或者叔叔是黑色就是情况二与情况三
						if (pCur == pParent->_pLeft)
						{
							RotateRight(pParent);
							swap(pParent, pCur);
						}
						//情况二！！
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateLeft(granderFather);
					}
				}
			}
		}

		++_size;
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return make_pair(iterator(pNewNode), true);
	}
	iterator Find(const T& data)const
	{
		Node* pCur = _pHead->_pParent;
		while (pCur)
		{
			if (KOFV()(data) == KOFV()(pCur->_data))
			{
				return iterator(pCur);
			}
			else if (KOFV()(data) <KOFV()(pCur->_data))
			{
				pCur = pCur->_pLeft;
			}
			else{
				pCur = pCur->_pRight;
			}
		}
		return end();//没有返回end
	}
	void InOrder()
	{
		_InOrder(GetRoot());
	}
	bool Empty()const //判空
	{
		return nullptr == _pHead->_pParent;
	}
	size_t Size()const//size
	{
		return _size;
	}


protected:
	void _InOrder(Node* pCur)
	{
		if (pCur)
		{
			_InOrder(pCur->_pLeft);
			cout << pCur->_data << " ";
			_InOrder(pCur->_pRight);
		}
	}
	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		Node* pPParent = pParent->_pParent;
		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		//判断pParent 是根节点还是非根节点
		if (pPParent == _pHead)
		{
			GetRoot() = pSubL;
			return;
		}
		if (pParent == pPParent->_pLeft)
		{
			pPParent->_pLeft = pSubL;
		}
		else{
			pPParent->_pRight = pSubL;
		}
	}
	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}

		Node* pPParent = pParent->_pParent;
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		//判断pParent是根还是非根
		if (pPParent == _pHead)
		{
			GetRoot() = pSubR;
			return;
		}
		if (pParent == pPParent->_pLeft)
		{
			pPParent->_pLeft = pSubR;
		}
		else{
			pPParent->_pRight = pSubR;
		}

	}

	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
		{
			return _pHead;
		}
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
		{
			return _pHead;
		}
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	Node*& GetRoot()
	{
		//返回根节点，只要head不销毁，就肯定能返回
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
	size_t _size;//记录红黑树中有效节点的个数
};


//3.增加好类似的接口再封装map与set


//封装map  /set
//map<key,value>  拿key进行比较！！！
//set<key>            拿key进行比较！！！，直接用其元素进行比较

