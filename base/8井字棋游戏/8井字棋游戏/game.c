#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define LIN 3

void board_Init(char arr[ROW][LIN],int row, int lin)
{
	memset(&arr[0][0], '   ', row*lin*sizeof(arr[0][0]));
}

void Print(char arr[ROW][LIN], int row, int lin)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < LIN; j++)
		{
			printf("%c", arr[i][j]);
			if (j < LIN - 1)
			{
				printf("|");
			}
			
		}
		if (i < ROW - 1)
		{		for (j = 0; j < LIN; j++)
			{
					if (j == LIN - 1)
				{
						printf("\n");
						printf("------");
						printf("\n");
				}
			}
		}
		if (i ==ROW - 1)
		{
			printf("\n\n");
		}
	}
}

void Manplayer_Move(char arr[ROW][LIN], int row, int lin)
{
	printf("玩家走，请输入位置>");
	int x, y;
	//scanf("%d%d", &x, &y);
	int a, b;
	scanf("%d%d", &x, &y);
	a = x-1;
	b = y-1;
	if (arr[a][b] != ' ')
	{
		printf("请重新输入位置>");
		scanf("%d%d", &x, &y);
		a = x - 1;
		b = y - 1;
	}
	while (arr[a][b] == ' ')
	{
		arr[a][b] = '1';
		Print(arr, a, b);
	}
	
}

void Complayer_Move(char arr[ROW][LIN], int row, int lin)
{
	int x, y;
	//int a, b;
//	printf("电脑走\n");
	x = rand() % 3 ;
	y = rand() % 3 ;
	if (arr[x][y] != ' ')
	{
		x = rand() % 3 ;
		y = rand() % 3;
	}
	while (arr[x][y] == ' ')
	{
		arr[x][y] = '0';
		printf("电脑走\n");
		Print(arr, x, y);
	}
	
}

int Judge_Win(char arr[ROW][LIN],int row,int lin)
{
	int i, j;
	int ping=1;
	int  sum,sum2=0;
	for (i = 0; i < row; i++)
	{
		sum = 0;
		for (j = 0; j < lin; j++)
		{
			sum = sum + arr[i][j];
		}
		if (sum == row * 48)   //0的ascii 总和等于3*48表示够三个棋子  行
		{
			printf("电脑赢！\n游戏结束！");
			
			return 0;
		}
		if (sum == row * 49)
		{
			printf("玩家赢！\n游戏结束！"); 
			return 0;
		}
	}
	for (j = 0; j < lin; j++)
	{
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum = sum + arr[i][j];
		}
		if (sum == lin * 48)
		{
			printf("电脑赢！\n游戏结束！"); 
			return 0;
		}
		if (sum == lin * 49)
		{
			printf("玩家赢！\n游戏结束！"); 
			return 0;
		}
		
	}
	for (i = 0; i< row; i++)
	{
		
		for (j = 0; j < lin; j++)
		{
			if (i == j)
			sum2 = sum2 + arr[i][j];
			
		}
		if (sum2 == lin * 48)
		{
			printf("电脑赢！\n游戏结束！");
			return 0;
		}
		if (sum2 == lin * 49)
		{
			printf("玩家赢！\n游戏结束！");
			return 0;
		}
	}
	if (ping != is_full(arr, row, lin))
	{
		printf("平局！");
		return 0;
	}
	return 1;
}

int is_full(char arr[ROW][LIN], int row, int lin)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lin; j++)
		{
			if (arr[i][j] == ' ')
				return 1;
		}
	}
	return 0;
}