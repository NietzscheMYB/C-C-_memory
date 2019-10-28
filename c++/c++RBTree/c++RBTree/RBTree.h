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
			//按照二叉搜索树的性质找到待插入的节点在红黑树的位置
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
			//插入新的节点
			pCur = new Node(data);
			if (data < pParent->_data)
			{
				pParent->_pLeft = pCur;
			}
			else{
				pParent->_pRight = pCur;
			}
			pCur->_pParent = pParent;

			//已经插入，现在只需要检查是否符合红黑树的性质
			//因为插入到新节点默认颜色是红色，因此，如果其双亲节点的颜色是黑色
			//没有违反红黑树任何性质，则不需要调整。
			//但当新插入节点的双亲节点颜色为红色时，就违反了性质三
			//约定cur为当前节点，p为父节点，g为祖父节点
			//u为叔叔节点

			//检测：新节点插入后，是否有连在一起的红色节点
			while(pParent!=_pHead&&RED == pParent->_color)
			{
				Node* granderFather = pParent->_pParent;
				//先处理双亲在左侧的情况
				if (pParent == granderFather->_pLeft)
				{
					Node* uncle = granderFather->_pRight;
					//情况一：叔叔节点存在，且为红
					if (uncle&&RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						//改变位置继续检查
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else
					{
						//接下来的情况变成 情况二或者情况三
						if (pCur==pParent->_pRight)//这是情况三！！
						{
							//这是情况三！
							RotateLeft(pParent);
							swap(pParent, pCur);
							//交换完了就变成了情况二！！
						}
						//情况二！！
						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateRight(granderFather);
					}
				}
				else
				{
					//三种情况的反情况
					Node* uncle = granderFather->_pLeft;
					if (uncle&&RED == uncle->_color) //情况一的反情况！！！
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						pCur = granderFather;
						pParent = pCur->_pParent;
					}
					else
					{
						//这是情况二和情况三的反情况

						if (pCur == pParent->_pLeft)//这是情况三的反情况！！！
						{
							RotateRight(pParent);//旋转
							swap(pParent, pCur);//交换
							//此时已经变成情况二的反情况
						}

						pParent->_color = BLACK;
						granderFather->_color = RED;
						RotateLeft(granderFather);
					}
				}
			}


			//调整完，要做的事情
			//根改为黑,调整期间可能会改变根的颜色
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
			cout << "违反性质1：根节点颜色必须为黑色" << endl;
			return false;
		}
		//获取一条路径中节点的个数
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
			cout << "违反了性质三：不能有连着一起的红色节点" << endl;
		}
		//一条路径到叶子
		if (nullptr == pRoot->_pLeft&&nullptr==pRoot->_pRight)
		{
			if (blackCount != pathBlack)
			{
				cout << "违反了性质4：每条路径中黑色节点个数必须相同" << endl;
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

		//判断是否为根节点
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

		//判断pParent是根节点还是非根节点
		if (pPParent == _pHead)
		{
			//是根节点
			GetRoot() = pSubL;
		}
		else
		{
			//非根节点
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
		//返回根节点，只要head不销毁，就肯定能返回
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
};




