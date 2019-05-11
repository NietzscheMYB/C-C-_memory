#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
typedef char DataType;

typedef struct Stack{
	char array[100];
	int top; //表示有效元素的个数，表示栈顶的位置
}Stack;


//初始化
void StackInit(Stack *stack)   
{
	assert(stack);
	stack->top = 0;
}


//入栈
void StackPush(Stack *stack, DataType value)
{
	assert(stack);
	stack->array[stack->top++] = value;
}

//出栈
void StackPop(Stack *stack)
{
	assert(stack);
	stack->top--;
}
//返回栈顶元素
char StackTop(const Stack *stack)
{
	return stack->array[stack->top - 1];
}

//返回长度
int StackSize(const Stack *stack)
{
	return stack->top;
}
//打印
void StackPrint(const Stack *stack)
{
	int i = 0;
	for (i = 0; i <= stack->top - 1; i++)
	{
		printf("%c ", stack->array[i]);
	}
	printf("\n");
}

void TestStack()
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, '1');
	StackPush(&stack, '2');
	StackPush(&stack, '3');
	StackPush(&stack, '4');
	StackPush(&stack, '5');
	StackPrint(&stack);
	StackPop(&stack);
	StackPrint(&stack);
	StackPop(&stack);
	StackPrint(&stack);
	int top = StackTop(&stack);
	int size = StackSize(&stack);
	printf("top=%c size=%d\n", top, size);
}

void Change(char arr1[], char arr2[])
{
	Stack s1, s2;
	StackInit(&s1);
	StackInit(&s2);
	int len1 = strlen(arr1);
	//for (int i = 0; i < len1; i++)
	//{
	//	char x = arr1[i];
	//	if (x != '(' && x != ')' && x != '+' && x != '-' && x != '/' && x != '*')
	//	{
	//		StackPush(&s1, x);
	//		continue;
	//	}
	//}
	//StackPrint(&s1);

	for (int i = 0; i < len1; i++)
	{
		char x = arr1[i];
		if (x != '(' && x != ')' && x != '+' && x != '-' && x != '/' && x != '*')
			{
				StackPush(&s1, x);
				continue;
			}
		switch (x)
		{
		case '(':StackPush(&s2, x);
			break;
		case ')':while (StackTop(&s2) != '(')
		{
					 StackPush(&s1, StackTop(&s2));
					 StackPop(&s2);
		}
				 StackPop(&s2);
				 break;
		case '*':if (StackSize(&s2)==0)//== NULL || StackTop(&s2) == '*' || StackTop(&s2) == '/'
		{
					 StackPush(&s2, x);
					 break;
		}
				 while (StackTop(&s2) == '*' || StackTop(&s2) == '/')
				 {
					 StackPush(&s1, StackTop(&s2));
					 StackPop(&s2);
				 }
				 StackPush(&s2, x);
				 break;
		case'/':if (StackSize(&s2) == 0)//== NULL || StackTop(&s2) == '*' || StackTop(&s2) == '/'
		{
					StackPush(&s2, x);
					break;
		}
				while (StackTop(&s2) == '*' || StackTop(&s2) == '/')
				{
					StackPush(&s1, StackTop(&s2));
					StackPop(&s2);
				}
				StackPush(&s2, x);
				break;
		case '+':if (StackSize(&s2) == 0)//== NULL || StackTop(&s2) == '*' || StackTop(&s2) == '/'
		{
					 StackPush(&s2, x);
					 break;
		}
				 while (StackTop(&s2) == '*' || StackTop(&s2) == '/' || StackTop(&s2) == '+' || StackTop(&s2) == '-')
				 {
					 StackPush(&s1, StackTop(&s2));
					 StackPop(&s2);
				 }
				 StackPush(&s2, x);
				 break;
		case '-':if (StackSize(&s2) == 0)//== NULL || StackTop(&s2) == '*' || StackTop(&s2) == '/'
		{
					 StackPush(&s2, x);
					 break;
		}
				 while (StackTop(&s2) == '*' || StackTop(&s2) == '/' || StackTop(&s2) == '+' || StackTop(&s2) == '-')
				 {
					 StackPush(&s1, StackTop(&s2));
					 StackPop(&s2);
				 }
				 StackPush(&s2, x);
				 break;
		}
	}
	while (StackSize(&s2) != 0)
	{
		StackPush(&s1, StackTop(&s2));
		StackPop(&s2);
	}
	StackPrint(&s1);
	int size = StackSize(&s1);
	for (int i = size-1; i >=0; i--)
	{
		arr2[i] = StackTop(&s1);
		StackPop(&s1);
	}
	
}
void i2s(int num, string &str) {
	stringstream ss;
	ss << num;
	ss >> str;
}
void s2u(int num, string &str) {
	stringstream ss;
	ss >> num;
	ss << str;
}


int ReverseCaluate(char arr[])
{
	Stack s;
	StackInit(&s);
	int a = 0, b = 0, c = 0;
	int d = 0;
	int len = strlen(arr);
	int m[10] = { 0 ,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < len; i++)
	{
		char x = arr[i];
		if (x != '(' && x != ')' && x != '+' && x != '-' && x != '/' && x != '*')
		{
			StackPush(&s, x);
			continue;
		}
		switch (x)
		{
		case '+': a = StackTop(&s) - '0'; StackPop(&s);  b = StackTop(&s) - '0'; StackPop(&s);
			 c = a + b;  d = c + '0';
			StackPush(&s, d);
			break;
		case '-': a = StackTop(&s) - '0'; StackPop(&s);  b = StackTop(&s) - '0'; StackPop(&s);
			 c = a - b;  d = c + '0';
			StackPush(&s, d);
			break;
		case '*': a = StackTop(&s) - '0'; StackPop(&s); b = StackTop(&s) - '0'; StackPop(&s);
			c = a * b;d = c + '0';
			StackPush(&s, d);
			break;
		case '/': a = StackTop(&s) - '0'; StackPop(&s);  b = StackTop(&s) - '0'; StackPop(&s);
			 c = a / b;d = c + '0';
			StackPush(&s, d);
			break;
		}

	}
	int num = StackTop(&s) - '0';
	return num;
}

void test()
{
	char arr1[10] = { "3+2*5" };
	char arr2[10] = { "0" };
	printf("转换前：%s\n", arr1);
	Change(arr1, arr2);
	printf("转换后%s\n", arr2);
	int x1 = ReverseCaluate(arr2);
	printf("计算结果：%d\n", x1);

	printf("\n");


	char arr3[50] = { "((3+5*2)+2)/5+6/3*2+3" };
	char arr4[50] = { "0" };
	printf("转换前：%s\n", arr3);
	Change(arr3, arr4);
	printf("转换后%s\n", arr4);
	int x2 = ReverseCaluate(arr4);
	printf("计算结果：%d\n",x2);

}
void xx()
{
	char x = 2;
	printf("%d\n", x-'0');
}
int main()
{
	test();
	return 0;
}