#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <search.h>
#include <stdlib.h>

#define NAME_SIZE 32
#define TEL_SIZE 16
#define ADDR_SIZE 128

#define CONTACT_FILE "contact.txt"

#define INIT 1

typedef struct people{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char telphone[TEL_SIZE];
	char address[ADDR_SIZE];
}people_t, *people_p, **people_pp;

typedef struct contact{
	int cap;
	int size;
	people_t peoples[0];
}contact_t, *contact_p, **contact_pp;

#pragma warning(disable:4996)

contact_p initContact();
void addPeople(contact_pp ct_, people_p p_);
void deletePeople(contact_p ct_, const char *name_);
void updatePeople();
void searchPeople(contact_p ct_, const char *name_);
void listPeople(contact_p ct_);
void clearContact(contact_p ct_);
void sortContact(contact_p ct_);
void destoryContact(contact_p ct);

void save(contact_p ct, const char *file_);

#endif