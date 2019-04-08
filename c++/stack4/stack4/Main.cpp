#include <iostream>
#include <queue>
#include <functional> //greater算法头文件
#include <vector>
using namespace std;
////给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
////例如 :
////给定二叉树 : [3, 9, 20, null, null, 15, 7],
//struct TreeNode{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
//};
////用两个队列和一个二维数组
////一个队列存节点
////另一个队列存节点对应的层号
////按照层号放入对应的二维数组的行中
//
//class Solution{
//public:
//	//得到二叉树的高度
//	int getHeight(TreeNode* root)
//	{
//		if (root == nullptr)
//		{
//			return 0;
//		}
//		int left = getHeight(root->left);
//		int right = getHeight(root->right);
//		return left > right ? left + 1 : right + 1;
//	}
//	vector<vector<int>> levelOrder(TreeNode* root)
//	{
//		//定义一个二维数组
//		vector<vector<int>> treeVec;
//		//使得二维数组的行数与树的高度一致
//		treeVec.resize(getHeight(root));
//		//定义一个队列存放节点
//		queue<TreeNode*> node;
//		//定义一个队列存放对应的序号
//		queue<int> index;
//		//入队根节点
//		if (root == nullptr)
//		{
//			return;
//		}
//		if (root)
//		{
//			node.push(root);
//			index.push(0);
//		}
//		//遍历队列
//		//先使node队列出列 存放到二维数组中
//		while (!node.empty())
//		{
//			TreeNode* cur = node.front();
//			node.pop();
//			int curIndex = index.front();
//			index.pop();
//			//按照层号存放当前节点
//			treeVec[curIndex].push_back(cur->val);
//			//带出下一个节点的子节点
//			if (cur->left)
//			{
//				node.push(cur->left);
//				index.push(curIndex + 1);
//			}
//			if (cur->right)
//			{
//				node.push(cur->right);
//				index.push(curIndex + 1);
//			}
//
//		}
//		return treeVec;
//	}
//};


//二叉树的镜像
//操作给定的二叉树，将其变换为源二叉树的镜像。
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x), left(nullptr), right(nullptr){}
};
//递归版本

//class Solution{
//public:
//	void Mirror(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)
//		{
//			return;
//		}
//		swap(pRoot->left, pRoot->right);
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//};

//非递归版本
//class Solution{
//public:
//	void Mirror(TreeNode* pRoot)
//	{
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




//priority_queue
//优先级队列默认使用vector作为其底层存储数据的容器
//在vector上又使用堆算法将vector中的元素构造成堆 的结构
//因此priority_queue就是堆，所有需要用到堆的位置
//都要考虑用到priority_queue
//默认是大堆

void TestPriorityQueue()
{
	//默认情况下，创建的是大堆，其底层按照小于号比较
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int> q1;
	for (auto e : v)
	{
		q1.push(e);
	}
	for (int i = 0; i < q1.size(); i++)
	{
		cout << q1.top() << endl;
		q1.pop();
	}
	cout << endl; 
	//建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	for (int i = 0; i < q2.size(); i++)
	{
		cout << q2.top() << endl;
		q2.pop();
	}
}
int main()
{
	TestPriorityQueue();
	return 0;
}