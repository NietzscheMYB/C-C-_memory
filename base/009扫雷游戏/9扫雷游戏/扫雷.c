#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#define ROW 9
#define LIN 9
#define ROWS ROW+2
#define LINS LIN+2

void menu()
{
	printf("*************************\n");
	printf("*******1.开始游戏********\n");
	printf("*******0.结束游戏********\n");
	printf("*************************\n");

}

void game()
{
	char board_show[ROWS][LINS] = { '0' };//*
	char board_mine[ROWS][LINS] = { '0' };//0
	//char sign[ROWS][LINS] = { '0' };//*********
	Init_board(board_show,'*', ROWS, LINS);
	Init_board(board_mine,'0', ROWS, LINS);
	//Init_board(sign, ROWS,'0', LINS);
	Set_mine(board_mine,ROWS,LINS);
	Print_board(board_show, ROWS, LINS);
	printf("\n");
	printf("----------------------------");
	printf("\n\n");
	Print_board(board_mine, ROWS, LINS);
	Find_mine(board_mine, board_show, ROWS, LINS);

}

int main()
{
	int input;
	srand(time(NULL));
	menu();
	scanf("%d", &input);
	//do
	//{
	//	
	//}while (input);
	switch (input)
		{
		case 1: game();
			break;
		case 0: printf("正在退出~~~~~~~\n");
			break;
		default:printf("输入错误,请重新输入\n");
			break;
		}		
	
}