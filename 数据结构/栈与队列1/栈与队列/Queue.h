#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// ���
typedef struct Node{
	int value;
	struct Node *next;
} Node;

//ͷɾ+β��

typedef struct Queue{
	Node *front; //�����һ�����
	Node *rear; //�������һ�����
	int size;  //���ݸ���
}Queue;

//��ʼ��  ������ȫΪ�� 
void QueueInit(Queue *queue){
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

//����
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
//push,��β���� ����β��
void QueuePush(Queue *queue, int val){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	queue->size++;
	if (queue->rear != NULL)
	{
		queue->rear->next = node; //��ַ�ı�
		queue->rear = node;  //��β���ı䣻
	}
	else
	{
		queue->front = queue->rear = node;
	}
}
//pop ���׳��У���ͷɾ
void QueuePop(Queue *queue)
{
	assert(queue->size > 0);
	queue->size--;
	Node *front = queue->front;
	queue->front = queue->front->next;
	free(front);
	if (queue->front = NULL)
	{
		//����ֻ��һ���������
		queue->rear = NULL;
	}
}
//Front ���ض���Ԫ��
int QueueFront(const Queue *queue){
	return queue->front->value;
}
//Rear ���ض�βԪ��
int QueueRear(const Queue *queue){
	return queue->rear->value;
}
//empty �Ƿ�Ϊ��
int QueueEmpty(const Queue *queue){
	return queue->size == 0 ? 1 : 0;
}
//Size
int QueueSize(const Queue *queue){
	return queue->size;
}