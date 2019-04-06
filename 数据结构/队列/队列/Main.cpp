#include <stdio.h>
#include <malloc.h>
typedef int DataType;
typedef struct Queue{
	DataType *arr;
	DataType *front;
	DataType *rear;
	int size;
}Queue;

void QueueInit(Queue *q)
{
	q->arr = (DataType*)malloc(10 * sizeof(DataType));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue *q, DataType value)
{
	if (q->front == NULL&&q->rear == NULL)
	{
		q->arr[q->size] = value;
		q->front = q->arr;
		q->rear = q->arr;
		q->size++;
		return;
	}
	q->arr[q->size] = value;
	q->rear = q->rear + 1;
	q->size++;
}
void QueuePop(Queue *q)
{
	if (q->front == NULL&&q->rear == NULL)
	{
		return;
	}
	if (q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
		q->size--;
		return;
	}
	q->front = q->front + 1;
	q->arr = q->front;
	q->size--;
}
void QueuePrint(Queue *q)
{
	if (q->front == NULL&&q->rear == NULL)
	{
		return;
	}
	if (q->front == q->rear)
	{
		printf("%d\n", q->arr[q->size]);
	}
	for (int i = 0; i < q->size; i++)
	{
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	return 0;

}