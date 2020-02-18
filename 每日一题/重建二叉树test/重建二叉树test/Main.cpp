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
			return NULL;//�������г���С�ڵ���0 ֱ�ӷ���
		}
		TreeNode* root = new TreeNode(0);//����һ���½ڵ㣬����ŵ�ǰ�������ĸ��ڵ�
		root->val = preorder[preL];

		int k;
		for (int k = inL; k <= inR; k++)
		{
			if (inorder[k] == preorder[preL])
			{
				break;
			}
		}
		int numLeft = k - inL;//�������Ľ����

		///����������������Ϊ[preL+1,preL+numLeft] ��������Ϊ[inL,k-1]
		//�������������ڵ��ַ����ֵ��root��ָ��
		root->left = create(preL + 1, preL + numLeft, inL, k - 1);

		//��������������Ϊ[preL+numLeft+1,preR] ��������[k+1,inR]
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