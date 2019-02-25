#pragma once
#include <stdio.h>
typedef int DataType;
typedef struct Node{
	DataType value;
	struct Node* next;
}Node;

typedef struct Queue{
	Node *front;
	Node *rear;
	int size;
}Queue;

void QueueInit(Queue *q);
void QueuePush(Queue *q, DataType value);
void QueuePop(Queue *q);
DataType QueueFront(Queue *q);
DataType QueueBack(Queue *q);
int QueueSize(Queue *q);
int QueueEmpty(Queue *q);
Node *BuyNode(DataType value);
void TestQueue();