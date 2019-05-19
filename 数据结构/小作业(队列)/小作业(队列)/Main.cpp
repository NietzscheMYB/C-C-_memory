#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

// 头删 + 尾插
typedef struct Queue {
	Node *front;		// 链表的第一个结点
	Node *rear;			// 链表的最后一个结点
	int size;			// 数据个数
}	Queue;

// 初始化
void QueueInit(Queue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}
// 销毁
void QueueDestroy(Queue *queue) {
	Node *node, *next;
	for (node = queue->front; node != NULL; node = next) {
		next = node->next;
		free(node);
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

// Push ，队尾插入，即链表的尾插
void QueuePush(Queue *queue, int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	queue->size++;

	if (queue->rear != NULL) {
		queue->rear->next = node;
		queue->rear = node;
	}
	else {
		queue->front = queue->rear = node;
	}
}

// Pop， 队首出列，即链表的头删
void QueuePop(Queue *queue) {
	assert(queue->size > 0);
	queue->size--;
	Node *front = queue->front;
	queue->front = queue->front->next;
	free(front);

	if (queue->front == NULL) {
		// 处理只有一个结点的情况
		queue->rear = NULL;
	}
}

// Front	返回队首元素
int QueueFront(const Queue *queue) {
	return queue->front->value;
}


// Rear		返回队尾元素
int QueueRear(const Queue *queue) {
	return queue->rear->value;
}
// Empty	是否为空
int QueueEmpty(const Queue *queue) {
	return queue->size == 0 ? 1 : 0;
}
//// Size
//int QueueEmpty(const Queue *queue) {
//	return queue->size;
//}

void QueuePrint(Queue *queue)
{
	int i =0;
	int len = queue->size;
	Node* cur = queue->front;
	for (; cur!=NULL; cur=cur->next)
	{

		int num = cur->value;
		
		printf("%-5d  ", num);
		
	}
	printf("\n");
}
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePrint(&q);

	QueuePop(&q);
	QueuePrint(&q);


}

void PrintTriangle(int n)
{
	Queue q;
	QueueInit(&q);
	int i = 0;
	QueuePush(&q, 1);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			printf("1\n");
			continue;
		}
		int num = QueueFront(&q);
		QueuePop(&q);
		while (!QueueEmpty(&q)&&QueueFront(&q) != 1)
		{
			num = num + QueueFront(&q);
			QueuePush(&q, num);
			num = QueueFront(&q);
			QueuePop(&q);
		}
		if (!QueueEmpty(&q))
		{
			num = num + QueueFront(&q);
		}
		QueuePush(&q, num);
		QueuePush(&q, 1);
		QueuePrint(&q);
	}
}

int main()
{
	printf("请输入行数：");
	int n = 0;
	scanf("%d", &n);
	PrintTriangle(n);
	return 0;
}