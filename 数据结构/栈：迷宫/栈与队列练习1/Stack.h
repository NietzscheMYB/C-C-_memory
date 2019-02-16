#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//extern struct Position;  //�Թ���ջ��ṹ��
typedef struct Position DataType;
//typedef int DataType;

typedef struct Position{
	int x;
	int y;
}Position;


typedef struct Stack{
	DataType array[100];
	int top; //��ʾ��ЧԪ�صĸ�������ʾջ����λ��
}Stack;

//��ʼ��
void StackInit(Stack *stack);
//ѹջ β��
void StackPush(Stack *stack,DataType value);
//��վ ���� βɾ
void StackPop(Stack *stack);
//����ջ��Ԫ��
DataType StackTop( Stack *stack);
//��ȡsize
int StackSize(const Stack *stack);
//��ӡ
void StackPrint(const Stack *stack);
//���ջ�Ƿ�Ϊ��
int StackEmpty(const Stack *stack);