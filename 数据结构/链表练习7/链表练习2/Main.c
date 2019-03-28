#include <stdio.h>
#include <malloc.h>
typedef int DataType;
typedef struct Node{
	DataType value;
	struct Node* next;
}Node,*List;

Node *ButNode(DataType value)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void ListInit(List* l)
{
	*l = NULL;
}
void ListPushBack(List*l, DataType value)
{
	if (*l == NULL)
	{
		Node *node = ButNode(value);
		*l = node;
	}

}
//list ������һ��ָ�����ͣ�����Ҫ���һ�����ڵ�ĵ�ַ�ʹ���l��
//�ڸ�������б����l�ĵ�ַ���������Ա����βΣ����Ƕ�l���� 
//�ú���ʵ�־��Ǵ���ַ������
int main()
{
	List l;
	ListInit(&l);
	ListPushBack(&l, 1);
	return 0;
}