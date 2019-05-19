#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

// ͷɾ + β��
typedef struct Queue {
	Node *front;		// ����ĵ�һ�����
	Node *rear;			// ��������һ�����
	int size;			// ���ݸ���
}	Queue;

// ��ʼ��
void QueueInit(Queue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}
// ����
void QueueDestroy(Queue *queue) {
	Node *node, *next;
	for (node = queue->front; node != NULL; node = next) {
		next = node->next;
		free(node);
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

// Push ����β���룬�������β��
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

// Pop�� ���׳��У��������ͷɾ
void QueuePop(Queue *queue) {
	assert(queue->size > 0);
	queue->size--;
	Node *front = queue->front;
	queue->front = queue->front->next;
	free(front);

	if (queue->front == NULL) {
		// ����ֻ��һ���������
		queue->rear = NULL;
	}
}

// Front	���ض���Ԫ��
int QueueFront(const Queue *queue) {
	return queue->front->value;
}


// Rear		���ض�βԪ��
int QueueRear(const Queue *queue) {
	return queue->rear->value;
}
// Empty	�Ƿ�Ϊ��
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
	printf("������������");
	int n = 0;
	scanf("%d", &n);
	PrintTriangle(n);
	return 0;
}