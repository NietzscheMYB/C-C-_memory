#include "SList.h"

//�����ӡ����
void PrintSListFrom2Tail(SList *list)
{
	//assert(list != NULL);
	SListNode *cur = list->first;
	if (cur == NULL)
	{
		//printf("\n");
		return;
	}
	else
	{
		PrintSListFrom2Tail(cur);
		printf("%d ",cur->value);
		if (cur->value == 1)
			printf("\n");
	}
}

void TestPrintSListFrom2Tail()
{
	SList list;
	SListInit(&list);
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(&list);
	PrintSListFrom2Tail(&list);
}

//ɾ������һ����ͷ��β��㣨���ܱ�����
void DeleteNode(SList *list,SListNode *pos)
{
	assert(list != NULL);
	assert(pos->next!=NULL);
	if (list->first == NULL)
	{
		return;
	}
	int temp;
	SListNode *Del=NULL;
	Del = pos->next;
	temp = pos->value;
	pos->value = Del->value;
	Del->value = temp;
	pos->next = Del->next;
	free(Del);
}

void TestDeleteNode()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPushFront(&list, 0);
	SListPrint(&list);
	SListNode *node = SListFind(&list, 2);
	DeleteNode(&list, node);
	SListPrint(&list);
}

//����ͷ�������һ���ڵ�ǰ����һ�����
void InsertPosFront(SListNode *pos, SLDataType value)
{
	assert(pos != NULL);
	SListNode *node1 = SListBuyNode(value);
	SListNode *node2 = NULL;
	node2 = pos->next;
	pos->next = node1;
	node1->next = node2;
	int temp = 0;
	temp = pos->value;
	pos->value = node1->value;
	node1->value = temp;
}

void TestInsertPosFront()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPushFront(&list, 0);
	SListPrint(&list);
	SListNode *node = SListFind(&list, 2);
	InsertPosFront(node, 5);
	SListPrint(&list);
}

//��һ������ʵϰԼɪ��
void CreatCircle(SList *list)//������
{
	assert(list != NULL);
	SListNode *cur=NULL;
	cur = list->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = list->first;
}
void JosephCircle(SList *list,const int M)//�⻷   ��ȡ�滻ɾ��
{
	assert(list != NULL);
	SListNode *cur = NULL;
	SListNode *Del = NULL;
	cur = list->first;
	while (cur != cur->next)
	{
		int count = M;
		while (--count)
		{
			cur = cur->next;
		}
		Del=cur->next;
		cur->value = Del->value;
		cur->next = Del->next;
		free(Del);
	}
	list->first = cur;
	list->first->next = NULL;
}

void TestJosephCircle()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPushFront(&list, 0);
	SListPrint(&list);
	 CreatCircle(&list);//������
	 JosephCircle(&list, 3);
	 SListPrint(&list);
}

//���������ã����ܴ����µĽ�㣩   ���ҲҪ���Ǵ������� ���������û����
//����1 ͷ��
void SListReverse1(SList *list)
{
	assert(list != NULL);
	if (list->first == NULL || list->first->next == NULL)
	{
		return;
	}

	SListNode *ret= NULL;
	while (list->first)
	{
		//ɾ��
		SListNode *node = list->first;
		list->first = node->next;  //

		//����
		node->next = ret;
		ret = node;
	}
	list->first = ret;
	
}
//��ָ��
void SListReverse2(SList *list)
{
	SListNode *pre = NULL;
	SListNode *cur = list->first;
	SListNode *next = cur->next;
	while (cur)
	{
		cur->next = pre;
		pre = cur;
		cur = next;
		if (cur == NULL)
			break;
		next = cur->next;   //���߰�next=cur->next��ǰ�� ʡ��if
	}
	list->first = pre;
}
void TestSListReverse()
{
	SList list;
	SListInit(&list);
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(&list);
	SListReverse2(&list);
	SListPrint(&list);
}

//�ϲ�������������ϲ�����Ȼ���򣨲��ܴ����µĽ�㣩
//SList *MergeSList(SList *list1, SList *list2)
//{
//	assert(list1 != NULL);
//	assert(list2 != NULL);
//	if (list1->first == NULL || list2->first == NULL)
//	{
//		return (list1->first == NULL) ? list2:list1;
//	}
//	SListNode *node = NULL;
//	SListNode *cur1 = list1->first;
//	SListNode *cur2 = list2->first;
//	SListNode *first = NULL;
//	SListNode *first1 = NULL;
//
//	if (cur1->value < cur2->value)
//	{
//		first = cur1;
//		first1=cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		first1=cur2;
//		first = cur2;
//		cur2=cur2->next;
//	}
//	while (cur1&&cur2)
//	{
//		if (cur1->value < cur2->value)
//		{
//			first->next=cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			first->next = cur2;
//			cur2 = cur2->next;
//		}
//		first=first->next;
//	}
//	if (cur1 == NULL)
//	{
//		while (cur2)
//		{
//			first->next = cur2->next;
//		}
//	}
//}