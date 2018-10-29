#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define LIN 3

void menu()
{
	printf("*********************************\n");
	printf("***********1.��ʼ��Ϸ***********\n");
	printf("***********0.������Ϸ************\n");
	printf("*********************************\n");
}

void game()
{
	int flag = 1;
	srand(  time(NULL));
	char board[ROW][LIN] = { '0'};
	board_Init(board, ROW, LIN);
	Print(board, ROW, LIN);
	while (flag == 1)
	{
		Manplayer_Move(board,ROW,LIN);
		Complayer_Move(board,ROW, LIN);
		flag=Judge_Win(board,ROW,LIN);
	}
	printf("\n");
	
}

int main()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
				break;
			case 0:
				break;
			default:printf("�����������������\n");
		}
	} while (input);
	return 0;
}