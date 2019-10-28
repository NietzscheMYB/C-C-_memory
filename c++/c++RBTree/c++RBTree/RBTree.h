#pragma once

enum COLOR
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data=T(),COLOR color=RED)
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _color(color)
	, _data(data)
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
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		else
		{
			//���ն����������������ҵ�������Ľڵ��ں������λ��
			Node* pCur = pRoot;
			Node* pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (pCur->_data < data)
				{
					pCur = pCur->_pRight;
				}
				else if(pCur->_data > data){
					pCur = pCur->_pLeft;
				}
				else{
					return false;
				}	
			}
			//�����µĽڵ�
			pCur = new Node(data);
			if (data < pParent->_data)
			{
				pParent->_pLeft = pCur;
			}
			else{
				pParent->_pRight = pCur;
			}
			pCur->_pParent = pParent;

			//�Ѿ����룬����ֻ��Ҫ����Ƿ���Ϻ����������
			//��Ϊ���뵽�½ڵ�Ĭ����ɫ�Ǻ�ɫ����ˣ������˫�׽ڵ����ɫ�Ǻ�ɫ
			//û��Υ��������κ����ʣ�����Ҫ������
			//�����²���ڵ��˫�׽ڵ���ɫΪ��ɫʱ����Υ����������
			//Լ��curΪ��ǰ�ڵ㣬pΪ���ڵ㣬gΪ�游�ڵ�
			//uΪ����ڵ�

			//��⣺�½ڵ������Ƿ�������һ��ĺ�ɫ�ڵ�
			while(pParent!=_pHead&&RED == pParent->_color)
			{
				Node* granderFather = pParent->_pParent;
				//�ȴ���˫�����������
				if (pParent == granderFather->_pLeft)
				{
					Node* uncle = granderFather->_pRight;
					//���һ������ڵ���ڣ���Ϊ��
					if (uncle&&RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//�ı�λ�ü������
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else
					{
						//�������������� ��������������
						if (pCur==pParent->_pRight)//�������������
						{
							//�����������
							RotateLeft(pParent);
							swap(pParent, pCur);
							//�������˾ͱ�������������
						}
						//���������
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateRight(granderFather);
					}
				}
				else
				{
					//��������ķ����
					Node* uncle = granderFather->_pLeft;
					if (uncle&&RED == uncle->_color) //���һ�ķ����������
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else
					{
						//�����������������ķ����

						if (pCur == pParent->_pLeft)//����������ķ����������
						{
							RotateRight(pParent);//��ת
							swap(pParent, pCur);//����
							//��ʱ�Ѿ����������ķ����
						}

						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateLeft(granderFather);
					}
				}
			}


			//�����꣬Ҫ��������
			//����Ϊ��,�����ڼ���ܻ�ı������ɫ
			pRoot->_color = BLACK;
			_pHead->_pLeft = LeftMost();
			_pHead->_pRight = RightMost();
			return true;
		}
	}
	void InOrder()
	{
		_InOrder(GetRoot());
	}
	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return true;
		}
		if (pRoot->_color != BLACK)
		{
			cout << "Υ������1�����ڵ���ɫ����Ϊ��ɫ" << endl;
			return false;
		}
		//��ȡһ��·���нڵ�ĸ���
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (pCur->_color == BLACK)
			{
				blackCount++;
			}
			pCur = pCur->_pLeft;
		}
		size_t pathBlack = 0;
		return _IsValidRBTree(pRoot, blackCount,pathBlack);
	}
protected:
	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathBlack)
	{
		if (nullptr == pRoot)
		{
			return true;
		}
		if (pRoot->_color == BLACK)
		{
			pathBlack++;
		}
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead&&pParent->_color==RED&&pRoot->_color==RED)
		{
			cout << "Υ����������������������һ��ĺ�ɫ�ڵ�" << endl;
		}
		//һ��·����Ҷ��
		if (nullptr == pRoot->_pLeft&&nullptr==pRoot->_pRight)
		{
			if (blackCount != pathBlack)
			{
				cout << "Υ��������4��ÿ��·���к�ɫ�ڵ����������ͬ" << endl;
			}
		}
		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathBlack) &&
			_IsValidRBTree(pRoot->_pRight, blackCount, pathBlack);

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

	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		//�ж��Ƿ�Ϊ���ڵ�
		if (pPParent == _pHead)
		{
			GetRoot() = pSubR;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
			{
				pPParent->_pLeft = pSubR;
			}
			else
			{
				pPParent->_pRight = pSubR;
			}
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
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		//�ж�pParent�Ǹ��ڵ㻹�ǷǸ��ڵ�
		if (pPParent == _pHead)
		{
			//�Ǹ��ڵ�
			GetRoot() = pSubL;
		}
		else
		{
			//�Ǹ��ڵ�
			if (pPParent->_pLeft == pParent)
			{
				pPParent->_pLeft = pSubL;
			}
			else
			{
				pPParent->_pRight = pSubL;
			}
		}

	}
	Node* LeftMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}
		Node* pCur = pRoot;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node* RightMost()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}
		Node* pCur = pRoot;
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




