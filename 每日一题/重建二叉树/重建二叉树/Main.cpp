 
#include<iostream>
#include<vector>
using namespace std;

//  Definition for binary tree
  struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
		{
			return nullptr;
		}
		TreeNode* node = new TreeNode(pre[0]);//�õ���ǰ�ڵ��ֵ����
		vector<int> leftpre;//��ǰ�ڵ���������ǰ������Ľ��
		vector<int> leftvin;//��ǰ�ڵ�����������������Ľ��

		vector<int> rightpre;//��ǰ�ڵ���������ǰ������Ľ��
		vector<int> rightvin;//��ǰ�ڵ�����������������Ľ��
		for (int i = 0; i < vin.size(); i++)
		{
			leftvin.push_back(vin[i]);
			if (pre[0] == vin[i])
			{
				leftvin.pop_back();
				for (int j = 1; j <i+1; j++)
				{
					leftpre.push_back(pre[j]);
				}
				for (int k = i + 1; k < vin.size(); k++)
				{
					rightpre.push_back(pre[k]);
					rightvin.push_back(vin[k]);
				}
				node->left = reConstructBinaryTree(leftpre,leftvin);
				node->right = reConstructBinaryTree(rightpre,rightvin);
			}
		}
		return node;
	}
};

int main()
{


	return 0;
}