#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <Windows.h>

typedef int SLDataType;


typedef struct SLNode {
	SLDataType	value;
	struct SLNode *next;
}	SListNode;

typedef struct SList {
	SListNode *first;		// SLNode *head;
}	SList;

// 初始化链表
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;

}
SList list;

// 销毁链表
void SListDestroy(SList *list) {
	assert(list != NULL);

	SListNode *cur = list->first;
	SListNode *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}

	list->first = NULL;
}

// 申请新结点
SListNode * SListBuyNode(SLDataType value)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}


// 链表头插
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

// 链表尾插
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

// 删
// 头删
void SListPopFront(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}
//尾删
void SListPopBack(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空
	// 如果只有一个结点
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

// pos 一定是链表中的一个有效结点
void SListInsertAfter(SListNode *pos, SLDataType value) {
	// 给 value 申请结点
	SListNode *node = SListBuyNode(value);

	node->next = pos->next;
	pos->next = node;
}

void SListEraseAfter(SListNode *pos) {
	SListNode *next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListInsertBefore(SList *list, SListNode *pos, SLDataType value)
{
	SListNode *cur = list->first;
	while (cur->next != pos) {
		cur = cur->next;
	}

	// cur 指向 pos 的前一个结点

	SListNode *node = SListBuyNode(value);

	cur->next = node;
	node->next = pos;
}

// 改
void SListUpdate(SListNode *node, SLDataType value) {
	node->value = value;
}

// 查
// 去找到链表中遇到的第一个 value，如果没找到，返回 NULL
SListNode * SListFind(const SList *list, SLDataType value) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->value == value) {
			return cur;
		}
	}

	return NULL;
}

// 打印
void SListPrint(const SList *list) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->value);
	}
	printf("NULL\n");
}


void Menu()
{
	printf("\n\n\n\n\n\n");
	printf("                                 ******************************************************\n");
	printf("                                 ******************************************************\n");
	printf("                                 *********************单链表操作***********************\n");
	printf("                                 **********************1.开始**************************\n");
	printf("                                 **********************0.退出**************************\n");
	printf("                                 ******************************************************\n");
	printf("                                 ******************************************************\n");

}

void StartMenu()
{
	printf("\n\n\n\n\n\n");
	printf("                                                 1.单链表创建    2.退出\n   ");
}

void FunctionMenu()
{
	printf("\n\n\n\n\n\n");
	printf("                                                 1.链表头插      2.链表尾插\n");
	printf("                                                 3.链表头删      4.链表尾删\n");
	printf("                                                 5.链表查找      6.链表节点个数\n");
}
// 链表头插
void XSListPushFront(SList *list)
{
	SLDataType value;
	scanf("%d", &value);
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node; 
	SListPrint(list);
}
void XSListPushBack(SList *list)
{
	SLDataType value;
	scanf("%d", &value);
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
	SListPrint(list);
}
void XSListPopFront(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
	SListPrint(list);
}
//尾删
void XSListPopBack(SList *list)
{
	assert(list != NULL);			// 保证链表是有的
	assert(list->first != NULL);	// 保证链表不为空
	// 如果只有一个结点
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
	SListPrint(list);
}

void XSListFind(SList *list)
{
	SListPrint(list);
	int value;
	scanf("%d", &value);
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->value == value) {
			printf("找到了！\n");
			return;
		}
	}
	printf("没找了！\n");
	return;
}

void XSListLength(SList *list)
{
	SListPrint(list);
	int count = 0;
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) 
	{
		count++;
		}
	printf("%d\n", count);
}


void Function()
{
	
	//SListInit(&list);
	int key1 = 0;
	scanf("%d", &key1);
	switch (key1)
	{
	case 1:system("cls"); XSListPushFront(&list); FunctionMenu(); Function();
		break;
	case 2:system("cls"); XSListPushBack(&list); FunctionMenu(); Function();
		break;
	case 3:system("cls"); XSListPopFront(&list); FunctionMenu(); Function();
		break;
	case 4:system("cls"); XSListPopBack(&list); FunctionMenu(); Function();
		break;
	case 5:system("cls"); XSListFind(&list); FunctionMenu(); Function();
		break;
	case 6:system("cls"); XSListLength(&list); FunctionMenu(); Function();
		break;
	}
}
void Start()
{
	StartMenu();
	int key1 = 0;
	scanf("%d", &key1);
	switch (key1)
	{
	case 1:system("cls");  printf("\n\n单链表创建成功！\n"); FunctionMenu(); SListInit(&list); Function();
		break;
	case 2:return;
		break;
	}
}

void ListGame()
{
	Menu();
	int key1 = 0;
	scanf("%d", &key1);
	switch (key1)
	{
	case 1:system("cls"); Start();
		break;
	case 0:return ;
		break;
	}
}


void Test()
{
	Start();
}





void TestSList1() {
	SList list;
	SListInit(&list);
	
		printf("链表定义初始化成功！\n");
	
	
	assert(list.first == NULL);
	printf("开始尾插\n");
	SListPushBack(&list, 11);
	SListPrint(&list);
	SListPushBack(&list, 12);
	SListPrint(&list);
	SListPushBack(&list, 13);
	SListPrint(&list);
	
	// 11 12 13
	
	printf("\n开始头插\n");
	SListPushFront(&list, 1);
	SListPrint(&list);
	SListPushFront(&list, 2);
	SListPrint(&list);
	SListPushFront(&list, 3);
	SListPrint(&list);

	printf("\n在12后处插入\n");
	SListNode *n12 = SListFind(&list, 12);
	assert(n12 != NULL);
	SListInsertAfter(n12, 103);

	SListPrint(&list);
	// 11 12 103 13

	

	SListPrint(&list);
	// 11 12 13

	printf("\n在12前插入\n");
	SListInsertBefore(&list, n12, 101);

	SListPrint(&list);
	// 11 101 12 13

	printf("\n尾删\n");
	SListPopBack(&list);
	SListPrint(&list);
	//system("cls");
	
	printf("\n头删\n");
	SListPopFront(&list);
	SListPrint(&list);
}

int main()
{
	ListGame();
	return 0;
}