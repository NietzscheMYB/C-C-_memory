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
	bool DFS(TreeNode* root, int sum)
	{
		if (root == NULL)
		{
			return false;
		}
		if (!root->right&&!root->left&&sum == root->val)
		{
			return true;
		}
		return DFS(root->left, sum - root->val) || DFS(root->right, sum - root->val);
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
		{
			return false;
		}
		return DFS(root, sum);
	}
};

int main()
{
	//ע��Ҷ�Ӽ��������Ӻ��Һ��Ӷ�û�У�������
	return 0;
}