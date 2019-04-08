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
//	 //得到树的高度
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

//镜像二叉树递归
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

//二叉树的镜像 非递归版本
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
//	//默认是大堆
//	priority_queue<int> pq;
//	//可以设置为小堆
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

//默认双端队列
template<class T,class Container=deque<T>>  //container 适配器
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
	//vector 实现栈
	//Stack<int, vector<int>> st;
	//list 实现栈
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
	//list 实现队列   //vector 实现不了，因为vector没有pop_front
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
	//重载括号
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
		//先把元素放到数组的最后一个位置
		_con.push_back(val);
		//向上调整，使其满足堆的性质
		shiftUp(_con.size() - 1);
	}
	void shiftUp(size_t child)
	{
		//定义一个仿函数，通过仿函数的对象的比较规则对堆元素进行调整
		compare _cmp;//仿函数对象
		//和父亲节点比较大小
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_con[child] > _con[parent])
			{
				swap(_con[child], _con[parent]);
				//更新父子节点
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
			//如果有孩子存在，且值大于左孩子的值，取右孩子
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
		//交换根元素和最后一个叶子节点元素
		swap(_con[0], _con[_con.size() - 1]);
		//删除最后一个元素
		_con.pop_back();
		//从根部向下调整，使其满足堆的性质
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