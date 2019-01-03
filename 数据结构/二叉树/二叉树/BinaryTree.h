#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}Node ;

void preorder(Node *root)  //ǰ��
{
	//5�����
	//if (root == NULL)
	//	return;
	//if (root->left==NULL&&root->right==NULL)
	//{
	//	printf("%d ", root->val);
	//	return;
	//}
	//if (root->right == NULL)
	//{
	//	printf("%d ", root->val);
	//	preorder(root->left);
	//	return;
	//}
	//if (root->left == NULL)
	//{
	//	printf("%d ", root->val);
	//	preorder(root->right);
	//	return;
	//}

	//printf("%d ", root->val);
	//preorder(root->left);
	//preorder(root->right);

	//�ݹ��
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);  //��
	preorder(root->left);   //������
	preorder(root->right);  //������
	//printf("\n");
}

void inorder(Node *root)  //������
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);   //������
	printf("%d ", root->val);  //��
	inorder(root->right);  //������

}

void postorder(Node *root)  //������
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);   //������
	postorder(root->right);  //������
	printf("%d ", root->val);  //��
}

Node *buyNode(int val){
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

void Test()
{
	Node *a = buyNode(1);
	Node *b = buyNode(2);
	Node *c = buyNode(3);
	Node *d = buyNode(4);
	Node *e = buyNode(5);
	Node *f = buyNode(6);
	Node *g = buyNode(7);

	a->left = b;
	a->right = c;
	c->left = d;
	c->right = f;
	d->right = e;
	f->right = g;

	preorder(a);
	printf("\n");
	inorder(a);
	printf("\n");
	postorder(a);
}