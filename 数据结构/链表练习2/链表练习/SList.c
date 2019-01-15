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
	//�����µĽڵ㻹���ڶ��Ͽ��ٿռ䣡


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
	assert(list != NULL);  //��֤�������е�
	assert(list->first != NULL);//��֤����Ϊ��
	SListNode *cur;
	cur = list->first;
	list->first = list->first->next;
	free(cur);
}
//void SListPopFront(SList *list)
//{
//	assert(list != NULL);			// ��֤�������е�
//	assert(list->first != NULL);	// ��֤����Ϊ��
//
//	SListNode *old_first = list->first;
//	list->first = list->first->next;
//	free(old_first);
//}

//void SListPushBack(SList *list, SLDataType value)
//{
//	assert(list != NULL);
//	//������û�н���ʱ��
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
// β��
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL) {
		SListPushFront(list, value);
		return;
	}

	// �������н������
	// �������е����һ�����
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur �������һ�����
	SListNode *node = SListBuyNode(value);
	cur->next = node;
}

//void SListPopBack(SList *list)
//{
//	assert(list != NULL);
//	if (list->first->next = NULL)
//	{
//		SListPopFront(list);
//		return;
//	}
//	SListNode *cur=list->first;
//	while (cur->next->next != NULL)
//	{
//		cur = cur->next;
//	}
//	free(cur->next);
//	cur->next = NULL;
//}
void SListPopBack(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��
	 //���ֻ��һ�����
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