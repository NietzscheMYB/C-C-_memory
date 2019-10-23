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
				//�ŵ����
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
	//���û�ʹ�ü򵥣����ô�����
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
		//�ҵ���ɾ��Ԫ���ڶ�����������λ��
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
		//�ж��Ƿ��ҵ�
		if (nullptr == pCur)
		{
			return false;
		}
		//�ڵ��ҵ��ˣ����������
		//1.���Ҷ������ڣ�����
		//2.ֻ�����Ӵ���
		//3.ֻ���Һ��Ӵ���
		//4.���Һ��Ӷ�����
		Node* pDelNode = pCur;
		if (nullptr == pCur->_pRight)
		{
			//ֻ������||���Ҷ�������
			if (nullptr == pParent)
			{
				//��
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
			//ֻ���Һ���
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
			//���Һ��Ӿ�����
			//������������һ������ڵ�ɾ��
			//��ʽһ����������---->�ҵ�����������С�ĺ���---->�������������ĺ��� ������Ϊ�����Ļ�������������С��ֵ����ɾ���ڵ��滻�������������������������
			//��ʽ������������---->�ҵ������������ĺ���---->�����������Ҳ�ĺ���
			//���÷�ʽһ����
			Node* pMostLeft = pCur->_pRight;
			pParent = pCur;
			while (pMostLeft->_pLeft)
			{
				pParent = pMostLeft;
				pMostLeft = pMostLeft->_pLeft;
			}
			pCur->_data = pMostLeft->_data;
			//ɾ������ڵ�
			if (pMostLeft == pParent->_pLeft)
			{
				//��������ຢ�ӵ��ұ�
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
	//һ��ָ�������!!!!
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











