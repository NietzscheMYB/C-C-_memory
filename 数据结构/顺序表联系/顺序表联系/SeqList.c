#include "SeqList.h"

void SeqListInit(SeqList *seqlist, int capacity)
{
	assert(seqlist != NULL);
	seqlist->array = (SDataType*)malloc(capacity*sizeof(SDataType));  //因为arry是SDataType型所以malloc的类型也是这个
	seqlist->capacity = capacity;
	seqlist->size = 0;
}

void SeqListDestroy(SeqList *seqlist)
{
	assert(seqlist != NULL);
	free(seqlist->array);
	seqlist->capacity = 0;
	seqlist->size = 0;
	
}


void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size != 0);
	seqlist->size--;
}

void SeqListPushBack(SeqList *seqlist,SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size >= 0);
	CheckCapacity(seqlist);

	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}

void SeqListPushFront(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);
	for (int i = seqlist->size-1; i>=0; i--)
	{
		seqlist->array[i + 1] = seqlist->array[i];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}

void SeqListPopFront(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);

	for (int i = 1; i < seqlist->size; i++)
	{
		seqlist->array[i - 1] = seqlist->array[i];
	}
	seqlist->size--;
}

void SeqListInsert(SeqList *seqlist, int pos, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array!=NULL);
	assert(pos >= 0&&pos<=seqlist->size);
	CheckCapacity(seqlist);
	for (int i = seqlist->size - 1; i >= pos; i--)
	{
		seqlist->array[i + 1]=seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}


void SeqListErase(SeqList *seqlist, int pos)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos > 0 && pos < seqlist->size);
	for (int i =pos+1; i<seqlist->size; i++)
	{
		seqlist->array[i-1] = seqlist->array[i];
	}
	seqlist->size--;

}

void SeqListPrint(const SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size >= 0);
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d ", seqlist->array[i]);
	}
	printf("\n");
}

void SeqListChange(SeqList *seqlist,int pos,SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos < seqlist->size);
	seqlist->array[pos] = value;
}

int SeqListFind(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (seqlist->array[i] == value)
			return i;
	}
	return -1;
}

void SeqListRemove(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (seqlist->array[i] == value)
		{
			SeqListErase(seqlist, i);
			break;
		}
	}
}

bool SeqListEmpty(SeqList *seqlist)
{
	return seqlist->size == 0;
}

int SeqListSize(SeqList *seqlist)
{
	return seqlist->size;
}

void SeqListBubbleSort(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	int i = 0, j = 0;
	int temp;
//	int Issort = 0;   //优化冒泡
	for (i=0; i < seqlist->size-1; i++)
	{
		//Issort = 1;
		for (j=0; j <seqlist->size - i - 1; j++)
		{
			if (seqlist->array[j]>seqlist->array[j + 1])
			{
				temp = seqlist->array[j];
				seqlist->array[j] = seqlist->array[j + 1];
				seqlist->array[j + 1] = temp;
				//Issort = 0;
			}
			
		}
		/*if (Issort==1)
		{
			break;
		}*/
	}
}


int SeqListBinarySearch(SeqList *seqlist,SDataType value)
{
	int left =0,right =seqlist->size - 1;
	//int mid = (left + right) / 2;
	while (left <= right)
	{
		int mid = (right - left) / 2 + left;
		if (value == seqlist->array[mid])
			return mid;
		else if (value < seqlist->array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

static  void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	SDataType *Newarray;
	if (seqlist->size < seqlist->capacity)
		return;//不用扩容
	else  //扩容
	{
		Newarray= (SDataType*)malloc((2*seqlist->capacity)*sizeof(SDataType));
		for (int i = 0; i < seqlist->size; i++)
		{
			Newarray[i] = seqlist->array[i];
		}
		free(seqlist->array);
		seqlist->array = Newarray;
		seqlist->capacity = 2 * seqlist->capacity;
	}

}