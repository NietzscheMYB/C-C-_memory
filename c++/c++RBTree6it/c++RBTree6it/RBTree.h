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


//��װ��������
//1.��ָ��һ����
//2.�ƶ���
//3.�Ƚ�
template<class T>
class RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
public:
	RBTreeIterator(Node* Node = nullptr)
		:_pNode(Node)
	{}
	//1.��ָ��һ��
	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return &_pNode->_data;
	}
	//2.�ƶ�
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
	Self operator--()
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
	//3.�Ƚ�
	bool operator==(const Self& s)
	{
		return _pNode == s._pNode;
	}
	bool operator!=(const Self& s)
	{
		return _pNode != s._pNode;
	}
private:
	void Increament()
	{
		//++�ƶ����ҵ��ȵ�ǰ�ڵ���ֵ
		//�������������
		//1.����������������
		//�����������ҵ�����ߵĽڵ㣡��
		if (_pNode->_pRight)
		{
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		else{
			//2.������������������Ѱ�ң���
			Node* pParent = _pNode->_pParent;
			while (_pNode==pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//���2 �л���һ��������� ���һ���ڵ�++ ʱ �ͱ����end������head�ڵ㣡
			//��ʱ���������û���Һ��ӣ���
			if (_pNode->_pRight != pParent)
			{
				_pNode = pParent;
			}
		}
	}
	void DeIncreament()
	{
		//����������ͷ�ڵ�ʱ������
		if (_pNode->_pParent->_pParent == _pNode&&RED = _pNode->_color)
		{
			_pNode = _pNode->_pRight;
		}
		//��++���෴�ģ���
		else if (_pNode->_pLeft)
		{
			//���1 ����������Ѱ�����ұߵĺ���
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		else{
			//���2������Ѱ�ң���
			Node* pParent = _pNode->_pParent;
			while (_pNode==pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//��һ���ڵ� ������--������������������ÿ��ǣ���
			_pNode = pParent;
		}
	}
private:
	Node* _pNode;
};


template<class T>
class RBTree
{
	typedef RBTreeIterator<T> Iterator;
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	Iterator begin()
	{
		return Iterator(_pHead->_pLeft);
	}
	Iterator end()
	{
		return Iterator(_pHead);
	}
	bool Insert(const T& data)
	{
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		//���ݶ����������������ҵ�ҪҪ�����λ��
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

		//����ɹ����ж��Ƿ���������������
		//����Ľڵ�϶��Ǻ�ɫ�ģ����������ж����ĸ��׽ڵ����ɫ
		while (pParent != _pHead&&RED == pParent->_color)
		{
			Node* granderFather = pParent->_pParent;
			Node* uncle = nullptr;
			if (pParent == granderFather->_pLeft)
			{
				//���������
				//���Ǹ������ӣ������Һ���
				uncle = granderFather->_pRight;

				//��3�����
				//1.���������嶼�Ǻ�ģ�үү�Ǻڵ�
				//2.cur�����ӣ������Ǻ�ɫ�������Ǻ�ɫ�������岻���ڣ�үү�Ǻڵ�
				//3.cur���к��ӣ������Ǻ�ɫ�������Ǻ�ɫ�������岻���ڣ�үү�Ǻڵ�


				//�������ɫ��1��2��3����ֳ���
				//����cur����������ֳ���
				if (uncle&&RED == uncle->_color)
				{
					//���һ������
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					granderFather->_color = RED;
					//���ϼ��
					pCur = granderFather;
					pParent = pCur->_pParent;
				}
				else{
					//�������������������
					if (pCur == pParent->_pRight)
					{
						//��pCur���ұ߾������3
						//����������2
						RotateLeft(pParent);
						swap(pParent, pCur);
					}
					//�����������
					pParent->_color = BLACK;
					granderFather->_color = RED;
					RotateRight(granderFather);
				}
			}
			else{
				//���Ǹ����Һ��ӣ���������
				uncle = granderFather->_pLeft;
				if (uncle&&uncle->_color == RED)
				{
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					granderFather->_color = RED;
					//�������ϵ�������
					pCur = granderFather;
					pParent = pCur->_pParent;
				}
				else{
					//���岻���ڣ����������Ǻ�ɫ����������������
					if (pCur == pParent->_pLeft)
					{
						RotateRight(pParent);
						swap(pParent, pCur);
					}
					//���������
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

		//�ж�pParent �Ǹ��ڵ㻹�ǷǸ��ڵ�
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

		//�ж�pParent�Ǹ����ǷǸ�
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
		//���ظ��ڵ㣬ֻҪhead�����٣��Ϳ϶��ܷ���
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
};