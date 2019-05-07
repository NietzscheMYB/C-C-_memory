#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
	struct TreeNode* left;
	struct TreeNode* right;
	char value;
}TreeNode;

//typedef struct Result{
//	TreeNode *root;//���������ĸ��ڵ�
//	int used;//�����������õ���val��
//}Result;
//
//Result CreateTree(char preorder[], int size)
//{
//	//�������
//	if (size == 0)
//	{
//		Result result;
//		result.root = NULL;
//		result.used = 0;
//		return result;
//	}
//	char rootVal = preorder[0];
//	if (rootVal == '#')
//	{
//		Result result;
//		result.root = NULL;
//		result.used = 1;
//		return result;
//	}
//	//����
//
//	//��
//	TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
//	root->value = rootVal;
//	root->left = root->right = NULL;
//
//	//������
//	Result left_result = CreateTree(preorder + 1, size - 1);
//
//	//������
//	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);
//
//	root->left = left_result.root;
//	root->right = right_result.root;
//
//	Result result;
//	result.root = root;
//	result.used = 1 + left_result.used + right_result.used;
//
//	return result;
//}

typedef struct Result{
	TreeNode* root;
	int used;
}Result;

Result CreateTree(char preorder[],int size)
{
	if (size == 0)
	{
		Result result;
		result.root = NULL;
		result.used = 0;
		return result;
	}

	char valRoot = preorder[0];
	if (valRoot == '#')
	{

		Result result;
		result.root = NULL;
		result.used = 1;
		return result;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->value = valRoot;
	root->left = root->right = NULL;


	Result left_result = CreateTree(preorder + 1, size - 1);

	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);


	root->left = left_result.root;
	root->right = right_result.root;

	Result x;
	x.root = root;
	x.used = 1 + left_result.used + right_result.used;
	return x;

}

void Preorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->value);
	Preorder(root->left);
	Preorder(root->right);
}


void Test()
{
	char arr[] = { "abd###c#ef" };
	int size = strlen(arr);
	Result root= CreateTree(arr, size);
	Preorder(root.root);
}
int main()
{
	Test();
	return 0;
}