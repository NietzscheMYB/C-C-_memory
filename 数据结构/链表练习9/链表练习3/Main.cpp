#include <stdio.h>
#include <malloc.h>
typedef int DataType;
typedef struct Node{
	DataType value;
	struct Node* next;
}Node,*List;

Node *BuyNode(DataType value)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void ListInit(List *l)
{
	*l = NULL;
}

void ListPushBack(List *l, DataType value)
{
	if (*l == NULL)
	{
		Node *node = BuyNode(value);
		*l = node;
		return;
	}
	Node *cur = *l;
	while (cur->next)
	{
		cur = cur->next;
	}
	Node *node = BuyNode(value);
	cur->next = node;
}
void ListPushFront(List *l, DataType value)
{
	if (*l == NULL)
	{
		ListPushBack(l, value);
		return;
	}
	Node *node = BuyNode(value);
	Node *next = *l;
	
	*l = node;
	node->next = next;
}

void PrintList(List *l)
{
	Node *cur = *l;
	if (cur->next == NULL)
	{
		printf("%d\n", cur->value);
		return;
	}
	while (cur->next)
	{
		printf("%d-->", cur->value);
		cur = cur->next;
	}
	printf("%d\n", cur->value);

}
void ReversePrint(List *l)
{
	Node *cur = *l;
	if (cur == NULL)
	{
		return;
	}
	ReversePrint(&cur->next);
	printf("%d ", cur->value);
}
int main()
{
	List l;
	ListInit(&l);
	ListPushBack(&l, 1);
	ListPushBack(&l, 2);
	ListPushBack(&l, 3);
	ListPushBack(&l, 4);
	ListPushBack(&l, 5);
	PrintList(&l);
	ListPushFront(&l, 0);
	PrintList(&l);
	ReversePrint(&l);
	printf("\n");
	return 0;
}