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
	void fun()
	{
		cout << "1" << endl;
	}
};

template < class T>
struct RBTreeIterator{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* pNode = nullptr)
		:_pNode(pNode)
	{}
	//1.具有指针操作
	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return &(operator*());
	}
	//2.移动
	Self& operator++()
	{
		Increament();
		return *this;
	}
	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}
	Self& operator--()
	{
		DeIncreament();
		return *this;
	}
	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}
	//3.比较
	bool operator==(const Self& s) const
	{
		return _pNode == s._pNode;
	}

	bool operator!=(const Self& s) const
	{
		return _pNode != s._pNode;
	}
private:
	//++找比当前迭代器对应节点值大的节点！！！
	//大的节点中最小的节点
	//1.当前节点右子树
	//2.当前节点双亲中
	//
	void Increament()
	{
		//右子树存在
		if (_pNode->_pRight)
		{
			//就是找到比当前节点值大的节点，比当前节点大一点点
			//在右子树中找最左侧的节点，这个最左侧的节点是当前右子树中最小的节点
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		//右子树不存在
		else
		{
			//比_pNode大的元素可能在其双亲中！！
			Node* pParent = _pNode->_pParent;
			//只要是左的就退出
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//根节点没有右子树，并且迭代器刚好在根节点位置！！
			if (_pNode->_pRight != pParent)
			{
				_pNode = pParent;
			}
			//特殊情况
			//最后一次++ 到头节点！！
		}

	}
	void DeIncreament()
	{
		//第一个条件判断是根节点和头节点，加上第二个节点判断出是头节点 此时_pNode 是end
		if (_pNode->_pParent->_pParent == _pNode&&RED == _pNode->_color)
		{
			_pNode = _pNode->_pRight；
		}
		else if (_pNode->_pLeft)
		{
			//如果左子树存在，应该在左子树中找最大的节点
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		else{
			//向上找
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
			//begin 不能-- 不用考虑这种情况！！

			//要考虑node在头节点！！
		}
	}
private:
	Node* _pNode;
};



//1.给出迭代器类， 并给迭代器取一个别名！！
//2.给出begin与end方法


template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
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
			if (KOFV()(data) == KOFV() (pCur->_data))
				return iterator(pCur);
			else if (KOFV()(data) < KOFV()(pCur->_data))
			{
				pCur = pCur->_pLeft;
			}
			else{
				pCur = pCur->_pRight;
			}
		}
		return end();//没找到返回end
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}
	bool Empty() const
	{
		return nullptr == _pHead->_pParent;
	}

	size_t Size() const
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

struct KeyOfValue
{
	int operator()(int data)
	{
		return data;
	}
};



//增加迭代器+验证
//迭代器操作  像指针一样 ++ --
//map<string,sting>::iterator it=m.begin()
//while(it!=m.end())
//cout<<it->first<<" "<<it->second<<endl;
//++it;
//cout<<endl;

//1.operator*()  operator->()       具有指针的操作
//2.移动  前置++ / 后置++ 或者 前置-- / 后置 --
//3.比较  ！=          ==


//封装：map/set
//map：<key,value>---比较方式：键值对中的key
//set:key-------------比较方式：直接用其元素进行比较