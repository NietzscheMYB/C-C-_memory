#include <iostream>
#include <queue>
#include <list>
using namespace std;
//
////Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Solution{
// public:
//	 //�õ����ĸ߶�
//	 int getHegight(TreeNode* root)  
//	 {
//		 if (root == nullptr)
//		 {
//			 return 0;
//		 }
//		 int left = getHegight(root->left);
//		 int right = getHegight(root->right);
//		 return left > right ? left + 1 : right + 1;
//	 }
//	 vector<vector<int>> levelOrder(TreeNode* root)
//	 {
//
//	 }
// };

//����������ݹ�
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		if (pRoot == nullptr)
//		{
//			return;
//		}
//		swap(pRoot->left, pRoot->right);
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//};

//�������ľ��� �ǵݹ�汾
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
//};*/
//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) {
//		queue<TreeNode*> q;
//		if (pRoot)
//		{
//			q.push(pRoot);
//		}
//		while (!q.empty())
//		{
//			TreeNode* cur = q.front();
//			q.pop();
//			swap(cur->left, cur->right);
//			if (cur->left)
//			{
//				q.push(cur->left);
//			}
//			if (cur->right)
//			{
//				q.push(cur->right);
//			}
//		}
//	}
//};



//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int> pq;
//		for (const auto& e : nums)
//		{
//			pq.push(e);
//		}
//		for (int i = 0; i<k - 1; i++)
//		{
//			pq.pop();
//		}
//		return pq.top();
//	}
//};

#include <functional>
class Date{
public:
	Date (int y, int m, int d)
		:
		_y(y), _m(m), _d(d)
	{
		
	}
	bool operator<(const Date&d) const
	{
		return _y < d._y || (_y == d._y&&_m < d._m)
			|| (_y == d._y&&_m == d._m&&_d < d._d);
	}
	bool operator>(const Date&d) const
	{
		
	}
	friend ostream operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._y << '-' << d._m << '-' << d._d << endl;
	}
private:
	size_t _y;
	size_t _m;
	size_t _d;
};
//int main()
//{
//	//Ĭ���Ǵ��
//	priority_queue<int> pq;
//	//��������ΪС��
//	//priority_queue<int,vector<int>,qreater<int>> pq;
//
//	pq.push(100);
//	pq.push(50);
//	pq.push(3);
//	pq.push(1);
//	pq.push(18);
//	pq.push(19);
//	while (!pq.empty())
//	{
//		cout << pq.top() << endl;
//		pq.pop();
//	}
//
//	return 0;
//
//}

template<class T,class Container>
class Stack{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_back();
	}
	T& Top()
	{
		return _con.back();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};

//Ĭ��˫�˶���
template<class T,class Container=deque<T>>  //container ������
class Queue
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	T& Front()
	{
		return _con.front();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
	T& Back()
	{
		return _con.back();
	}

private:
	Container _con;
};

void test1()
{
	//vector ʵ��ջ
	//Stack<int, vector<int>> st;
	//list ʵ��ջ
	Stack<int, list<int>> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	while (!st.Empty())
	{
		cout << st.Top() << endl;
		st.Pop();
	}
}
void test2()
{
	//list ʵ�ֶ���   //vector ʵ�ֲ��ˣ���Ϊvectorû��pop_front
	Queue<int, list<int>> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	while (!st.Empty())
	{
		cout << st.Front() << endl;
		st.Pop();
	}
}



class Greater
{
public:
	//��������
	bool operator()(const int& a, const int& b)
	{
		return a > b;
	}
};
class Less{
public:
	bool operator()(const int& a, const int& b)
	{
		return a < b;
	}
};
void test3()
{
	Greater g;
	Less l;
	cout << g(2, 3) << endl;
	cout << l(2,3) << endl;
	priority_queue<int, vector<int>, Greater> d;
	d.push(1);
	d.push(2);
	d.push(3);
	d.push(4);
	d.push(5);
	while (!d.empty())
	{
		cout << d.top() << endl;
		d.pop();
	}
}
template <class T,class Container=vector<T>,class Compare>
class PriortyQueue
{
public:
	void Push(const T& val)
	{
		//�Ȱ�Ԫ�طŵ���������һ��λ��
		_con.push_back(val);
		//���ϵ�����ʹ������ѵ�����
		shiftUp(_con.size() - 1);
	}
	void shiftUp(size_t child)
	{
		//����һ���º�����ͨ���º����Ķ���ıȽϹ���Զ�Ԫ�ؽ��е���
		compare _cmp;//�º�������
		//�͸��׽ڵ�Ƚϴ�С
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				//���¸��ӽڵ�
				child = parent;
				parent = (child - 1) / 2;
			}
			else{
				break;
			}
		}
	}
	void shiftDown(size_t parent)
	{
		size_t child = 2 * parent + 1;
		while (child<_con.size())
		{
			//����к��Ӵ��ڣ���ֵ�������ӵ�ֵ��ȡ�Һ���
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
			{
				child++;
			}
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}

	void Pop()
	{
		//������Ԫ�غ����һ��Ҷ�ӽڵ�Ԫ��
		swap(_con[0], _con[_con.size() - 1]);
		//ɾ�����һ��Ԫ��
		_con.pop_back();
		//�Ӹ������µ�����ʹ������ѵ�����
		shiftDown(0);
	}
	T& Top()
	{
		return _con[0];
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Size()
	{
		return _con.size();
	}
private:
	Container _con;
};
void test4()
{
	PriortyQueue<int, vector<int>>pq;
	pq.Push(1);
	pq.Push(2);
	pq.Push(3);
	pq.Push(4);
	pq.Push(5);
	while (!pq.Empty())
	{
		cout << pq.Top() << endl;
		pq.Pop();
	}
}
int  main()
{
	test4();
	return 0;
}