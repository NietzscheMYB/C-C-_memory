#include<iostream>
using namespace std;

template<class T>
struct BSTreeNode{
	BSTreeNode(const T& data=T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}
	
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree()
	{
		Destroy(_pRoot);
	}
	bool Insert(const T&data)
	{
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data > data)
			{
				//放到左边
				pCur = pCur->_pLeft;
			}
			else if (pCur->_data< data){
				pCur = pCur->_pRight;
			}
			else{
				return false;
			}
		}
		Node* newNode = new Node(data);
		if (pParent->_data > data)
		{
			pParent->_pLeft = newNode;
		}
		else
		{
			pParent->_pRight = newNode;
		}
		return true;

	}
	//让用户使用简单，不用传参数
	Node* LeftMost()
	{
		return _LeftMost(_pRoot);
	}
	Node* RightMost()
	{
		return _RightMost(_pRoot);
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}
	void Delete(const T& data)
	{

	}
	Node* Find(const T&data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (pCur->_data < data)
			{
				pCur = pCur->_pRight;
			}
			else if (pCur->_data>data)
			{
				pCur = pCur->_pLeft;
			}
			else
			{
				return pCur;
			}
		}
		return nullptr;
	}
private:
	Node* _LeftMost(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return nullptr;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node* _RightMost(Node* pRoot)
	{
		if (nullptr = pRoot)
		{
			return nullptr;
		}
		Node* pCur = pRoot;
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
	//一级指针的引用!!!!
	void _Destroy(Node* &pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};











