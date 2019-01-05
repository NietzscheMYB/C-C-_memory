#pragma once

//typedef struct SeqList{
//	int array[100];  //能存100个数的静态顺序表
//	int size; //表示当前顺序表里有多少个数
//	          //顺便也表示了即将插入的下标
//			
//}SeqList;
typedef int SDataType;

typedef struct SeqList{
	SDataType *array;  //指向堆上空间  堆上开辟空间     //理解成数组
 	int size; //表示当前顺序表里有多少个数
	//顺便也表示了即将插入的下标

	int capacity;  //容量
}SeqList;

//初始化
//seqlist 是一个变量的地址
//capacity是初始容量 
void SeqListInit(SeqList *seqlist, int capacity);

//销毁
void SeqListDestroy(SeqList *seqlist);

//增加插入
//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value);
//头插
void SeqListPushFront(SeqList *seqlist, SDataType value);
//中间插入，往pos所在的下标插入 value
void SeqListInsert(SeqList *seqlist,int pos,SDataType value);




//删除
//尾删
void SeqListPopBack(SeqList *seqlist);
//头删
void SeqListPopFront(SeqList *seqlist);

//删除pos所在下标数据
void SeqListErase(SeqList *seqlist, int pos);
//改
//查找


//检查是否需要扩容，如果需要扩容就进行扩容
//保证函数结束后，容量一定够用

static void CheckCapacity(SeqList *seqlist);


//打印

void SeqListPrint(const SeqList*seqlist);

//修改pos所在的下标的数据为value
void SeqListModify(SeqList *seqlist, int pos, SDataType value);

//查找  找到返回第一个下标 没找到返回-1
int SeqListFind(const SeqList *seqlist, int value);