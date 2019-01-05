#include "SeqList.h"
#include <assert.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
//��ʼ��˳���  seqlist->array ���Ͽ��ٿռ� size=0�� capacity=capacity
void  SeqListInit(SeqList *seqlist, int capacity)
{
	assert(seqlist!=NULL);
	seqlist->array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}

//����˳���  ��free���ͷſռ�  ʹsize=0.�� capacity=0
void SeqListDestroy(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	free(seqlist->array);     //�ص�
	seqlist->array = NULL;
	seqlist->capacity = 0;
	seqlist->size = 0;

}


//β��
void SeqListPushBack(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	seqlist->array[seqlist->size] = value;  //seqlist->array[seqlist0->size]=value;
	seqlist->size++;
}
//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	//�����ݰ��ƣ�i����ռ��±�
	for (int i = seqlist->size; i > 0; i--)
	{
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}

//�м����
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





//βɾ ɾ��ֱ��ɾ�� ����free ���free ��ֱ�ӰѲ��ֿռ��ͷŵ�������
void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array!=NULL);
	assert(seqlist->size > 0);
	seqlist->size--;
}
//ͷɾ��
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


//���в��붼Ҫ�Ӱ���
void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	if (seqlist->size < seqlist->capacity)
		return;
	//�ߵ�����϶�Ҫ����
	int capacity = 2 * (seqlist->capacity);
	SDataType *array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	//�����ݰ��ƣ�����
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