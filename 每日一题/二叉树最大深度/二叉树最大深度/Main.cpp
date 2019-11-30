#include<iostream>
#include<queue>
using namespace std;


//* Definition for a binary tree node.
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//class Solution {
//public:
//	int max = 0;
//	int count(TreeNode* root)
//	{
//		int x1 = 0, x2 = 0;
//		if (root == nullptr)
//		{
//			return 0;
//		}
//		if (root->left == nullptr&&root->right == nullptr)
//		{
//			return 1;
//		}
//		if (root->left)
//		{
//			x1=count(root->left) + 1;
//		}
//		if (root->right)
//		{
//			x2 = count(root->right) + 1;
//		}
//		return x1 > x2 ? x1 : x2;
//
//	}
//	int maxDepth(TreeNode* root) {
//		return count(root);
//	}
//};

 class Solution {
 public:
	 int maxDepth(TreeNode* root) {
		 if (root == nullptr)
		 {
			 return 0;
		 }
		 queue<TreeNode*> q;
		 q.push(root);
		 int num = 0;
		 while (!q.empty())
		 {
			 int n = q.size();
			 for (int i = 0; i < n; i++)
			 {
				 TreeNode* pcur = q.front();
				 q.pop();
				 if (pcur->left)
				 {
					 q.push(pcur->left);
				 }
				 if (pcur->right)
				 {
					 q.push(pcur->right);
				 }
			 }
			 num++;
		 }
		 //其实就是判断多少层
		 return num;

	 }
 };

 int main()
 {
	 return 0;
 }