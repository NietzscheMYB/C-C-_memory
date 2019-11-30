#include<iostream>
#include<queue>
#include<vector>
using namespace std;



//* Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


#if 0
 class Solution {
 public:
	 bool fun(TreeNode* root)
	 {
		 if (root == nullptr)
		 {
			 return true;
		 }
		 vector<TreeNode*> v;
		 v.push_back(root);
		 //v.push_back(root->left);
		// v.push_back(root->right);


		 while (!v.empty())
		 {
			 int n = v.size();
			 int begin = 0;
			int end = n - 1;
			 //end--;
			 int flag = 0;
			 while (begin < end)
			 {
				 if (v[begin] != nullptr&&v[end] != nullptr)
				 {
					 if (v[begin]->val == v[end]->val)
					 {
						 flag = 1;

					 }
					 else{
						 flag = 0;
						 break;
					 }
					 begin++;
					 end--;
					 continue;
				 }
				 return false;
			 }
			 if (flag == 0&&begin!=end)
			 {
				 return false;
			 }

			 for(int i = 0; i < n; i++)
			 {
				 TreeNode* x = v[0];
				 if (x != nullptr)
				 {
					 if (x->left)
					 {
						 v.push_back(x->left);
					 }
					 else{
						 v.push_back(nullptr);
					 }
					 if (x->right)
					 {
						 v.push_back(x->right);
					 }
					 else{
						 v.push_back(nullptr);
					 }
				 }
				 v.erase(v.begin());
			 }
		 }
		 return true;
	 }
	 bool isSymmetric(TreeNode* root) {
		 return fun(root);
	 }
 };
#endif


class Solution {
 public:

	 bool fun(TreeNode* root1, TreeNode* root2)
	 {
		 if (root1 == nullptr&&root2 == nullptr)
		 {
			 return true;
		 }
		 if (root1 != nullptr&&root2 != nullptr)
		 {
			 if (root1->val == root2->val)
			 {
				 return fun(root1->left,root2->right)&&fun(root1->right,root2->left);
			 }
		 }
		 return false;
	 }

	 bool isSymmetric(TreeNode* root) {
		 return fun(root, root);
	 }
 };


 int main()
 {
	 //vector<int> v;
	 //v.push_back(1);
	 //v.push_back(2);
	 //v.push_back(3);
	 //v.push_back(4);
	 //v.push_back(5);
	 //auto begin = v.begin();
	 //auto end = v.end();
	 //end--;
	 //while (begin <end)
	 //{
		// cout << *begin << " "<<*end<<" ";
		// begin++;
		// end--;
	 //}
	 //cout << *begin << endl;


	 TreeNode* root = new TreeNode(1);
	 TreeNode* l2 = new TreeNode(2);
	 TreeNode* r2= new TreeNode(2);
	 TreeNode* l3 = new TreeNode(3);
	 TreeNode* r4 = new TreeNode(4);
	 TreeNode* l4 = new TreeNode(4);
	 TreeNode* r3 = new TreeNode(3);
	 root->left = l2;
	 l2->left = l3;
	 l2->right = r4;
	 root->right = r2;
	 r2->left = l4;
	 r2->right = r3;

	 Solution s;
	 bool ret = s.isSymmetric(root);

 }