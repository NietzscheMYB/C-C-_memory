#include "SList.h"

void SListInit(SList *list)
{
	assert(list != NULL);
	list->first = NULL;
}

void SListDistroy(SList *list)
{
	assert(list != NULL);
	SListNode *cur=list->first;
	SListNode *next;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	list->first = NULL;
}


SListNode *SListBuyNode(SLDataType value)
{
	//申请新的节点还是在堆上开辟空间！

	SListNode *NewNode=(SListNode*)malloc(sizeof(SListNode));
	assert(NewNode);
	NewNode->next = NULL;
	NewNode->value = value;
	return NewNode;
}


void SListPushFront(SList *list,SLDataType value)
{
	assert(list != NULL);
	SListNode *node=SListBuyNode(value);
	SListNode *cur = list->first;
	node->next = cur;
	cur= node;
}

void SListPoPFront(SList *list)
{
	assert(list != NULL);  //保证链表是有道
	assert(list->first != NULL);//保证链表不为空
	SListNode *cur;
	cur = list->first;
	list->first = list->first->next;
	free(cur);
}


void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	//链表中没有结点的时候
	if (list->first == NULL);
	{
		SListPushFront(list, value);
	}
	SListNode *node = SListBuyNode(value);
	SListNode *cur;
	cur = list->first;
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
	node->next = NULL;
}

void SListPopBack(SList *list)
{
	assert(list != NULL);
	if (list->first->next = NULL)
	{
		SListPoPFront(list);
	}
	SListNode *cur=list->first;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListInsertNodeAfter(SList *list, SListNode *pos, SLDataType value)
{
	assert(list != NULL);
	assert(pos != NULL);
	SListNode *node=SListBuyNode(value);
	node->next = pos->next;
	pos->next = node;

}

void SListEraseNodeAfter(SList *list, SListNode *pos, SLDataType value)
{
	assert(list != NULL);
	assert(pos != NULL);
	SListNode *cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}

void SListInsertNodeBefore(SList *list, SListNode *pos, SLDataType value)
{
	assert(list != NULL);
	assert(pos != NULL);
	SListNode *node = SListBuyNode(value);
	SListNode *cur = list->first;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = node;
	node->next = pos;
}
void SListUpdate(SListNode *node, SLDataType value)
{
	node->value = value;
}
SListNode *SListFind(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *cur;
	cur = list->first;
	while (cur->next != NULL)
	{
		if (cur->value == value)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListPrint(const SList *list)
{
	assert(list != NULL);
	SListNode *cur;
	while (cur->next != NULL)
	{
		printf("%d-->", cur->value);
		cur = cur->next;
	}
	printf("NULL\n");
}