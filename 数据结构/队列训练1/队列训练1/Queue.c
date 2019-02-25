#include "Queue.h"
#include <assert.h>
#include <malloc.h>
Node *BuyNode(DataType value)
{
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		return;
	}
	node->value = value;
	node->next = NULL;
	return node;
}


void QueueInit(Queue *q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue *q, DataType value)
{
	assert(q);
	Node *node = BuyNode(value);
	if (q->rear!= NULL)
	{
		q->rear->next = node;
		q->rear = node;
	}
	else{
		q->front = q->rear = node;
	}
}

void QueuePop(Queue *q)    //出队列
{
	assert(q);
	Node* Del = q->front;
	q->front = q->front->next;
	free(Del);
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}
int QueueFront(Queue *q)
{
	return q->front->value;
}
int QueueRear(Queue *q)
{
	return q->rear->value;
}
int QueueEmpty(Queue *q)
{
	return q->size == 0 ? 1 : 0;
}
int QueueSize(Queue *q)
{
	return q->size;
}
void TestQueue()
{
	Queue s;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	QueuePush(&s, 4);

	QueuePop(&s);
	QueuePop(&s);
	QueuePop(&s);
	QueuePop(&s);


}
