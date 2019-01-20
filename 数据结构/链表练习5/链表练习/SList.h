#pragma once
#pragma warning(disable:4996)
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
//找到最后一个结点
SListNode *SListTail(SList *list);
//判断两个链表长度
int DifferenceLen(SList *list1, SList *list2);






//面试题
//1.逆序打印单链表   递归写法
void PrintSListFrom2Tail(SList *list);
//2.删除链表一个无头非尾结点（不能变量链表);   替换发法删除
void DeleteNode(SList *list,SListNode *pos);
//3.在无头单链表的一个节点前插入一个结点   先插在后面 再替换
void InsertPosFront(SListNode *pos, SLDataType value);
//4.给一个链表实习约瑟夫环
void CreatCircle(SList *list);//生产环
//步数自己设置
void JosephCircle(SList *list,int count);//解环
//5.单链表逆置（不能创造新的结点）   这个也要考虑带环问题 但这个程序没体现
void SListReverse1(SList *list);
void SListReverse2(SList *list);
//6.合并两个有序链表合并后依然有序(不能创立新的结点)
void MergeSList(SList *list1, SList *list2);
//7.要求查找中间结点，只能遍历一次
void FindMiddleNode(SList *list);
//8.查找单链表倒数第K个结点（只能遍历一次）
void FindLastKNode(SList *list, int k);
//9.删除倒数第K个结点
void PopLastKNoed(SList *list, int k);
//10.判断两个链表是否相交，若相交求交点。
int IsCrossWithoutCircle(SList *list1, SList *list2);
void SetCross(SList *list1, SList *list2); //建环
void FindEnterNode(SList *list1, SList *list2);