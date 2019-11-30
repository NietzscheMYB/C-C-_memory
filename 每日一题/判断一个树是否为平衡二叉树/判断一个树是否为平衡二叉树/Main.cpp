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

class Solution {
public:
	int count(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (root->left == nullptr&&root->right == nullptr)
		{
			return 1;
		}
		int ret1 = 0;
		int ret2 = 0;
		if (root->left)
		{
			ret1 = count(root->left) + 1;
		}
		if (root->right)
		{
			ret2 = count(root->right) + 1;
		}

		return ret1 > ret2 ? ret1 : ret2;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}
		int left = count(root->left);
		int right = count(root->right);
		if (abs(right - left) <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
		return false;
	}
};


 //class Solution {
 //public:
	// int countleft(TreeNode* root)
	// {
	//	 if (root == nullptr)
	//	 {
	//		 return 0;
	//	 }
	//	 if (root->left == nullptr)
	//	 {
	//		 return 1;
	//	 }
	//	 return countleft(root->left) + 1;
	// }
	// int countright(TreeNode* root)
	// {
	//	 if (root == nullptr)
	//	 {
	//		 return 0;
	//	 }
	//	 if (root->right == nullptr)
	//	 {
	//		 return 1;
	//	 }
	//	 return countright(root->right) + 1;
	// }

	// void test(TreeNode* root)
	// {
	//	 if (root == nullptr)
	//	 {
	//		 return ;
	//	 }
	//	 test(root->left);
	//	 test(root->right);
	//	 int left = 0, right = 0;
	//	 left = countleft(root);



	// }

	// bool isBalanced(TreeNode* root) {

	// }
 //};

int main()
{
	return 0;
}





