#pragma once  
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
typedef int SDataType;    //Ҫ�ֺ�  ���Ըı�˳��������


typedef struct SeqList
{
	SDataType *array;   //ָ�϶��Ͽռ�    ���һ����������
	int size;     //��ǰ˳����ж��ٸ���
	int capacity;  //˳��������
}SeqList;

//���붼Ҫ�� SDataType  value;

//��ʼ��
void SeqListInit(SeqList *seqlist, int capacity);

//����
void SeqListDestroy(SeqList *seqlist);

//βɾ
void SeqListPopBack(SeqList *seqlist);
//β��
void SeqListPushBack(SeqList *seqlist,SDataType value);
//ͷ��
void SeqListPushFront(SeqList *seqlist,SDataType value);
//ͷɾ
void SeqListPopFront(SeqList *seqlist);

//���м����  ��pos���ڵ��±����
void SeqListInsert(SeqList *seqlist, int pos, SDataType value);


//ɾ��pos���ڵ��±�
void SeqListErase(SeqList *seqlist, int pos);

//��ӡ
void SeqListPrint(const SeqList *seqlist);

//�޸�pos���ڵ��±������Ϊvalude
void SeqListChange(SeqList *seqlist,int pos,SDataType value);

//����  ����ҵ����ص�һ���ҵ����±�
//���û�ҵ� ����-1

int SeqListFind(SeqList *seqlist, SDataType value);

//�ҵ���ɾ����һ��value

void SeqListRemove(SeqList *seqlist, SDataType value);


//�ж�˳����Ƿ�Ϊ��
bool SeqListEmpty(SeqList *seqlist);

//�������ݸ���
int SeqListSize(SeqList *seqlist);

//ð������
void SeqListBubbleSort(SeqList *seqlist);


//���ֲ���
int SeqListBinarySearch(SeqList *seqlist);

//ɾ�����е�value

void SeqListRemoveAll(SeqList *seqlist,SDataType value);

//����Ƿ���Ҫ���ݣ����Ҫ������
static  void CheckCapacity(SeqList *seqlist);




