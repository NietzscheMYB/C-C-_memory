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

// ��ʼ������
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;

}
SList list;

// ��������
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

// �����½��
SListNode * SListBuyNode(SLDataType value)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}


// ����ͷ��
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

// ����β��
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

// ɾ
// ͷɾ
void SListPopFront(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}
//βɾ
void SListPopBack(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��
	// ���ֻ��һ�����
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

// pos һ���������е�һ����Ч���
void SListInsertAfter(SListNode *pos, SLDataType value) {
	// �� value ������
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

	// cur ָ�� pos ��ǰһ�����

	SListNode *node = SListBuyNode(value);

	cur->next = node;
	node->next = pos;
}

// ��
void SListUpdate(SListNode *node, SLDataType value) {
	node->value = value;
}

// ��
// ȥ�ҵ������������ĵ�һ�� value�����û�ҵ������� NULL
SListNode * SListFind(const SList *list, SLDataType value) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->value == value) {
			return cur;
		}
	}

	return NULL;
}

// ��ӡ
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
	printf("                                 *********************���������***********************\n");
	printf("                                 **********************1.��ʼ**************************\n");
	printf("                                 **********************0.�˳�**************************\n");
	printf("                                 ******************************************************\n");
	printf("                                 ******************************************************\n");

}

void StartMenu()
{
	printf("\n\n\n\n\n\n");
	printf("                                                 1.��������    2.�˳�\n   ");
}

void FunctionMenu()
{
	printf("\n\n\n\n\n\n");
	printf("                                                 1.����ͷ��      2.����β��\n");
	printf("                                                 3.����ͷɾ      4.����βɾ\n");
	printf("                                                 5.�������      6.����ڵ����\n");
}
// ����ͷ��
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

	// �������н������
	// �������е����һ�����
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur �������һ�����
	SListNode *node = SListBuyNode(value);
	cur->next = node;
	SListPrint(list);
}
void XSListPopFront(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
	SListPrint(list);
}
//βɾ
void XSListPopBack(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��
	// ���ֻ��һ�����
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
			printf("�ҵ��ˣ�\n");
			return;
		}
	}
	printf("û���ˣ�\n");
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
	case 1:system("cls");  printf("\n\n���������ɹ���\n"); FunctionMenu(); SListInit(&list); Function();
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
	
		printf("�������ʼ���ɹ���\n");
	
	
	assert(list.first == NULL);
	printf("��ʼβ��\n");
	SListPushBack(&list, 11);
	SListPrint(&list);
	SListPushBack(&list, 12);
	SListPrint(&list);
	SListPushBack(&list, 13);
	SListPrint(&list);
	
	// 11 12 13
	
	printf("\n��ʼͷ��\n");
	SListPushFront(&list, 1);
	SListPrint(&list);
	SListPushFront(&list, 2);
	SListPrint(&list);
	SListPushFront(&list, 3);
	SListPrint(&list);

	printf("\n��12�󴦲���\n");
	SListNode *n12 = SListFind(&list, 12);
	assert(n12 != NULL);
	SListInsertAfter(n12, 103);

	SListPrint(&list);
	// 11 12 103 13

	

	SListPrint(&list);
	// 11 12 13

	printf("\n��12ǰ����\n");
	SListInsertBefore(&list, n12, 101);

	SListPrint(&list);
	// 11 101 12 13

	printf("\nβɾ\n");
	SListPopBack(&list);
	SListPrint(&list);
	//system("cls");
	
	printf("\nͷɾ\n");
	SListPopFront(&list);
	SListPrint(&list);
}

int main()
{
	ListGame();
	return 0;
}