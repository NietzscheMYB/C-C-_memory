#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//extern struct Position;  //迷宫中栈存结构体
typedef struct Position DataType;
//typedef int DataType;

typedef struct Position{
	int x;
	int y;
}Position;


typedef struct Stack{
	DataType array[100];
	int top; //表示有效元素的个数，表示栈顶的位置
}Stack;

//初始化
void StackInit(Stack *stack);
//压栈 尾插
void StackPush(Stack *stack,DataType value);
//出站 弹出 尾删
void StackPop(Stack *stack);
//返回栈顶元素
DataType StackTop( Stack *stack);
//获取size
int StackSize(const Stack *stack);
//打印
void StackPrint(const Stack *stack);
//检查栈是否为空
int StackEmpty(const Stack *stack);