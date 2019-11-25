#include<iostream>
using namespace std;

//* Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr&&q==nullptr)
		{
			return true;
		}
		if (p == nullptr&&q != nullptr)
		{
			return false;
		}
		if (p != nullptr&&q == nullptr)
		{
			return false;
		}
		bool ret1 = false, ret2 = false;
	
		

		if (p->val == q->val)
		{
			if (p->left != nullptr&&q->left != nullptr)
			{
				ret1 = isSameTree(p->left, q->left);

			}
			if (p->right != nullptr&&q->right != nullptr)
			{
				ret2 = isSameTree(p->right, q->right);
			}
		}
		else{
			return false;
		}
		return ret1&&ret2;
	}
};