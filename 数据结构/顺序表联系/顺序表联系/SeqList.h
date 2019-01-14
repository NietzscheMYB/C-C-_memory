#pragma once  
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
typedef int SDataType;    //要分号  可以改变顺序表的类型


typedef struct SeqList
{
	SDataType *array;   //指上堆上空间    理解一个线性数组
	int size;     //当前顺序表有多少个数
	int capacity;  //顺序表的容量
}SeqList;

//插入都要有 SDataType  value;

//初始化
void SeqListInit(SeqList *seqlist, int capacity);

//销毁
void SeqListDestroy(SeqList *seqlist);

//尾删
void SeqListPopBack(SeqList *seqlist);
//尾插
void SeqListPushBack(SeqList *seqlist,SDataType value);
//头插
void SeqListPushFront(SeqList *seqlist,SDataType value);
//头删
void SeqListPopFront(SeqList *seqlist);

//从中间插入  往pos所在的下标插入
void SeqListInsert(SeqList *seqlist, int pos, SDataType value);


//删除pos所在的下标
void SeqListErase(SeqList *seqlist, int pos);

//打印
void SeqListPrint(const SeqList *seqlist);

//修改pos所在的下标的数据为valude
void SeqListChange(SeqList *seqlist,int pos,SDataType value);

//查找  如果找到返回第一个找到的下标
//如果没找到 返回-1

int SeqListFind(SeqList *seqlist, SDataType value);

//找到并删除第一个value

void SeqListRemove(SeqList *seqlist, SDataType value);


//判断顺序表是否为空
bool SeqListEmpty(SeqList *seqlist);

//返回数据个数
int SeqListSize(SeqList *seqlist);

//冒泡排序
void SeqListBubbleSort(SeqList *seqlist);


//二分查找
int SeqListBinarySearch(SeqList *seqlist);

//删除所有的value

void SeqListRemoveAll(SeqList *seqlist,SDataType value);

//检查是否需要扩容，如果要则扩容
static  void CheckCapacity(SeqList *seqlist);




