#pragma once

typedef struct Stack{
	int array[100];
	int top;
}Stack;

//��ʼ��
void StcakInit(Stack *stack){
	stack->top = 0;
}
//ѹջ β��
void StackPush(Stack *stack, int value){
	stack->array[stack->top] = value;
	stack->top++;
}
//��ջ ���� βɾ
void StackPop(Stack* stack)
{
	stack->top--;
}
//����ջ��Ԫ��
int  StackTop(const Stack* stack){
	return stack->array[stack->top - 1];
}
//��ȡsize
int Stacksize(const Stack*stack){
	return stack->top;
}

