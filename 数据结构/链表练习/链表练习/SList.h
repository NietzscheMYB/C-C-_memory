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
	SListNode *first;   //链表头
}SList;

//初始化
void SListInit(SList *list);
//销毁
void SListDistroy(SList *list);
//头插
void SListPushFront(SList *list,SLDataType value);
//头删
void SListPoPFront(SList *list);
//尾插
void SListPushBack(SList *list,SLDataType value);
//尾删
void SListPopBack(SList *list);

//申请新的结点
SListNode *SListBuyNode(SLDataType value);

//pos 一定是链表中的一个有效结点
//在pos之后插,删
void SListInsertNodeAfter(SList *list, SListNode *pos, SLDataType value);
void SListEraseNodeAfter(SList *list, SListNode *pos, SLDataType value);
//在pos之前插，删
void SListInsertNodeBefore(SList *list, SListNode *pos, SLDataType value);
void SListEraseNodeBefor(SList *list, SListNode *pos, SLDataType value);

//改数值  改的是某个结点的数值！！！
void SListUpdate(SListNode *node, SLDataType value);
//查 去找到链表中遇到的第一个value,如果没有找到，返回NULL
SListNode *SListFind(SList *list, SLDataType value);

//打印
void SListPrint(const SList *list);
