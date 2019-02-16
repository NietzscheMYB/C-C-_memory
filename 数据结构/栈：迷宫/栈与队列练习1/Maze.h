#pragma once
#include "Stack.h"

//�����װ�ɽṹͼ
//typedef struct Position{
//	int x;
//	int y;
//}Position;

#define ROW 6
#define COL 6

typedef struct Maze{
	int map[ROW][COL];
}Maze;


void InitMap(Maze *m, int map[ROW][COL]);
//��ʼ��
void PrintMap(Maze *map);
//��ӡ�Թ�
int IsMazeExit(Maze *m, Position cur, Position enter);
//�ж��Ƿ�Ϊ�Թ�����
int IsPass(Maze *m, Position cur);
//�ж��߲���ͨ
void PassMaze(Maze *m, Position enter, Stack *s);
//���Թ�����
int IsValidEnter(Maze *m, Position enter);
//�ж��Ƿ�Ϊ�Ϸ����
void PrintPath(Stack *s);
//��ӡ·��

void TestStack();
