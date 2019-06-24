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
		printf("该元素在哈希表中\n");

	}
	else
	{
		printf("该元素不在\n");
	}
	if (-1 != HashTableFind(&ht, 3))
	{
		printf("该元素在哈希表中\n");

	}
	else
	{
		printf("该元素不在\n");
	}
	HashTableDelete(&ht, 33);
	if (-1 != HashTableFind(&ht, 33))
	{
		printf("该元素在哈希表中\n");

	}
	else
	{
		printf("该元素不在\n");
	}

}
int main()
{
	TestHashTable();
	return 0;
}