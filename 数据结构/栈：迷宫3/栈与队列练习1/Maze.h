#pragma once
#include "Stack.h"

//坐标封装成结构图
//typedef struct Position{
//	int x;
//	int y;
//}Position;

#define ROW 4
#define COL 5

typedef struct Maze{
	int map[ROW][COL];
}Maze;


void InitMap(Maze *m, int map[ROW][COL]);
//初始化
void PrintMap(Maze *map);
//打印迷宫
int IsMazeExit(Maze *m, Position cur, Position enter);
//判断是否为迷宫出口
int IsPass(Maze *m, Position cur);
//判断走不走通
void PassMaze(Maze *m, Position enter, Stack *s);
//走迷宫！！
int IsValidEnter(Maze *m, Position enter);
//判断是否为合法入口
void PrintPath(Stack *s);
//打印路径

void TestMap();


//走带环迷宫
void PassMaze1(Maze *m, Position enter);
void _PassMaze(Maze *m, Position cur, Stack *path, Stack *ShortPath);
void SaveShortPath(Stack *path, Stack *ShortPath);
int IsNextPass(Maze *m, Position cur, Position next,Position enter);