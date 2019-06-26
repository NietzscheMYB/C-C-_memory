#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define MAX_CAPACITY 10

typedef struct People{
	char tel[15];
	char name[10];
	char addr[20];
}People;

typedef enum{ EXIST, EMPTY, DELET }State;

typedef struct HTElem{
	People p;
	State state;
}HTElem;

typedef struct HashTable{
	HTElem* arr;
	int size;
	int capacity;
	int IsLineDetective;
}HT;

void HashTableInit(HT* ht, int capacity, int IsLineDetective);
void HashTableInsert(HT* ht, People x);
void HashTableDelete(HT* ht, People x);
void HashTableFind(HT* ht, People x);
int HashTableSize(HT* ht);
int HashTableEmpty(HT* ht);
void CheckCapacity(HT*ht);
void HashTableDestroy(HT* ht);
int HashFunc(People x);
void Show(HT* ht);
void save(HT* ht);
int Dectective(int hashAddr);//线性探测
int Dectective2(int hashAddr, int i);//二次探测
