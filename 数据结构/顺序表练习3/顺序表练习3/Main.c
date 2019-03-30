#include <stdio.h>

typedef int DataType;
typedef struct Seqlist{
	DataType *arr;
	int capacity;
	int size;
}Seqlist;

void SeqlistInit(Seqlist *l)
{
	l->arr = (Seqlist*)malloc(sizeof(int)*20);//开辟20个整形大小
	l->capacity = 20;
	l->size = 0;
}

void SeqlistPushBack(Seqlist *l, DataType value)
{
	if (l == NULL)
	{
		return;
	}
	l->arr[l->size] = value;
	l->size++;
}

void SeqlistPushFront(Seqlist *l, DataType value)
{
	if (l == NULL)
	{
		return;
	}
	for (int i = l->size - 1; i >= 0; i--)
	{
		l->arr[i + 1] = l->arr[i];
	}
	l->arr[0] = value;
	l->size++;
}
void SeqlistPrint(Seqlist *l)
{
	if (l == NULL)
	{
		return;
	}
	for (int i = 0; i < l->size; i++)
	{
		printf("%d ", l->arr[i]);
	}
	printf("\n");
}
void classify(Seqlist *l)
{
	int begin = 0, end = l->size - 1;
	int tmp = l->arr[0];
	while (begin < end)
	{
		while (begin < end&&l->arr[begin]<=l->arr[0])
		{
			begin++;
		}
		while (begin < end&&l->arr[end] >= l->arr[0])
		{
			end--;
		}
		int k = l->arr[begin];
		l->arr[begin] =l->arr[end];
		l->arr[end] = k;
	}
	int o = l->arr[begin-1];
	l->arr[begin-1] = l->arr[0];
	l->arr[0] =o ;
}
int main()
{
	Seqlist l;
	SeqlistInit(&l);
	SeqlistPushBack(&l, 1);
	SeqlistPushBack(&l, 2);
	SeqlistPushBack(&l, 3);
	//SeqlistPushBack(&l, 4);
	SeqlistPushBack(&l, 5);
	SeqlistPushBack(&l, 6);
	SeqlistPrint(&l);
	SeqlistPushFront(&l, 0);
	SeqlistPrint(&l);
	SeqlistPushFront(&l, 4);
	SeqlistPrint(&l);
	classify(&l);
	SeqlistPrint(&l);
	return 0;
}