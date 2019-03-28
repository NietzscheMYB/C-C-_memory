#include <stdio.h>
#include <malloc.h>
typedef int DataType;
typedef struct Node{
	DataType value;
	struct Node* next;
}Node,*List;

Node *ButNode(DataType value)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void ListInit(List* l)
{
	*l = NULL;
}
void ListPushBack(List*l, DataType value)
{
	if (*l == NULL)
	{
		Node *node = ButNode(value);
		*l = node;
	}

}
//list 类型是一个指针类型，我们要存第一个给节点的地址就存在l里
//在各项操作中必须对l的地址操作，所以避免形参，我们对l操作 
//用函数实现就是传地址！！！
int main()
{
	List l;
	ListInit(&l);
	ListPushBack(&l, 1);
	return 0;
}