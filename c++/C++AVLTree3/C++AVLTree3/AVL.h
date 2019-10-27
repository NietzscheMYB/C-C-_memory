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
	//�������
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new AVLTreeNode<T>(data);
			return true;
		}
		//�ҵ�Ҫ�����λ��
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
		//�Ѿ��ҵ�Ҫ�����λ����
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
			//����ƽ������
			if (pCur == pParent->_pLeft)
			{
				pParent->_bf--;
			}
			else{
				pParent->_bf++;
			}
			//pParent ��ƽ�����Ӹı�
			//��pParent��ƽ�����ӽ��з���
			//��pParent ��ƽ�����ӱ�Ϊ0��ʱ��˵����ǰ��ƽ��������1/-1��������һ���ڵ�
			//����ı�pParent�ϲ��ƽ������ ֱ�ӷ��ؾ���
			if (pParent->_bf == 0)
			{
				return true;
			}
			if (pParent->_bf == 1 || pParent->_bf == -1)
			{
				//pParent ��ƽ��������1����-1ʱ��˵����ǰ��ƽ��������0��������һ���ڵ�
				//��Ӱ�����ϲ��ƽ������
				//���Ϸ����ҵ������������Ľڵ�
				pCur = pParent;
				pParent = pParent->_pParent;
			}
			else{
				if (pParent->_bf == 2)
				{
					//��ʱ��Ҫ��ת������
					//ͬ�ŵ���ת
					if (pCur->_bf == 1)
					{
						//�������ߣ�����
						_RotateL(pParent);
					}
					else{
						//���˫��
						_RotateRL(pParent);
					}
				}
				else if (pParent->_bf == -2)
				{
					if (pCur->_bf == 1)
					{
						//���˫��
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
	//����ֻ��Ҫ�ṩ�ӿھ���
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
		//��������
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

		//�ж�pParent �Ǹ��ڵ㻹�ǷǸ��ڵ�
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
		//�Ƚ�ƽ��������0
		//pParent pSubR
		pParent->_bf = pSubR->_bf = 0;
	}
	void _RotateR(Node* pParent)
	{
		//��������
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
		//�ж�pParent�Ǹ��ڵ㻹�ǷǸ��ڵ�

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
		//�Ƚ�ƽ��������Ϊ0
		pParent->_bf = pSubL->_bf = 0;
	}
	void _RotateLR(Node* pParent)
	{
		//��ת������ƽ�����ӿ��ܻ���������ȱ���pSubRL��ƽ������
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
		//����������ƽ������
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









