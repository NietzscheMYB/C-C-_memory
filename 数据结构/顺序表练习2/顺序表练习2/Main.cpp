#include <stdio.h>
#include <malloc.h>
typedef int DataType;
typedef struct list{
	DataType *arr;
	int capacity;
	int size;
}List;
void InitList(List *l,int capacity)
{
	l->arr = (DataType*)malloc(sizeof(capacity));
	l->size = 0;
	l->capacity = capacity;
}
void ListPushBack(List *l, int value)
{
	l->arr[l->size] = value;
	l->size++;
}
void ListPushFront(List *l, int value)
{
	for (int i = l->size-1; i >= 0; i--)
	{
		l->arr[i + 1] = l->arr[i];
	}
	l->arr[0] = value;
	l->size++;
}
int  ListDelete(List *l, int value)
{	int i = 0;
	int pos = 0;
	for (i = 0; i< l->size - 1; i++)
	{
		if (value == l->arr[i])
		{
			pos = i;
			break;
		}
	}
	if (i == l->size)
	{
		return 0;
	}
	for (i = pos+1; i <l->size; i++)
	{
		l->arr[i - 1] = l->arr[i];
	}
	l->size--;
	return 1;
}
void Print(List *l)
{
	for (int i = 0; i < l->size; i++)
	{
		printf("%d ", l->arr[i]);
	}
	printf("\n");
}
int main()
{
	List l;
	InitList(&l, 10);
	ListPushBack(&l, 1);
	ListPushBack(&l, 2);
	ListPushBack(&l, 3);
	ListPushBack(&l, 4);
	Print(&l);
	ListDelete(&l, 2);
	Print(&l);
	ListPushFront(&l, 0);
	Print(&l);
	return 0;
}