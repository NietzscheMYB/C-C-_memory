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
//		//�ȱ�����ڵ�
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
//	//����ջ
//	s.push(cur);
//	//��ǰ�ڵ���Ҫ�ҵĽڵ㣬˵��·���������
//	if (cur == node)
//	{
//		return true;
//	}
//	//��ǰ�ڵ㲻��Ҫ�ҵ��Ľڵ㣬��ȥ�����ҽڵ�
//	if (getPath(cur->left, node, s))
//	{
//		return true;
//	}
//	if (getPath(cur->right, node, s))
//	{
//		return true;
//	}
//	//��ǰ�ڵ㲻����ҪѰ�ҵĽڵ��·���ϣ���ջ
//	s.pop();
//	return false;
//}
//
//TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//	stack<TreeNode*> path1;
//	stack<TreeNode*> path2;
//	//��ȡ·��
//	getPath(root, p, path1);
//	getPath(root, q, path2);
//	//·���ü���ʹ·������һ��
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
//	//Ѱ�ҵ�һ����ͬ�Ľڵ㣬��Ϊ��������
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

/*��������ʵ��ջ
ջ������ȳ�
1.ʼ�ձ���һ�������ǿյ�
2.��ջʱ��Ԫ����ǿն������
3.��ջʱ��Ԫ���ȵ���ն��У����ǿն��е����һ��Ԫ��*/