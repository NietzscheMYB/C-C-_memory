#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>

#define MAX_CAPCAITY  50

//#define CONTACT_FILE "contact.txt"




typedef struct People
{
	char Name[10]  ;
	char Street[10];
	char City[10];
	char Eip[10];
	char State[10];
	
}People,*People_p;

typedef struct Contact
{
	int _size;
	int _capacity;
	People *_arr;
}Contact,*Contact_p;

void ContactInit(Contact* ct);
void ContactAdd(Contact* ct, People data);
void ContactShow(Contact* ct);
void ContactDelete(Contact* ct, char* name);
void ContactSearch(Contact* ct, const char* name);
void ContactDestroy(Contact* ct);
void DealCapacity(Contact* ct);
void save(Contact* ct);



