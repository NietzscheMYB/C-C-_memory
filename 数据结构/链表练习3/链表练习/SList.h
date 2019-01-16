#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
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


//������
//1.�����ӡ������   �ݹ�д��
void PrintSListFrom2Tail(SList *list);
//2.ɾ������һ����ͷ��β��㣨���ܱ�������);   �滻����ɾ��
void DeleteNode(SList *list,SListNode *pos);
//3.����ͷ�������һ���ڵ�ǰ����һ�����   �Ȳ��ں��� ���滻
void InsertPosFront(SListNode *pos, SLDataType value);
//4.��һ������ʵϰԼɪ��
void CreatCircle(SList *list);//������
//�����Լ�����
void JosephCircle(SList *list,int count);//�⻷
//5.���������ã����ܴ����µĽ�㣩   ���ҲҪ���Ǵ������� ���������û����
void SListReverse1(SList *list);
void SListReverse2(SList *list);
//6.�ϲ�������������ϲ�����Ȼ����(���ܴ����µĽ��)
void MergeSList(SList *list1, SList *list2);