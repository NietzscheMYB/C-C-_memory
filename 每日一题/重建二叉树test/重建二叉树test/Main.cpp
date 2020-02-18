#include<iostream>
#include<vector>
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
	vector<int> preorder;
	vector<int> inorder;
	TreeNode* create(int preL, int preR, int inL, int inR)
	{
		if (preL>preR)
		{
			return NULL;//先序序列长度小于等于0 直接返回
		}
		TreeNode* root = new TreeNode(0);//创建一个新节点，来存放当前二叉树的根节点
		root->val = preorder[preL];

		int k;
		for (int k = inL; k <= inR; k++)
		{
			if (inorder[k] == preorder[preL])
			{
				break;
			}
		}
		int numLeft = k - inL;//左子树的结点数

		///左子树的先序区间为[preL+1,preL+numLeft] 中序区间为[inL,k-1]
		//返回左子树根节点地址，赋值给root左指针
		root->left = create(preL + 1, preL + numLeft, inL, k - 1);

		//右子树先序区间为[preL+numLeft+1,preR] 中序区间[k+1,inR]
		root->right = create(preL + numLeft + 1, preR, k + 1, inR);

		return root;
	}
	TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
		preorder = pre;
		inorder = ino;
		return create(0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};
int main()
{

	return 0;
}