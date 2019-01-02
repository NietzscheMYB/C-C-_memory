#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 结点
typedef struct Node{
	int value;
	struct Node *next;
} Node;

//头删+尾插

typedef struct Queue{
	Node *front; //链表第一个结点
	Node *rear; //链表最后一个结点
	int size;  //数据个数
}Queue;

//初始化  队列完全为空 
void QueueInit(Queue *queue){
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

//销毁
void QueueDestroy(Queue *queue){
	Node *node, *next;
	for (node = queue->front; node != NULL; node =next)
	{
		next = node->next;
		free(node);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}
//push,队尾插入 链表尾插
void QueuePush(Queue *queue, int val){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	queue->size++;
	if (queue->rear != NULL)
	{
		queue->rear->next = node; //地址改变
		queue->rear = node;  //队尾结点改变；
	}
	else
	{
		queue->front = queue->rear = node;
	}
}
//pop 队首陈列，即头删
void QueuePop(Queue *queue)
{
	assert(queue->size > 0);
	queue->size--;
	Node *front = queue->front;
	queue->front = queue->front->next;
	free(front);
	if (queue->front = NULL)
	{
		//处理只有一个结点的情况
		queue->rear = NULL;
	}
}
//Front 返回队首元素
int QueueFront(const Queue *queue){
	return queue->front->value;
}
//Rear 返回队尾元素
int QueueRear(const Queue *queue){
	return queue->rear->value;
}
//empty 是否为空
int QueueEmpty(const Queue *queue){
	return queue->size == 0 ? 1 : 0;
}
//Size
int QueueSize(const Queue *queue){
	return queue->size;
}