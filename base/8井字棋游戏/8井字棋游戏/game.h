#define _GAME_H
#ifndef _GAME_H


#define ROW 3
#define LIN 3
void board_Init(char arr[ROW][LIN],int row, int lin);
void Print(char arr[ROW][LIN], int row, int lin);
void Manplayer_Move(char arr[ROW][LIN], int row, int lin);
void Complayer_Move(char arr[ROW][LIN], int row, int lin);

int Judge_Win(char arr[ROW][LIN], int row, int lin);
int is_full(char arr[ROW][LIN], int row, int lin);

#endif