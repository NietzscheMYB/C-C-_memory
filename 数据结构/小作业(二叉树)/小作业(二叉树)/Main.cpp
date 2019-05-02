#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	char val;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Result{
	Node *root;//构建的树的根节点
	int used;//构建过程中用掉的val个数
}Reslut;

Node *BuyNode(int val)
{
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Result CreatTree(char preorder[], int size)
{
	//特殊情况
	if (size == 0)
	{
		Result result;
		result.root = NULL;
		result.used = 0;
		return result;
	}
	char rootVal = preorder[0];
	if (rootVal == '#')
	{
		Result result;
		result.root = NULL;
		result.used = 1;
		return result;
	}
	//递推
	//根
	Node* root = (Node *)malloc(sizeof(Node));
	root->val = rootVal;
	root->left = root->left = NULL;

	//左子树
	Result left_result = CreatTree(preorder + 1, size - 1);

	//右子树
	Reslut right_result = CreatTree(preorder + 1 + left_result.used,
		size - 1 - left_result.used);

	root->left = left_result.root;
	root->right = right_result.root;

	Result result;
	result.root = root;
	result.used = 1 + left_result.used + right_result.used;
	return result;
}



//前序遍历
void Preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c   ", root->val);
	Preorder(root->left);
	Preorder(root->right);
}

//中序遍历
void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	printf("%c    ", root->val);
	Inorder(root->right);
}

//后续遍历
void Postorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%c    ", root->val);
}

void Test()
{
	char arr[] = { "123456" };
	Result root=CreatTree(arr, 6);
	Preorder(root.root);
}
int main()
{
	Test();
	return 0;
}