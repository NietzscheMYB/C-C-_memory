#include "SList.h"
void SListPopFront(SList *list);

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


//void SListPushFront(SList *list,SLDataType value)
//{
//	assert(list != NULL);
//	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
//	//SListNode *node=SListBuyNode(value);
//	SListNode *cur = list->first;
//	node->next = cur;
//	cur= node;
//}
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

void SListPopFront(SList *list)
{
	assert(list != NULL);  //保证链表是有道
	assert(list->first != NULL);//保证链表不为空
	SListNode *cur;
	cur = list->first;
	list->first = list->first->next;
	free(cur);
}
//void SListPopFront(SList *list)
//{
//	assert(list != NULL);			// 保证链表是有的
//	assert(list->first != NULL);	// 保证链表不为空
//
//	SListNode *old_first = list->first;
//	list->first = list->first->next;
//	free(old_first);
//}

//void SListPushBack(SList *list, SLDataType value)
//{
//	assert(list != NULL);
//	//链表中没有结点的时候
//	if (list->first == NULL);
//	{
//		SListPushFront(list, value);
//		return;
//	}
//	SListNode *node = SListBuyNode(value);
//	SListNode *cur;
//	cur = list->first;
//	while (cur->next!=NULL)
//	{
//		cur = cur->next;
//	}
//	cur->next = node;
//	node->next = NULL;
//}
// 尾插
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL) {
		SListPushFront(list, value);
		return;
	}

	// 链表中有结点的情况
	// 找链表中的最后一个结点
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur 就是最后一个结点
	SListNode *node = SListBuyNode(value);
	cur->next = node;
}


void SListPopBack(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空
	 //如果只有一个结点
	if (list->first->next == NULL) {
		SListPopFront(list);
		return;
	}

	SListNode *cur = list->first;
	while (cur->next->next != NULL) {
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
	SListNode *cur=list->first;
	while (cur)
	{
		printf("%d-->", cur->value);
		cur = cur->next;
	}
	printf("NULL\n");
}
SListNode *SListTail(SList *list)
{
	assert(NULL != list);
	if (list->first != NULL)
	{
		return;
	}
	SListNode *cur = list->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}
int DifferenceLen(SList *list1, SList *list2)
{
	assert(list1 != NULL);
	assert(list2 != NULL);
	if (list1->first == NULL || list2->first==NULL)
	{
		return;
	}
	SListNode *cur1 = list1->first;
	SListNode *cur2 = list2->first;
	int count1 = 1,count2=1,count3=1;
	while (cur1->next != NULL)
	{
		count1++;
		cur1 = cur1->next;
	}
	while (cur2->next != NULL)
	{
		count2++;
		cur2 = cur2->next;
	}
	if (count1 < count2)
	{
		count3 = count2 - count1;
	}
	else
	{
		count3 = count1 - count2;
	}
	return count3;
}

void  TestSList()
{
	SList list;
	SListInit(&list);

	SListPushBack(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	

	SListPrint(&list);

	SListPopBack(&list);
	SListPrint(&list);

	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPrint(&list);
	SListPopFront(&list);
	SListPrint(&list);

}