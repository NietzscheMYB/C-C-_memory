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
	printf("����ߣ�������λ��>");
	int x, y;
	//scanf("%d%d", &x, &y);
	int a, b;
	scanf("%d%d", &x, &y);
	a = x-1;
	b = y-1;
	if (arr[a][b] != ' ')
	{
		printf("����������λ��>");
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
//	printf("������\n");
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
		printf("������\n");
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
		if (sum == row * 48)   //0��ascii �ܺ͵���3*48��ʾ����������  ��
		{
			printf("����Ӯ��\n��Ϸ������");
			
			return 0;
		}
		if (sum == row * 49)
		{
			printf("���Ӯ��\n��Ϸ������"); 
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
			printf("����Ӯ��\n��Ϸ������"); 
			return 0;
		}
		if (sum == lin * 49)
		{
			printf("���Ӯ��\n��Ϸ������"); 
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
			printf("����Ӯ��\n��Ϸ������");
			return 0;
		}
		if (sum2 == lin * 49)
		{
			printf("���Ӯ��\n��Ϸ������");
			return 0;
		}
	}
	if (ping != is_full(arr, row, lin))
	{
		printf("ƽ�֣�");
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