#pragma once
#if 0
#include<stdio.h>
#include<assert.h>
#define MAX_SIZE 10
typedef int DateType;
typedef enum{ EXIST, EMPTY, DELETE }State;
typedef struct HTElem
{
	DateType _data;
	State _state;
}HTElem;
typedef struct HashTable
{
	HTElem _array[MAX_SIZE];
	int _size;//记录哈希表格中有效元素的个数
	int _total;//表格中哈希放的元素的个数：包括存在和删除
	int _IsLineDetective;//是否为线性探测
}HashTable,HT;


void HashTableInit(HT* ht,int IsLineDetective);
void HashTableInsert(HT* ht, DateType data);
void HashTableDelete(HT* ht, DateType data);
int HashTableFind(HT* ht, DateType data);
int HashTableSize(HT* ht);
int HashTableEmpty(HT* ht);

#endif
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#define MAX_SIZE 10
typedef int DateType;
typedef enum{ EXIST, EMPTY, DELETE }State;
typedef struct HTElem
{
	DateType _data;
	State _state;
}HTElem;
typedef struct HashTable
{
	HTElem* _array;
	int _size;//记录哈希表格中有效元素的个数
	int _capacity;
	int _IsLineDetective;//是否为线性探测
}HashTable, HT;


void HashTableInit(HT* ht, int _capacity, int IsLineDetective);
void HashTableInsert(HT* ht, DateType data);
void HashTableDelete(HT* ht, DateType data);
int HashTableFind(HT* ht, DateType data);
int HashTableSize(HT* ht);
int HashTableEmpty(HT* ht);
void HashTableDestroy(HT* ht);