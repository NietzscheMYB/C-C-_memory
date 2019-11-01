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
	//1.����ָ�����
	T& operator*()
	{
		return _pNode->_data;
	}
	T* operator->()
	{
		return &(operator*());
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
	//3.�Ƚ�
	bool operator==(const Self& s) const
	{
		return _pNode == s._pNode;
	}

	bool operator!=(const Self& s) const
	{
		return _pNode != s._pNode;
	}
private:
	//++�ұȵ�ǰ��������Ӧ�ڵ�ֵ��Ľڵ㣡����
	//��Ľڵ�����С�Ľڵ�
	//1.��ǰ�ڵ�������
	//2.��ǰ�ڵ�˫����
	//
	void Increament()
	{
		//����������
		if (_pNode->_pRight)
		{
			//�����ҵ��ȵ�ǰ�ڵ�ֵ��Ľڵ㣬�ȵ�ǰ�ڵ��һ���
			//�����������������Ľڵ㣬��������Ľڵ��ǵ�ǰ����������С�Ľڵ�
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
			{
				_pNode = _pNode->_pLeft;
			}
		}
		//������������
		else
		{
			//��_pNode���Ԫ�ؿ�������˫���У���
			Node* pParent = _pNode->_pParent;
			//ֻҪ����ľ��˳�
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//���ڵ�û�������������ҵ������պ��ڸ��ڵ�λ�ã���
			if (_pNode->_pRight != pParent)
			{
				_pNode = pParent;
			}
			//�������
			//���һ��++ ��ͷ�ڵ㣡��
		}

	}
	void DeIncreament()
	{
		//��һ�������ж��Ǹ��ڵ��ͷ�ڵ㣬���ϵڶ����ڵ��жϳ���ͷ�ڵ� ��ʱ_pNode ��end
		if (_pNode->_pParent->_pParent == _pNode&&RED == _pNode->_color)
		{
			_pNode = _pNode->_pRight��
		}
		else if (_pNode->_pLeft)
		{
			//������������ڣ�Ӧ�����������������Ľڵ�
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
			{
				_pNode = _pNode->_pRight;
			}
		}
		else{
			//������
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pLeft)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
			//begin ����-- ���ÿ��������������

			//Ҫ����node��ͷ�ڵ㣡��
		}
	}
private:
	Node* _pNode;
};



//1.�����������࣬ ����������ȡһ����������
//2.����begin��end����


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
			//���ݶ����������������ҵ�ҪҪ�����λ��
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
		return end();//û�ҵ�����end
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
	size_t _size;//��¼���������Ч�ڵ�ĸ���
};

struct KeyOfValue
{
	int operator()(int data)
	{
		return data;
	}
};



//���ӵ�����+��֤
//����������  ��ָ��һ�� ++ --
//map<string,sting>::iterator it=m.begin()
//while(it!=m.end())
//cout<<it->first<<" "<<it->second<<endl;
//++it;
//cout<<endl;

//1.operator*()  operator->()       ����ָ��Ĳ���
//2.�ƶ�  ǰ��++ / ����++ ���� ǰ��-- / ���� --
//3.�Ƚ�  ��=          ==


//��װ��map/set
//map��<key,value>---�ȽϷ�ʽ����ֵ���е�key
//set:key-------------�ȽϷ�ʽ��ֱ������Ԫ�ؽ��бȽ�