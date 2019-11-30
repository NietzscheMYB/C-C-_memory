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
	bool xd(TreeNode*s, TreeNode*t)
	{
		if (s == nullptr&&t == nullptr)
		{
			return true;
		}
		if (s != nullptr&&t != nullptr)
		{
			if (s->val == t->val)
			{
				return xd(s->left, t->left) && xd(s->right, t->right);
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	bool test(TreeNode*s, TreeNode*t)
	{
		if (s == nullptr&&t == nullptr)
		{
			return true;
		}
		bool ret=false;
		if (s != nullptr&&t != nullptr)
		{
			if (s->val == t->val)
			{
				ret=xd(s, t);
			}
			if (!ret)
			{
				ret=test(s->left, t)||test(s->right, t);
			}
			return ret;

		}
		return false;
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return test(s, t);
	}
};

int main()
{
	return 0;
}