#include"Hash.h"


void TestHashTable()
{
	HashTable ht;
	int i = 0;
	HashTableInit(&ht,i);
	HashTableInsert(&ht, 23);
	HashTableInsert(&ht, 14);
	HashTableInsert(&ht, 74);
	HashTableInsert(&ht, 33);
	HashTableInsert(&ht, 19);
	HashTableInsert(&ht, 29);

	printf("size=%d\n", HashTableSize(&ht));
	if (-1 != HashTableFind(&ht, 33))
	{
		printf("��Ԫ���ڹ�ϣ����\n");

	}
	else
	{
		printf("��Ԫ�ز���\n");
	}
	if (-1 != HashTableFind(&ht, 3))
	{
		printf("��Ԫ���ڹ�ϣ����\n");

	}
	else
	{
		printf("��Ԫ�ز���\n");
	}
	HashTableDelete(&ht, 33);
	if (-1 != HashTableFind(&ht, 33))
	{
		printf("��Ԫ���ڹ�ϣ����\n");

	}
	else
	{
		printf("��Ԫ�ز���\n");
	}

}
int main()
{
	TestHashTable();
	return 0;
}