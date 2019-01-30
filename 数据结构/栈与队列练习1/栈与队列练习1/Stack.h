#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Stack{
	int array[100];
	int top; //��ʾ��ЧԪ�صĸ�������ʾջ����λ��
}Stack;

//��ʼ��
void StackInit(Stack *stack);
//ѹջ β��
void StackPush(Stack *stack,DataType value);
//��վ ���� βɾ
void StackPop(Stack *stack);
//����ջ��Ԫ��
int StackTop(const Stack *stack);
//��ȡsize
int StackSize(const Stack *stack);
//��ӡ
void StackPrint(const Stack *stack);