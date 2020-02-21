#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//* Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> ans;
	void BFS(TreeNode* root)
	{
		queue<TreeNode*> q;
		q.push(root);
		int flag = 0;
		while (!q.empty())
		{
			vector<int> v;
			int len = q.size();
			for (int i = 0; i<len; i++)
			{
				TreeNode* tem = q.front();
				q.pop();
				v.push_back(tem->val);
				if (tem->left){ q.push(tem->left); }
				if (tem->right){ q.push(tem->right); }
			}
			ans.push_back(v);
		}
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL)
		{
			return ans;
		}
		BFS(root);
		return ans;
	}
};
int main()
{
	return 0;
}