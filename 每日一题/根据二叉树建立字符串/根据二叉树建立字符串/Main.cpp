#include<iostream>
//#include<sstream>
#include<string>
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
	 string tree2str(TreeNode* t) {
		 string res = "";
		 if (t == NULL)
		 {
			 return res;
		 }
		 if (t->left == NULL&&t->right == NULL)
		 {
			 res.append(to_string(t->val));
			 return res;
		 }
		 res.append(to_string(t->val));
		 res += ("(" + tree2str(t->left) + ")");
		 if (t->right != NULL)
		 {
			 res += ("(" + tree2str(t->right) + ")");
		 }
		 return res;
	 }
 };
 int main()
 {
	 return 0;
 }