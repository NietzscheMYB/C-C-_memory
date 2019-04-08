#include <iostream>
#include <queue>
#include <functional> //greater�㷨ͷ�ļ�
#include <vector>
using namespace std;
////����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
////���� :
////���������� : [3, 9, 20, null, null, 15, 7],
//struct TreeNode{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
//};
////���������к�һ����ά����
////һ�����д�ڵ�
////��һ�����д�ڵ��Ӧ�Ĳ��
////���ղ�ŷ����Ӧ�Ķ�ά���������
//
//class Solution{
//public:
//	//�õ��������ĸ߶�
//	int getHeight(TreeNode* root)
//	{
//		if (root == nullptr)
//		{
//			return 0;
//		}
//		int left = getHeight(root->left);
//		int right = getHeight(root->right);
//		return left > right ? left + 1 : right + 1;
//	}
//	vector<vector<int>> levelOrder(TreeNode* root)
//	{
//		//����һ����ά����
//		vector<vector<int>> treeVec;
//		//ʹ�ö�ά��������������ĸ߶�һ��
//		treeVec.resize(getHeight(root));
//		//����һ�����д�Žڵ�
//		queue<TreeNode*> node;
//		//����һ�����д�Ŷ�Ӧ�����
//		queue<int> index;
//		//��Ӹ��ڵ�
//		if (root == nullptr)
//		{
//			return;
//		}
//		if (root)
//		{
//			node.push(root);
//			index.push(0);
//		}
//		//��������
//		//��ʹnode���г��� ��ŵ���ά������
//		while (!node.empty())
//		{
//			TreeNode* cur = node.front();
//			node.pop();
//			int curIndex = index.front();
//			index.pop();
//			//���ղ�Ŵ�ŵ�ǰ�ڵ�
//			treeVec[curIndex].push_back(cur->val);
//			//������һ���ڵ���ӽڵ�
//			if (cur->left)
//			{
//				node.push(cur->left);
//				index.push(curIndex + 1);
//			}
//			if (cur->right)
//			{
//				node.push(cur->right);
//				index.push(curIndex + 1);
//			}
//
//		}
//		return treeVec;
//	}
//};


//�������ľ���
//���������Ķ�����������任ΪԴ�������ľ���
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x), left(nullptr), right(nullptr){}
};
//�ݹ�汾

//class Solution{
//public:
//	void Mirror(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)
//		{
//			return;
//		}
//		swap(pRoot->left, pRoot->right);
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//};

//�ǵݹ�汾
//class Solution{
//public:
//	void Mirror(TreeNode* pRoot)
//	{
//		queue<TreeNode*> q;
//		if (pRoot)
//		{
//			q.push(pRoot);
//		}
//		while (!q.empty())
//		{
//			TreeNode* cur = q.front();
//			q.pop();
//			swap(cur->left, cur->right);
//			if (cur->left)
//			{
//				q.push(cur->left);
//			}
//			if (cur->right)
//			{
//				q.push(cur->right);
//			}
//		}
//	}
//};




//priority_queue
//���ȼ�����Ĭ��ʹ��vector��Ϊ��ײ�洢���ݵ�����
//��vector����ʹ�ö��㷨��vector�е�Ԫ�ع���ɶ� �Ľṹ
//���priority_queue���Ƕѣ�������Ҫ�õ��ѵ�λ��
//��Ҫ�����õ�priority_queue
//Ĭ���Ǵ��

void TestPriorityQueue()
{
	//Ĭ������£��������Ǵ�ѣ���ײ㰴��С�ںűȽ�
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int> q1;
	for (auto e : v)
	{
		q1.push(e);
	}
	for (int i = 0; i < q1.size(); i++)
	{
		cout << q1.top() << endl;
		q1.pop();
	}
	cout << endl; 
	//��С�ѣ���������ģ���������greater�ȽϷ�ʽ
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	for (int i = 0; i < q2.size(); i++)
	{
		cout << q2.top() << endl;
		q2.pop();
	}
}
int main()
{
	TestPriorityQueue();
	return 0;
}