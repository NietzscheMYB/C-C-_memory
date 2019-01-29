#pragma once

typedef struct Stack{
	int array[100];
	int top;
}Stack;

//³õÊ¼»¯
void StcakInit(Stack *stack){
	stack->top = 0;
}
//Ñ¹Õ» Î²²å
void StackPush(Stack *stack, int value){
	stack->array[stack->top] = value;
	stack->top++;
}
//³öÕ» µ¯³ö Î²É¾
void StackPop(Stack* stack)
{
	stack->top--;
}
//·µ»ØÕ»¶¥ÔªËØ
int  StackTop(const Stack* stack){
	return stack->array[stack->top - 1];
}
//»ñÈ¡size
int Stacksize(const Stack*stack){
	return stack->top;
}

