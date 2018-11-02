#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#define ROW 9
#define LIN 9
#define ROWS ROW+2
#define LINS LIN+2
#define MINE 10



int is_mind(char arrs[ROWS][LINS], char arr[ROW][LIN], int row, int lin);
void open(char arrs[ROWS][LINS], char arr[ROWS][LINS], int x, int y);
int count(char arrs[ROWS][LINS], int x, int y);

void Init_board(char arr[ROWS][LINS],char ret, int rows,int  lins)
{
	memset(&arr[0][0], ret, rows*lins*sizeof(arr[0][0]));
}

void Print_board(char arr[ROWS][LINS], int row, int lin)
{
	int i = 0, j = 0;
	printf("0  ");
	for (i = 1; i < lin-1;i++)
	{
		printf("%d  ",i);
	}
	printf("\n");

	for (i = 1; i < row-1; i++)
	{
		printf("%d  ", i);
		for (j = 1; j < lin-1; j++)
		{
			printf("%c  ", arr[i][j]);
		}
		printf("\n");
	}

}

void Set_mine(char arr[ROWS][LINS], int row, int lin)
{
	int x, y;
	//int a, b;
	int i;

	for (i = 0; i < MINE; i++)
	{
		
			x = rand() % 9+1;
	        y = rand() % 9+1;
			arr[x][y] = '1';
	}

}

void Find_mine(char arrs[ROWS][LINS],char arr[ROWS][LINS], int row, int lin)
{
	int x, y;
	int a, b;
	int first = 0;
	int flag = 1;
	int ret = 0;
	int num = row*lin - MINE;
	while (flag)
	{
		printf("请输入坐标>");
		scanf("%d%d",&x,&y);
		a = x ;
		b = y ;
		ret = is_mind(arrs, arr, a, b);
		if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
		{
			first++;
			switch (ret)
			{
			case 0: open(arrs, arr, a, b);
				Print_board(arrs, ROWS, LINS);
				printf("\n");
				printf("----------------------------");
				printf("\n\n");
				Print_board(arr, ROWS, LINS);
				break;
			case 1:	printf("你被炸掉了\nGAMEOVER!!!!!!!!\n");
				flag = 0;
				break;

			}
			if (0 == num)
			{
				printf("游戏结束，玩家赢！！！\n");
				break;
			}
		}
		else
		{
			printf("输入错误请重新输入\n");
		}
	}
	
}


int is_mind(char arrs[ROWS][LINS], char arr[ROW][LIN], int row, int lin)
{
	if (arr[row - 1][lin - 1] == '1')
		return 1;
	else
		return 0;

}

void open(char arrs[ROWS][LINS], char arr[ROWS][LINS], int x, int y)
{
	if (arrs[x -1][y -1] == '0'&&arr[x - 1][y - 1] == '*')
	{
		arr[x-1][y-1] = count(arrs, x - 1, y - 1) + '0';
	}
	if (arrs[x - 1][y] == '0'&&arr[x - 1][y] == '*')
	{
		arr[x - 1][y] = count(arrs, x - 1, y) + '0';
		/*if (count(arrs, x - 1, y) == 0)
		{
			open(arrs, arr, x - 1, y);
		}*/
	}
	if (arrs[x - 1][y + 1] == '0'&&arr[x - 1][y + 1] == '*')
	{
		arr[x - 1][y + 1] = count(arrs, x - 1, y + 1) + '0';
		/*if (count(arrs, x - 1, y + 1) == 0)
		{
			open(arrs, arr, x - 1, y + 1);
		}*/
	}
	if (arrs[x ][y - 1] == '0'&&arr[x ][y - 1] == '*')
	{
		arr[x ][y - 1] = count(arrs, x , y - 1) + '0';
		/*if (count(arrs, x , y-1) == 0)
		{
			open(arrs, arr, x , y - 1);
		}*/
	}
	if (arrs[x][y + 1] == '0'&&arr[x][y + 1] == '*')
	{
		arr[x][y + 1] = count(arrs, x, y + 1) + '0';
		/*if (count(arrs, x, y+1) == 0)
		{
			open(arrs, arr, x, y + 1);
		}*/
	}
	if (arrs[x+1][y -1] == '0'&&arr[x+1][y - 1] == '*')
	{
		arr[x+1][y - 1] = count(arrs, x+1, y - 1) + '0';
	/*	if (count(arrs, x+1, y - 1) == 0)
		{
			open(arrs, arr, x+1, y - 1);
		}*/
	}
	if (arrs[x + 1][y] == '0'&&arr[x + 1][y] == '*')
	{
		arr[x + 1][y] = count(arrs, x + 1, y ) + '0';
		/*if (count(arrs, x + 1, y) == 0)
		{
			open(arrs, arr, x + 1, y  );
		}*/
	}
	if (arrs[x + 1][y+1] == '0'&&arr[x + 1][y+1] == '*')
	{
		arr[x + 1][y+1] = count(arrs, x + 1, y+1) + '0';
		/*if (count(arrs, x + 1, y+1) == 0)
		{
			open(arrs, arr, x + 1, y+1);
		}*/
	}
}

int count(char arrs[ROWS][LINS], int x, int y)
{
	return (arrs[x - 1][y - 1] + arrs[x - 1][y] + arrs[x - 1][y + 1
	] + arrs[x][y - 1] + arrs[x][y + 1]
	+ arrs[x + 1][y - 1] + arrs[x + 1][y] + arrs[x + 1][y + 1]
	- '0' * 8);
}