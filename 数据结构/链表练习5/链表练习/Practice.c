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
void MergeSList(SList *list1, SList *list2)
{
	//SListNode *ksd;
	assert(list1 != NULL);
	assert(list2 != NULL);
	if (list1->first == NULL || list2->first == NULL)
	{
		return (list1->first == NULL) ? list2:list1;
	}
	SListNode *node = NULL;
	//list1->first = node->next;
	SListNode *cur1 = list1->first;
	SListNode *cur2 = list2->first;
	SListNode *first = NULL;
	//SListNode *first1 = NULL;
	
	if (cur1->value < cur2->value)
	{
		node = list1->first; 
		first = node;
		list1->first = node->next;
		 cur1 = list1->first;
		 cur2 = list2->first;
		
	}
	else
	{
		node = list2->first;
		first = node;
		list2->first = node->next;
		cur1 = list1->first;
		cur2 = list2->first;
		
	}
	while (cur1&&cur2)
	{
		if (cur1->value < cur2->value)
		{
			node->next=cur1;
			node = cur1;
			cur1 = cur1->next;
		}
		else
		{
			node->next = cur2;
			node = cur2;
			cur2 = cur2->next;
		}
		
	}
	if (cur1 == NULL)
	{
		node->next = cur2->next;
	}
	if (cur2 == NULL)
	{
		node->next = cur1->next;
	}
	list1 = first;
	//return list1;
	SListPrint(&list1);
}

void TestMergeSList()
{
	SList list1;
	SList list2;
	SList list3;
	SListInit(&list1);
	SListInit(&list2);
	SListInit(&list3);
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 2);
	SListPushBack(&list1, 2);
	SListPushBack(&list1, 4);
	SListPrint(&list1);
	SListPushBack(&list2, 1);
	SListPushBack(&list2, 3);
	SListPushBack(&list2, 4);
	SListPushBack(&list2, 5);
	SListPushBack(&list2, 6);
	SListPrint(&list2);
	//list1=MergeSList(&list1, &list2);
	MergeSList(&list1, &list2);

}

//7.Ҫ������м��㣬ֻ�ܱ���һ��
void FindMiddleNode(SList *list)
{
 //   //���Ϊ������slow���м�λ�� ���Ϊż���� slow���м�ƫ��λ��
	assert(list != NULL);
	if (NULL == list->first)
	{
		return;
	}
	SListNode*cur1=list->first;
	SListNode*cur2 = list->first;
	while (cur1&&cur1->next)    //fast ��Ϊ����fast->next Ҳ����Ϊ��
	{
		cur1=cur1->next->next;
		cur2=cur2->next;
	}

	printf("%d\n", cur2->value);
}
void TestFindMiddleNode()
{
	SList list1,list2;
	SListInit(&list1);
	SListInit(&list2);
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 2);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 4);
	SListPushBack(&list1, 5);
	SListPrint(&list1);
	FindMiddleNode(&list1);
	SListPushBack(&list2, 1);
	SListPushBack(&list2, 2);
	SListPushBack(&list2, 3);
	SListPushBack(&list2, 4);
	SListPrint(&list2);
	FindMiddleNode(&list2);
}

//���ҵ���������K�����

//������ָ�����k�� ��һ��ָ�뵽��NULL �ڶ���ָ����ָΪ������;
void FindLastKNode(SList *list, int k)
{
	int num = k;
	assert(list != NULL);
	if (list == NULL)
	{
		return;
	}
	SListNode *cur1 = NULL;
	SListNode *cur2 = NULL;
	SListNode *cur3 = NULL;
	cur3 = list->first;
	int count = 0;
	while (cur3)
	{
		count++;
		cur3 = cur3->next;
	}
	if (k > count)
	{
		printf("Kֵ����\n");
		return;
	}
	cur1 = list->first;
	cur2 = list->first;
	while (k--)
	{
		cur2 = cur2->next;
	}
	while (cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	printf("������%d�Ľڵ��ֵΪ%d\n", num, cur1->value);
}
void TestFindLastKNode()
{
	int k = 0;
//	scanf("%d", &k);
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPushFront(&list, 6);
	SListPrint(&list);
	scanf("%d", &k);
	FindLastKNode(&list, k);
}

void PopLastKNoed(SList *list, int k)
{
	int num = k;
	assert(list != NULL);
	if (list == NULL)
	{
		return;
	}
	SListNode *cur1 = NULL;
	SListNode *cur2 = NULL;
	SListNode *cur3 = NULL;
	cur3 = list->first;
	int count = 0;
	while (cur3)
	{
		count++;
		cur3 = cur3->next;
	}
	if (k > count)
	{
		printf("Kֵ����\n");
		return;
	}
	cur1 = list->first;
	cur2 = list->first;
	while (k--)
	{
		cur2 = cur2->next;
	}
	while (cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	printf("������%d�Ľڵ��ֵΪ%d\n", num, cur1->value);
	printf("ɾ����\n");
	//SListNode *Del = cur1;
	SListNode *x = list->first;
	while (x->next != cur1)
	{
		x = x->next;
	}
	x->next = cur1->next;
	free(cur1);
	SListPrint(list);
}

void TestPopLastKNoed()
{
	int k = 0;
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPushFront(&list, 6);
	SListPrint(&list);
	scanf("%d", &k);
	//FindLastKNode(&list, k);
	PopLastKNoed(&list, k);
}

int IsCrossWithoutCircle(SList *list1, SList *list2)
{
	assert(NULL != list1);
	assert(NULL != list2);
	if (list1->first == NULL || list2->first == NULL)
	{
		return 0;
	}
	SListNode *cur1 = list1->first;
	SListNode *cur2 = list2->first;
	while (cur1->next!=NULL)
	{
		cur1 = cur1->next;
	}
	while (cur2->next != NULL)
	{
		cur2 = cur2->next;
	}
	if (cur1->value == cur2->value)
		return 1;
	return 0;
}


void SetCross(SList *list1,SList *list2)
{
	assert(NULL != list1);
	assert(NULL != list2);
	if (list1->first == NULL||list2->first==NULL)
	{
		return;
	}
	SListNode *cur = list2->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = SListFind(list1, 3);
}
void FindEnterNode(SList *list1, SList *list2)
{
	assert(list1!= NULL);
	assert(list2!= NULL);
	if (list1->first == NULL || list2->first == NULL)
	{
		return;
	}
	SListNode *cur1 = list1->first;
	SListNode *cur2 = list2->first;
	int count1 = 1, count2 = 1, count3 = 1;
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
	cur1 = list1->first;
	cur2 = list2->first;
	if (count1 < count2)
	{
		count3 = count2 - count1;
		while (count3--)
		{
			cur2 = cur2->next;
		}
	}
	else
	{
		count3 = count1 - count2;
		while (count3--)
		{
			cur1 = cur1->next;
		}
	}
	
	while (cur2->next != cur1->next)
	{
		cur2 = cur2->next;
		cur1 = cur1->next;
	}
	printf("����Ϊ%d\n", cur2->value);




}

void TestIsCrossWithoutCircleAndEnterNode()
{
	SList list1, list2;
	int flag = 0;
	SListInit(&list1);
	SListInit(&list2);
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 2);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 4);
	SListPushBack(&list1, 5);
	SListPushBack(&list2, 1);
	SListPushBack(&list2, 2);
	SListPushBack(&list2, 3);
	SetCross(&list1, &list2);
	flag = IsCrossWithoutCircle(&list1, &list2);
	if (flag == 1)
	{
		printf("�����н���\n");
	}
	FindEnterNode(&list1, &list2);
	

}