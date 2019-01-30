#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Stack{
	int array[100];
	int top; //表示有效元素的个数，表示栈顶的位置
}Stack;

//初始化
void StackInit(Stack *stack);
//压栈 尾插
void StackPush(Stack *stack,DataType value);
//出站 弹出 尾删
void StackPop(Stack *stack);
//返回栈顶元素
int StackTop(const Stack *stack);
//获取size
int StackSize(const Stack *stack);
//打印
void StackPrint(const Stack *stack);