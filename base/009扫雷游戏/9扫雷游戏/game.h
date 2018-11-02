#define __GAME_H_
#ifndef __GAME_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define LIN 9
#define ROWS ROW+2
#define LINS LIN+2

void Init_board(char arr[ROWS][LINS],char ret, int rows,int  lins);
void Set_mine(char arr[ROWS][LINS], int row, int lin);
void Find_mine(char arr[ROW][LINS],int row,int lin);
int is_mind(char arrs[ROWS][LINS], char arr[ROW][LIN], int row, int lin);
void open(char arrs[ROWS][LINS], char arr[ROWS][LINS], int x, int y);
int count(char arrs[ROWS][LINS], int x, int y);



#endif