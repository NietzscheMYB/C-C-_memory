#include "Maze.h"

void InitMap(Maze *m, int map[ROW][COL])
{
	int i, j;
	if (NULL == m)
	{
		return;
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			m->map[i][j] = map[i][j];
		}
	}
}

void PrintMap(Maze *m)
{
	if (NULL == m)
	{
		return;
	}
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", m->map[i][j]);
		}
		printf("\n");
	}
}

int IsMazeExit(Maze *m, Position cur, Position enter)
{
	if (NULL == m)
	{
		return 0;
	}
	if (cur.x == enter.x&&cur.y == enter.y)
	{
		return 0;
	}
	if (0 == cur.x || ROW - 1 == cur.x || 0 == cur.y ||
		COL - 1 == cur.y)
	{
		return 1;   //从上出去 从下出去 从左出去 从右出去
	}
	return 0;
}

int IsPass(Maze *m, Position cur)
{
	return 1 == m->map[cur.x][cur.y];
}

int IsValidEnter(Maze *m, Position enter)
{
	if (NULL == m)
	{
		return 0;
	}
	if (0==enter.x||ROW-1==enter.x||0==enter.y||COL-1==enter.y)
	{
		if (1 == m->map[enter.x][enter.y])
		{
			return 1;
		}
	}
	return 0;
}

void PrintPath(Stack *s)
{
	Position top;
	while (StackSize(s) > 1)
	{
		top = StackTop(s);
		printf("{%d,%d}<---", top.x, top.y);
		StackPop(s);
	}
	top = StackTop(s);
	printf("{%d,%d}", top.x, top.y);
}

void PassMaze(Maze* m, Position enter, Stack*s)//循环走法
{
	Position next;
	if (!IsValidEnter(m, enter))
	{
		printf("迷宫入口有误\n");
		return;
	}
	StackPush(s, enter);
	while (!StackEmpty(s))
	{
		Position cur = StackTop(s);
		m->map[cur.x][cur.y] = 2; //相当于走过
		if (IsMazeExit(m, cur, enter))
		{
			return;
		}
		//向上走
		next = cur;
		next.x-=1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//向左走
		next = cur;
		next.y -= 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//向右走
		next = cur;
		next.y += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//向下走
		next = cur;
		next.x += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//到这一步说明是死路
		//开始退!
		m->map[cur.x][cur.y] = 3;
		StackPop(s);  //出栈可能为空
	}
}


///-----------------------------------------------------------------------------------------------
//void PassMaze1(Maze *m,Position enter)
//{
//	Stack path, shortpath;
//	StackInit(&path);
//	StackInit(&shortpath);
//	_PassMaze(m, enter, enter, &path, &shortpath);
//	
//
//}

void _PassMaze(Maze *m, Position cur, Position enter, Stack *path, Stack *shortpath)
{
	Position next;
	StackPush(path, cur);
	if (IsMazeExit(m, cur, enter))
	{
		if (StackEmpty(shortpath) || (StackSize(shortpath) > StackSize(path)))
		{
			SaveShortPath(path, shortpath);
		}
		StackPop(path);
		return;
	}
	if (cur.x==enter.x&&cur.y==enter.y)
	{
		m->map[cur.x][cur.y] = 2;
	}
	//向上走
	next = cur;
	next.x -= 1;
	if (IsNextPass(m, next, cur, enter))
	{
		m->map[next.x][next.y] = m->map[cur.x][cur.y] + 1;
		_PassMaze(m, next, enter, path, shortpath);
	}
	//向左走
	next = cur;
	next.y -= 1;
	if (IsNextPass(m, next, cur, enter))
	{
		m->map[next.x][next.y] = m->map[cur.x][cur.y] + 1;
		_PassMaze(m, next, enter, path, shortpath);
	}
	//向右走
	next = cur;
	next.y += 1;
	if (IsNextPass(m, next, cur, enter))
	{
		m->map[next.x][next.y] = m->map[cur.x][cur.y] + 1;
		_PassMaze(m, next, enter, path, shortpath);
	}
	//向下
	next = cur;
	next.x += 1;
	if (IsNextPass(m, next, cur,enter))
	{
		m->map[next.x][next.y] = m->map[cur.x][cur.y] + 1;
		_PassMaze(m, next, enter, path, shortpath);
	}
	StackPop(path); //走不下去时回退！！！出栈

}

void SaveShortPath(Stack *path, Stack *shortpath)
{
	int i = 0;
	int size = StackSize(path);
	for (; i < size; i++)
	{
		shortpath->array[i] = path->array[i];
	}
	shortpath->top = i;
}

int IsNextPass(Maze *m, Position next, Position cur, Position enter)
{
	if (next.x < 0 || next.x >= ROW || next.y < 0 || next.y >= COL)
	{
		return 0;
	}
	if ((1 == m->map[next.x][next.y]) || (m->map[cur.x][cur.y] < m->map[next.x][next.y]))
	{
		return 1;
	}
	return 0;
}





//void TestMap()
//{
//	Maze m;
//	Stack s;
//	Position enter;
//	int map[ROW][COL] = {
//		{ 0, 0, 0, 0, 0, 0 },
//		{ 0, 0, 1, 0, 0, 0 },
//		{ 0, 0, 1, 0, 0, 0 },
//		{ 0, 0, 1, 1, 1, 0 },
//		{ 0, 0, 1, 0, 1, 1 },
//		{ 0, 0, 1, 0, 0, 0 }
//	};
//	StackInit(&s);
//	InitMap(&m, map);
//	PrintMap(&m);
//	enter.x = 5;
//	enter.y = 2;
//	PassMaze(&m, enter, &s);
//	printf("\n");
//	PrintMap(&m);
//	PrintPath(&s);
//	printf("\n");
//}
void TestMap()
{
	Maze m;
//	Stack s;
	Stack path, shortpath;
	StackInit(&path);
	StackInit(&shortpath);
	Position enter;
	int map[ROW][COL] = {
		{  0, 0, 0, 0, 0 },
		{  0, 1, 1, 0, 0 },
		{  0, 1, 1, 1, 1 },
		{  0, 1, 0, 0, 0 }
	};
	//StackInit(&s);
	InitMap(&m, map);
	PrintMap(&m);
	enter.x = 3;
	enter.y = 1;
	_PassMaze(&m, enter,enter,&path,&shortpath);
	printf("\n");
	PrintMap(&m);
	PrintPath(&shortpath);
	printf("\n");
}