#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SLNode{
	struct SLNode *next;
	SLDataType value;
}SListNode;

typedef struct SList{
	SListNode *first;   //����ͷ
}SList;

//��ʼ��
void SListInit(SList *list);
//����
void SListDistroy(SList *list);
//ͷ��
void SListPushFront(SList *list,SLDataType value);
//ͷɾ
void SListPoPFront(SList *list);
//β��
void SListPushBack(SList *list,SLDataType value);
//βɾ
void SListPopBack(SList *list);

//�����µĽ��
SListNode *SListBuyNode(SLDataType value);

//pos һ���������е�һ����Ч���
//��pos֮���,ɾ
void SListInsertNodeAfter(SList *list, SListNode *pos, SLDataType value);
void SListEraseNodeAfter(SList *list, SListNode *pos, SLDataType value);
//��pos֮ǰ�壬ɾ
void SListInsertNodeBefore(SList *list, SListNode *pos, SLDataType value);
void SListEraseNodeBefor(SList *list, SListNode *pos, SLDataType value);

//����ֵ  �ĵ���ĳ��������ֵ������
void SListUpdate(SListNode *node, SLDataType value);
//�� ȥ�ҵ������������ĵ�һ��value,���û���ҵ�������NULL
SListNode *SListFind(SList *list, SLDataType value);

//��ӡ
void SListPrint(const SList *list);
