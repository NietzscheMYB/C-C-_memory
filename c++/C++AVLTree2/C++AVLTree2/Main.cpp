#include<iostream>
using namespace std;
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data=T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	, _data(data)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;//当前节点 的平衡因子
};
template<class T>
class AVLTree{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}
	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空。
		//按照二叉搜索树的性质，找到要插入的位置
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
		pCur = new Node(data);
		if (pParent->_data>data)
		{
			pParent->_pLeft = pCur;
		}
		else
		{
			pParent->_pRight = pCur;
		}
		pCur->_pParent = pParent;

		//现在必须检查跟新parent平衡因子
		//新节点肯定插入在双亲的左侧或者右侧，parent的平衡因子肯定改变
		while (pParent)
		{
			//跟新平衡因子
			if (pCur == pParent->_pLeft)
			{
				pParent->_bf--;
			}
			else
			{
				pParent->_bf++;
			}
			//可能会导致双亲节点的平衡因子不满足AVL树的性质
			if (0 == pParent->_bf)
			{
				//双亲节点如果变成0的话，
				//肯定不会影响上层的平衡因子
				//所以就是AVL树了，返回true
				return true;
			}
			//如果双亲节点变成-1，或者1 说明
			//双亲节点曾经是0，现在高度增加
			//一定会影响上层的平衡因子
			else if (-1 == pParent->_bf || 1 == pParent->_bf)
			{
				//移动pCur, pParent
				//循环检查是否要更新平衡因子
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else{
				//双亲的平衡因子不满足AVL树的性质
				//双亲的节点的平衡因子为  2或者-2
				//需要对以双亲为根的，以双亲为根！！的二叉树进行旋转处理
				if (2 == pParent->_bf)
				{
					//平衡因子是2 ，说明右子树高
					if (1 == pCur->_bf)
					{
						//同号单旋转
						_RotateL(pParent);
					}
					else
					{
						//异号双旋
						_RotateRL(pParent);
					}
				}
				else
				{
					//左子树高
					//pParent 是2/-2的话，pCur 肯定是1/-1
					if (-1 == pCur->_bf)
					{
						//同号单旋
						_RotateR(pParent);
					}
					else
					{
						_RotateLR(pParent);
					}
				}
				//旋转完了，肯定就平衡了，所以就退出了！！
				break;
			}
		}
		return true;
	}
	//对外只提供接口就行，也不要加参数
	void InOrder()
	{
		_InOrder(_pRoot);
	}
	bool IsValidAVLTree()
	{
		return _IsValidAVLTree();
	}
protected:
	bool _IsValidAVLTree(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return true;
		}
		//调用递归求出左子树的高度
		int leftHeight = _Height(pRoot->_pLeft);
		//调用递归求出右子树的高度
		int rightHeight = _Height(pRoot->_pRight);
		if (!(pRoot->_bf>=-1&&pRoot->_bf<=1&&pRoot->_bf==(rightHeight-leftHeight)))
		{
			return false;
		}
		//借用递归从底层开始一步一步判断
		return _IsValidAVLTree(pRoot->_pLeft) && _IsValidAVLTree(pRoot->_pRight);
	}
	//检查高度
	size_t _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
		{
			return 0;
		}
		size_t leftHeight = (pRoot->_pLeft);
		size_t rightHeight = (pRoot->_pRight);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout <<pRoot->_data<<" ";
			_InOrder(pRoot->_pRight);
		}
	}
	//双亲和较高子树的还是同号时，单旋！！
	//右
	void _RotateR(Node* pParent)
	{
		//右旋，左子树高！！
		Node* pSubL = pParent->_pLeft;
		//右旋肯定 pSubL的左孩子不动，右孩子改变
		Node* pSubLR = pSubL->_pRight;
		//更新孩子指针域
		pParent->_pLeft = pSubLR;
		//更新双亲指针域
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		Node* pPParent = pParent->_pParent;
		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//对pParent 分情况：根节点||非根节pParent 可能的情况
		if (nullptr == pPParent)
		{
			_pRoot = pSubL;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
			{
				pPParent->_pLeft = pSubL;
			}
			else
			{
				pPParent->_pRight = pSubL;
			}
		}
		pParent->_bf = pSubL->_bf = 0;//双亲和较高的孩子平衡因子先置0！！
	}
	//左旋
	void _RotateL(Node* pParent)
	{
		//左旋，右子树高
		Node* pSubR = pParent->_pRight;
		//pSubR 的右子树不会改变，只需要改变其左子树
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pLeft = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}

		Node* pPParent = pParent->_pParent;
		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		//判断pParent 是根节点还是非根节点
		if (nullptr == pPParent)
		{
			_pRoot = pSubR;
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
		//先将平衡因子置为0
		//双亲和较高的孩子的平衡因子置0
		pParent->_bf = pSubR->_bf = 0;
	}
	//异号
	//旋转结束，最后平衡因子可能会出错，所以先保存pSubR的平衡因子
	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		_RotateR(pParent->_pRight);
		_RotateR(pParent);

		//调整特殊点的平衡因子
		if (-1 == bf)
		{
			pSubR->_bf = 1;
		}
		else if (1 == bf)
		{
			pParent->_data = -1;
		}

	}
	void _RotateLR(Node* pParent)
	{
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
private:
	Node* _pRoot;
};



int main()
{
	return 0;
}


