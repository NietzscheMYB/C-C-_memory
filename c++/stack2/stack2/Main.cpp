//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//void preorder(TreeNode* root,vector<int> &v)
//{
//	if (root == nullptr)
//		return;
//	v.push_back(root->val);
//	preorder(root->left, v);
//	preorder(root->right, v);
//}
//vector <int> preorderTraversal(TreeNode* root)
//{
//	vector<int> v;
//	preorder(root, v);
//	return v;
//}
//vector <int> preorderTraversal(TreeNode* root)
//{
//	vector<int> v;
//	stack < TreeNode*) st;
//	TreeNode* cur = root;
//	while (cur || !st.empty())
//	{
//		//先遍历左节点
//		while (cur)
//		{
//			st.push(cur);
//			v.push_back(cur->val);
//			cur = cur->left;
//		}
//		cur = st.top();
//		st.pop();
//		cur = cur->right;
//	}
//	return v;
//}
/////////////////////////////
//bool getPath(TreeNode* cur, TreeNode *node, stack<TreeNode*>& s)
//{
//	if (cur == nullptr)
//	{
//		return false;
//	}
//	//先入栈
//	s.push(cur);
//	//当前节点是要找的节点，说明路径搜索完成
//	if (cur == node)
//	{
//		return true;
//	}
//	//当前节点不是要找到的节点，再去看左右节点
//	if (getPath(cur->left, node, s))
//	{
//		return true;
//	}
//	if (getPath(cur->right, node, s))
//	{
//		return true;
//	}
//	//当前节点不存在要寻找的节点的路径上，出栈
//	s.pop();
//	return false;
//}
//
//TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//	stack<TreeNode*> path1;
//	stack<TreeNode*> path2;
//	//获取路径
//	getPath(root, p, path1);
//	getPath(root, q, path2);
//	//路径裁剪，使路径长度一致
//	while (path1.size() != path2.size())
//	{
//		if (path1.size() > path2.size())
//		{
//			path1.pop();
//		}
//		else{
//			path2.pop();
//		}
//	}
//	//寻找第一个相同的节点，即为公共祖先
//	while (!path1.empty())
//	{
//		if (path1.top() == path2.top())
//		{
//			break;
//			//return path1.top();
//		}
//		path1.pop();
//		path2.pop();
//	}
//	return payh1.top();
//}

/*两个队列实现栈
栈：后进先出
1.始终保持一个队列是空的
2.入栈时，元素向非空队列入队
3.出栈时，元素先导入空队列，出非空队列的最后一个元素*/