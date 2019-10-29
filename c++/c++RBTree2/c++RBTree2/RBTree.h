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
	RBTreeNode(const T& data=T(),COLOR color=RED)
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

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data,BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		//根据二叉搜索树的性质找到要要插入的位置
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else if (data>pCur->_data)
			{
				pCur = pCur->_pRight;
			}
			else{
				return false;
			}
		}
		pCur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = pCur;
		}
		else{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;

		//插入成功，判断是否满足红黑树的性质
		//插入的节点肯定是红色的！！，则先判断它的父亲节点的颜色
		 while(pParent!=_pHead&&RED==pParent->_color)
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
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
	void InOrder()
	{
		_InOrder(GetRoot());
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
};