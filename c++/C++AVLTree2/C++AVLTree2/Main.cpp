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
	int _bf;//��ǰ�ڵ� ��ƽ������
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
		//�ǿա�
		//���ն��������������ʣ��ҵ�Ҫ�����λ��
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

		//���ڱ��������parentƽ������
		//�½ڵ�϶�������˫�׵��������Ҳ࣬parent��ƽ�����ӿ϶��ı�
		while (pParent)
		{
			//����ƽ������
			if (pCur == pParent->_pLeft)
			{
				pParent->_bf--;
			}
			else
			{
				pParent->_bf++;
			}
			//���ܻᵼ��˫�׽ڵ��ƽ�����Ӳ�����AVL��������
			if (0 == pParent->_bf)
			{
				//˫�׽ڵ�������0�Ļ���
				//�϶�����Ӱ���ϲ��ƽ������
				//���Ծ���AVL���ˣ�����true
				return true;
			}
			//���˫�׽ڵ���-1������1 ˵��
			//˫�׽ڵ�������0�����ڸ߶�����
			//һ����Ӱ���ϲ��ƽ������
			else if (-1 == pParent->_bf || 1 == pParent->_bf)
			{
				//�ƶ�pCur, pParent
				//ѭ������Ƿ�Ҫ����ƽ������
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else{
				//˫�׵�ƽ�����Ӳ�����AVL��������
				//˫�׵Ľڵ��ƽ������Ϊ  2����-2
				//��Ҫ����˫��Ϊ���ģ���˫��Ϊ�������Ķ�����������ת����
				if (2 == pParent->_bf)
				{
					//ƽ��������2 ��˵����������
					if (1 == pCur->_bf)
					{
						//ͬ�ŵ���ת
						_RotateL(pParent);
					}
					else
					{
						//���˫��
						_RotateRL(pParent);
					}
				}
				else
				{
					//��������
					//pParent ��2/-2�Ļ���pCur �϶���1/-1
					if (-1 == pCur->_bf)
					{
						//ͬ�ŵ���
						_RotateR(pParent);
					}
					else
					{
						_RotateLR(pParent);
					}
				}
				//��ת���ˣ��϶���ƽ���ˣ����Ծ��˳��ˣ���
				break;
			}
		}
		return true;
	}
	//����ֻ�ṩ�ӿھ��У�Ҳ��Ҫ�Ӳ���
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
		//���õݹ�����������ĸ߶�
		int leftHeight = _Height(pRoot->_pLeft);
		//���õݹ�����������ĸ߶�
		int rightHeight = _Height(pRoot->_pRight);
		if (!(pRoot->_bf>=-1&&pRoot->_bf<=1&&pRoot->_bf==(rightHeight-leftHeight)))
		{
			return false;
		}
		//���õݹ�ӵײ㿪ʼһ��һ���ж�
		return _IsValidAVLTree(pRoot->_pLeft) && _IsValidAVLTree(pRoot->_pRight);
	}
	//���߶�
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
	//˫�׺ͽϸ������Ļ���ͬ��ʱ����������
	//��
	void _RotateR(Node* pParent)
	{
		//�������������ߣ���
		Node* pSubL = pParent->_pLeft;
		//�����϶� pSubL�����Ӳ������Һ��Ӹı�
		Node* pSubLR = pSubL->_pRight;
		//���º���ָ����
		pParent->_pLeft = pSubLR;
		//����˫��ָ����
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		Node* pPParent = pParent->_pParent;
		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//��pParent ����������ڵ�||�Ǹ���pParent ���ܵ����
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
		pParent->_bf = pSubL->_bf = 0;//˫�׺ͽϸߵĺ���ƽ����������0����
	}
	//����
	void _RotateL(Node* pParent)
	{
		//��������������
		Node* pSubR = pParent->_pRight;
		//pSubR ������������ı䣬ֻ��Ҫ�ı���������
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

		//�ж�pParent �Ǹ��ڵ㻹�ǷǸ��ڵ�
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
		//�Ƚ�ƽ��������Ϊ0
		//˫�׺ͽϸߵĺ��ӵ�ƽ��������0
		pParent->_bf = pSubR->_bf = 0;
	}
	//���
	//��ת���������ƽ�����ӿ��ܻ���������ȱ���pSubR��ƽ������
	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		int bf = pSubRL->_bf;

		_RotateR(pParent->_pRight);
		_RotateR(pParent);

		//����������ƽ������
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


