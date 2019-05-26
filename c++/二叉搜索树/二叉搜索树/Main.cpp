
#include<iostream>
using namespace std;

template <class T>
struct BSTNode{
	BSTNode(const T& val = T())
	:_data(val)
	, _pleft(nullptr)
	, _pright(nullptr)
	{}
	T _data;
	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
};
template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	BSTree(const pNode root = nullptr)
		:_root(root)
	{
	}
	pNode find(const T& val)
	{
		if (root == nullptr)
			return nullptr;
		pNode cur = _root;
		while (cur)
		{
			if (cur->_data == val)
			{
				return cur;
			}
			else if (cur->_data > val)
			{
				cur = cur->_pleft;
			}
			else
			{
				cur = cur->_pright;
			}
		}
		return nullptr;
	}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)
			{
				cur = cur->_pleft;
			}
			else if (cur->_data < val)
			{
				cur = cur->_pright;
			}
			else
			{
				return false;
			}
		}
		pNode newNode = new Node(val);
		if (parent->_data>val)
		{
			parent->_pleft = newNode;
		}
		else{
			parent->_pright = newNode;
		}
		return true;
	}

	bool erase(const T&val)
	{
		if (_root == nullptr)
		{
			return false;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_data == val)
			{
				break;
			}
			if (cur->_data > val)
			{
				parent = cur;
				cur = cur->_pleft;
			}
			else
			{
				parent = cur;
				cur = cur->_pright;
			}
		}
		//��ʼɾ��
		//1.ɾ��Ҷ�ӽڵ�
		if (cur->_pleft == nullptr&&cur->_pright == nullptr)
		{
			//�Ƿ�ɾ��_root
			if (cur != _root)
			{
				//�ø��׽ڵ��Ӧλ����Ϊ��
				if (parent->_pleft == cur)
				{
					parent->_pleft = nullptr;
				}
				else{
					parent->_pright = nullptr;
				}
			}
			else{
				//ɾ��_root ��Ϊ��
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pleft == nullptr)
		{
			if (cur != _root)
			{
				//ȷ����ǰ�ڵ��ڸ��׽ڵ����߻����ұߣ���Ӧλ����Ϊcur->_pright
				if (parent->_pleft ==cur)
				{
					parent->_pleft = cur->_pright;
				}
				else
				{
					parent->_pright = cur->_pright;
				}
			}
			else
			{
				//����root
				_root = _root->_pright;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pright == nullptr)
		{
			if (cur != _root)
			{
				//ȷ����ǰ�ڵ��Ǹ��׽ڵ���߻����ұߣ���Ӧλ������Ϊcur->_pleft
				if (parent->_pleft == cur)
				{
					parent->_pleft = cur->_pleft;
				}
				else{
					parent->_pright = cur->_pleft;
				}
			}
			delete cur;
			cur = nullptr;
		}
		else
		{
			//cur ���Һ��Ӷ�����
			//1.Ѱ���滻�ڵ�
			pNode pNext = cur->_pleft;
			parent = cur;
			while (pNext->_pright)
			{
				parent = pNext;
				pNext = pNext->_pright;
			}
			//2.�û�
			cur->_data = pNext->_data;
			//ָ���û��ڵ��ָ���ÿ�
			if (parent->_pright == pNext)
			{
				parent->_pright = nullptr;
			}
			parent->_pleft = nullptr;
			//3.ɾ���û��ڵ�
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pleft);
			cout << root->_data <<" ";
			_Inorder(root->_pright);
		}
	}
	~BSTree()
	{
		Distory(_root);
	}
	void Distory(pNode root)
	{
		if (root)
		{
			Distory(root->_pleft);
			Distory(root->_pright);
			delete root;
			root = nullptr;
		}
	}
private:
	pNode _root;
};

void test()
{/*
	BSTree<int> bt;
	bt.insert(5);
	bt.Inorder();
	bt.insert(4);
	bt.Inorder();
	bt.insert(3);
	bt.Inorder();
	bt.insert(2);
	bt.Inorder();
	bt.insert(1);
	bt.Inorder();*/
	BSTree<int> bt;
	bt.insert(5);
	//bt.Inorder();
	bt.insert(3);
	//bt.Inorder();
	bt.insert(4);
	//bt.Inorder();
	bt.insert(1);
	//bt.Inorder();
	bt.insert(0);
	//bt.Inorder();
	bt.insert(2);
	//bt.Inorder();
	bt.insert(7);
	//bt.Inorder();
	bt.insert(6);
	//bt.Inorder();
	bt.insert(8);
	bt.insert(9);
	bt.Inorder();
	bt.erase(4);
	bt.Inorder();
	bt.erase(8);
	bt.Inorder();
	bt.erase(0);
	bt.Inorder();
	bt.erase(1);
	bt.Inorder();
	bt.erase(2);
	bt.Inorder();
	bt.erase(5);
	bt.Inorder();
	bt.erase(3);
	bt.Inorder();
	bt.erase(7);
	bt.Inorder();
	bt.erase(6);
	bt.Inorder();
	bt.erase(9);
	bt.Inorder();
}
int main()
{
	test();
	return 0;
}

//#include <iostream>
//using namespace std;
//template <class T>
//struct BSTNode
//{
//	BSTNode(const T& val = T())
//	:_data(val)
//	, _pLeft(nullptr)
//	, _pRight(nullptr)
//	{}
//	T _data;
//	BSTNode<T>* _pLeft;
//	BSTNode<T>* _pRight;
//};
//
//template <class T>
//class BSTree
//{
//public:
//	typedef BSTNode<T> Node;
//	typedef Node* pNode;
//
//	BSTree(const pNode root = nullptr)
//		:_root(root)
//	{}
//
//	pNode find(const T& val)
//	{
//		if (_root == nullptr)
//			return nullptr;
//		pNode cur = _root;
//		while (cur)
//		{
//			if (cur->_data == val)
//				return cur;
//			else if (cur->data > val)
//			{
//				cur = cur->_pLeft;
//			}
//			else
//			{
//				cur = cur->_pRight;
//			}
//		}
//		return nullptr;
//	}
//
//	bool insert(const T& val)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(val);
//			return true;
//		}
//		pNode cur = _root;
//		pNode parent = nullptr;
//		while (cur)
//		{
//			parent = cur;
//			if (cur->_data > val)
//			{
//				cur = cur->_pLeft;
//			}
//			else if (cur->_data < val)
//			{
//				cur = cur->_pRight;
//			}
//			else
//				return false;
//		}
//
//		pNode newNode = new Node(val);
//		if (parent->_data > val)
//		{
//			parent->_pLeft = newNode;
//		}
//		else
//			parent->_pRight = newNode;
//
//		return true;
//	}
//
//	bool erase(const T& val)
//	{
//		if (_root == nullptr)
//			return false;
//		pNode cur = _root;
//		pNode parent = nullptr;
//		while (cur)
//		{
//			if (cur->_data == val)
//				break;
//			else if (cur->_data > val)
//			{
//				parent = cur;
//				cur = cur->_pLeft;
//			}
//			else
//			{
//				parent = cur;
//				cur = cur->_pRight;
//			}
//		}
//
//		//ɾ��
//		//1. ɾ��Ҷ�ӽڵ�
//		if (cur->_pLeft == nullptr && cur->_pRight == nullptr)
//		{
//			//�Ƿ�ɾ��_root
//			if (cur != _root)
//			{
//				//�ø��׽ڵ��Ӧλ����Ϊ��
//				if (parent->_pLeft == cur)
//					parent->_pLeft = nullptr;
//				else
//					parent->_pRight = nullptr;
//			}
//			else
//			{
//				//ɾ��_root, ��Ϊ��
//				_root = nullptr;
//			}
//			delete cur;
//			cur = nullptr;
//		}
//		else if (cur->_pLeft == nullptr)
//		{
//			if (cur != _root)
//			{
//				//ȷ����ǰ�ڵ��ڸ��׽ڵ����߻����ұߣ���Ӧλ����Ϊcur->_pRight
//				if (parent->_pLeft == cur)
//					parent->_pLeft = cur->_pRight;
//				else
//					parent->_pRight = cur->_pRight;
//			}
//			else
//			{
//				//����_root
//				_root = _root->_pRight;
//			}
//			delete cur;
//			cur = nullptr;
//		}
//		else if (cur->_pRight == nullptr)
//		{
//			if (cur != _root)
//			{
//				if (parent->_pLeft == cur)
//					parent->_pLeft = cur->_pLeft;
//				else
//					parent->_pRight = cur->_pLeft;
//			}
//			else
//			{
//				_root = _root->_pLeft;
//			}
//			delete cur;
//			cur = nullptr;
//		}
//		else
//		{
//			//cur ���Һ��Ӷ�����
//			//1. Ѱ���滻�ڵ�
//			pNode pNext = cur->_pLeft;  // 3   5
//			parent = cur;
//			while (pNext->_pRight)
//			{
//				parent = pNext;  // 3  4
//				pNext = pNext->_pRight;
//			}
//
//			//2. �û�
//			cur->_data = pNext->_data;
//			//ָ���û��ڵ��ָ���ÿ�
//			if (parent->_pRight == pNext)
//				parent->_pRight = nullptr;
//			parent->_pLeft = nullptr;
//
//			//3. ɾ���û��ڵ�
//			delete pNext;
//			pNext = nullptr;
//		}
//		return true;
//	}
//
//	void Inorder()
//	{
//		_Inorder(_root);
//		cout << endl;
//	}
//
//	void _Inorder(pNode root)
//	{
//		if (root)
//		{
//			_Inorder(root->_pLeft);
//			cout << root->_data << " ";
//			_Inorder(root->_pRight);
//		}
//	}
//
//	~BSTree()
//	{
//		Distory(_root);
//	}
//
//	void Distory(pNode root)
//	{
//		if (root)
//		{
//			Distory(root->_pLeft);
//			Distory(root->_pRight);
//			delete root;
//			root = nullptr;
//		}
//	}
//
//private:
//	pNode _root;
//};
//
//void testTree()
//{
//	BSTree<int> bt;
//	bt.insert(5);
//	//bt.Inorder();
//	bt.insert(3);
//	//bt.Inorder();
//	bt.insert(4);
//	//bt.Inorder();
//	bt.insert(1);
//	//bt.Inorder();
//	bt.insert(0);
//	//bt.Inorder();
//	bt.insert(2);
//	//bt.Inorder();
//	bt.insert(7);
//	//bt.Inorder();
//	bt.insert(6);
//	//bt.Inorder();
//	bt.insert(8);
//	bt.insert(9);
//	bt.Inorder();
//	bt.erase(4);
//	bt.Inorder();
//	bt.erase(8);
//	bt.Inorder();
//	bt.erase(0);
//	bt.Inorder();
//	bt.erase(1);
//	bt.Inorder();
//	bt.erase(2);
//	bt.Inorder();
//	bt.erase(5);
//	bt.Inorder();
//	bt.erase(3);
//	bt.Inorder();
//	bt.erase(7);
//	bt.Inorder();
//	bt.erase(6);
//	bt.Inorder();
//	bt.erase(9);
//	bt.Inorder();
//}
//int main()
//{
//	testTree();
//	return 0;
//}