#pragma once
#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode{
	AVLTreeNode(const T&data = T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	, _data(data)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	int _bf;
	T _data;
};


template<class T>
class AVLTree{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	//插入操作
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new AVLTreeNode<T>(data);
			return true;
		}
		//找到要插入的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (pCur->_data > data)
			{
				pCur = pCur->_pLeft;
			}
			else if (pCur->_data<data)
			{
				pCur = pCur->_pRight;
			}
			else
			{
				return false;
			}
		}
		//已经找到要插入的位置了
		pCur = new AVLTreeNode<T>(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = pCur;
		}
		else{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;


		while (pParent)
		{
			//更新平衡因子
			if (pCur == pParent->_pLeft)
			{
				pParent->_bf--;
			}
			else{
				pParent->_bf++;
			}
			//pParent 的平衡因子改变
			//对pParent的平衡因子进行分析
			//当pParent 的平衡因子变为0，时，说明以前的平衡因子是1/-1，则增加一个节点
			//不会改变pParent上层的平衡因子 直接返回就行
			if (pParent->_bf == 0)
			{
				return true;
			}
			if (pParent->_bf == 1 || pParent->_bf == -1)
			{
				//pParent 的平衡因子是1或者-1时，说明以前的平衡因子是0，则增加一个节点
				//会影响其上层的平衡因子
				//向上返回找到不满足条件的节点
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else{
				if (pParent->_bf == 2)
				{
					//此时需要旋转！！！
					//同号单旋转
					if (pCur->_bf == 1)
					{
						//右子树高，左旋
						_RotateL(pParent);
					}
					else{
						//异号双旋
						_RotateRL(pParent);
					}
				}
				else if (pParent->_bf == -2)
				{
					if (pCur->_bf == 1)
					{
						//异号双旋
						_RotateLR(pParent);
					}
					else
					{
						_RotateR(pParent);
					}

				}
				break;
			}
		}
		return true;
	}
	//对外只需要提供接口就行
	void InOrdor()
	{
		_InOrdor(_pRoot);
		cout << endl;
	}
	bool IsValidAVLTree()
	{
		return _IsValidAVLTree(_pRoot);
	}
protected:
	void _InOrdor(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return;
		}
		_InOrdor(pRoot->_pLeft);
		cout << pRoot->_data << " ";
		_InOrdor(pRoot->_pRight);
	}
	bool _IsValidAVLTree(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return true;
		}
		size_t _leftHeight = _Height(pRoot->_pLeft);
		size_t _rightHeight = _Height(pRoot->_pRight);

		if (!(pRoot->_bf == (_rightHeight - _leftHeight) && (-1 == pRoot->_bf || 1 == pRoot->_bf)))
		{
			return false;
		}
		return _IsValidAVLTree(pRoot->_pLeft) && _IsValidAVLTree(pRoot->_pRight);

	}
	size_t _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return 0;
		}
		size_t _leftHeight = _Height(pRoot->_pLeft);
		size_t _rightHeight = _Height(pRoot->_pRight);

		return _leftHeight > _rightHeight ? _leftHeight + 1 : _rightHeight + 1;
	}
	void _RotateL(Node* pParent)
	{
		//右子树高
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft= pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		//判断pParent 是根节点还是非根节点
		if (nullptr == pPParent)
		{
			_pRoot = pSubR;
			pParent->_bf = pSubR->_bf = 0;
			return;
		}
		if (pPParent->_pLeft == pParent)
		{
			pPParent->_pLeft = pSubR;
		}
		else{
			pPParent->_pRight = pSubR;
		}
		//先将平衡因子置0
		//pParent pSubR
		pParent->_bf = pSubR->_bf = 0;
	}
	void _RotateR(Node* pParent)
	{
		//左子树高
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
		//判断pParent是根节点还是非根节点

		if (nullptr == pPParent)
		{
			_pRoot = pSubL;
			pParent->_bf = pSubL->_bf = 0;
			return;
		}
		if (pPParent->_pLeft == pParent)
		{
			pPParent->_pLeft = pSubL;
		}
		else
		{
			pPParent->_pRight = pSubL;
		}
		//先将平衡因子置为0
		pParent->_bf = pSubL->_bf = 0;
	}
	void _RotateLR(Node* pParent)
	{
		//旋转结束后，平衡因子可能会出错，所以先保持pSubRL的平衡因子
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;

		_RotateL(pParent->_pLeft);
		_RotateR(pParent);

		if (-1 == bf)
		{
			pParent->_bf = 1;
		}
		else if (1 == bf)
		{
			pSubL->_bf = -1;
		}
	}
	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		_RotateR(pParent->_pRight);
		_RotateL(pParent);
		//调整特殊点的平衡因子
		if (-1 == bf)
		{
			pSubR->_bf = 1;
		}
		else if (1 == bf)
		{
			pParent->_bf = -1;
		}
	}
private:
	Node* _pRoot;
};









