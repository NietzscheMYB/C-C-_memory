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
	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
		{
			return true;
		}
		//找到待删除元素在二叉搜索树的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (pCur->_data > data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (pCur->_data < data)
			{
				pParent = pCur;
				pCur - pCur->_pRight;
			}
			else if (pCur->_data == data)
			{
				break;
			}
		}
		//判断是否找到
		if (nullptr == pCur)
		{
			return false;
		}
		//节点找到了，分情况！！
		//1.左右都不存在！！！
		//2.只有左孩子存在
		//3.只有右孩子存在
		//4.左右孩子都存在
		Node* pDelNode = pCur;
		if (nullptr == pCur->_pRight)
		{
			//只有左孩子||左右都不存在
			if (nullptr == pParent)
			{
				//根
				_pRoot = pCur->_pLeft;
			}
			else{
				if (pCur == pParent->_pLeft)
				{
					pParent->_pLeft = pCur->_pLeft;
				}
				else{
					pParent->_pRight = pCur->_pLeft;
				}
			}
		}
		else if (nullptr==pCur->_pLeft)
		{
			//只有右孩子
			if (nullptr = pParent)
			{
				_pRoot = pCur->_pRight;
			}
			else{
				if (pCur == pParent->_pLeft)
				{
					pParent->_pLeft = pCur->_pRight;
				}
				else{
					pParent->_pRight = pCur->_pRight;
				}
			}
		}
		else{
			//左右孩子均存在
			//在其子树中找一个替代节点删除
			//方式一：右子树找---->找到右子树中最小的孩子---->右子树中最左侧的孩子 ，，因为最左侧的还是右子树中最小的值，与删除节点替换，则还是满足二叉搜索树的性质
			//方式二：左子树找---->找到左子树中最大的孩子---->左子树中最右侧的孩子
			//采用方式一！！
			Node* pMostLeft = pCur->_pRight;
			pParent = pCur;
			while (pMostLeft->_pLeft)
			{
				pParent = pMostLeft;
				pMostLeft = pMostLeft->_pLeft;
			}
			pCur->_data = pMostLeft->_data;
			//删除替代节点
			if (pMostLeft == pParent->_pLeft)
			{
				//保留最左侧孩子的右边
				pParent->_pLeft = pMostLeft->_pRight;
			}
			else{
				pParent->_pRight = pMostLeft->_pRight;
			}
			pDelNode = pMostLeft;

		}
		delete pDelNode;
		return true;
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











