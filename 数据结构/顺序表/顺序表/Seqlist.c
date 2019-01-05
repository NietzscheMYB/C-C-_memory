#include "SeqList.h"
#include <assert.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
//初始化顺序表  seqlist->array 堆上开辟空间 size=0； capacity=capacity
void  SeqListInit(SeqList *seqlist, int capacity)
{
	assert(seqlist!=NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}

//销毁顺序表  ，free掉释放空间  使size=0.， capacity=0
void SeqListDestroy(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	free(seqlist->array);     //重点
	seqlist->array = NULL;
	seqlist->capacity = 0;
	seqlist->size = 0;

}


//尾插
void SeqListPushBack(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	seqlist->array[seqlist->size] = value;  //seqlist->array[seqlist0->size]=value;
	seqlist->size++;
}
//头插
void SeqListPushFront(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	//做数据搬移，i代表空间下表
	for (int i = seqlist->size; i > 0; i--)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}

//中间插入
void SeqListInsert(SeqList *seqlist, int pos, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0&&pos <= seqlist->size);
	for (int i = seqlist->size - 1; i >= pos; i--)
	{
		seqlist->array[i + 1] = seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}





//尾删 删除直接删除 不能free 如果free 就直接把部分空间释放掉！！！
void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array!=NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}
//头删除
void SeqListPopFront(SeqList *seqlist)
{
	assert(seqlist!=NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	for (int i = 1; i < seqlist->size; i--)
	{
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}

void SeqListErase(SeqList *seqlist, int pos)
{
	assert(seqlist != NULL);
	assert(seqlist->array = NULL);
	for (int i = pos; i <seqlist->size-1; i++)
	{
		seqlist->array[i] = seqlist->array[i + 1];
	}
	seqlist->size--;
}


//所有插入都要加搬移
void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	if (seqlist->size < seqlist->capacity)
		return;
	//走到这里肯定要扩容
	int capacity = 2 * (seqlist->capacity);
	SDataType *array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	//老数据搬移！！！
	for (int i = 0; i < seqlist->size; i++)
	{
		array[i] = seqlist->array[i];
	}
	free(seqlist->array);
	seqlist->array = array;
}

void SeqListPrint(const SeqList*seqlist)
{
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d ", seqlist->array[i]);
	}
	printf("\n");
}

void SeqListModify(SeqList *seqlist, int pos, SDataType value){
	assert(seqlist != NULL);
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = value;
}

int SeqListFind(const SeqList *seqlist, int value)
{
	for (int i = 0; i < seqlist->size; i++)
	{
		if (seqlist->array[i] == value);
		return i;
	}
	return -1;

}