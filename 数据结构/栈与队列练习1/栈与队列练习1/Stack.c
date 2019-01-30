#include "Stack.h"

void StackInit(Stack *stack)
{
	assert(stack);
	stack->top = 0;
}

void StackPush(Stack *stack,DataType value)
{
	assert(stack);
	stack->array[stack->top++] = value;
}

void StackPop(Stack *stack)
{
	assert(stack);
	stack->top--;
}

int StackTop(const Stack *stack)
{
	return stack->array[stack->top - 1];
}

int StackSize(const Stack *stack)
{
	return stack->top;
}
void StackPrint(const Stack *stack)
{
	int i = 0;
	for (i = 0; i <= stack->top - 1; i++)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}

void TestStack()
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	StackPrint(&stack);
	StackPop(&stack);
	StackPrint(&stack);
	StackPop(&stack);
	StackPrint(&stack);
	int top = StackTop(&stack);
	int size = StackSize(&stack);
	printf("top=%d  size=%d\n", top, size);
}