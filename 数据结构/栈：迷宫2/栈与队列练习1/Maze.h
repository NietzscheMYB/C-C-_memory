#pragma once
#include "Stack.h"

//坐标封装成结构图
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
//初始化
void PrintMap(Maze *map);
//打印迷宫
int IsMazeExit(Maze *m, Position cur, Position enter);
//判断是否为迷宫出口
int IsPass(Maze *m, Position cur);
//判断走不走通
void PassMaze(Maze *m, Position enter, Stack *s);     //循环写法！！
//走迷宫！！
int IsValidEnter(Maze *m, Position enter);
//判断是否为合法入口
void PrintPath(Stack *s);
//打印路径


int PassMaze_(Maze *m, Position cur, Position enter);
//递归写法！！！



void TestMap1();
void TestMap2();
