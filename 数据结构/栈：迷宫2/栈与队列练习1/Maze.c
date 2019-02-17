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
		return 1;   //���ϳ�ȥ ���³�ȥ �����ȥ ���ҳ�ȥ
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

void PassMaze(Maze* m, Position enter, Stack*s)//ѭ���߷�
{
	Position next;
	if (!IsValidEnter(m, enter))
	{
		printf("�Թ��������\n");
		return;
	}
	StackPush(s, enter);
	while (!StackEmpty(s))
	{
		Position cur = StackTop(s);
		m->map[cur.x][cur.y] = 2; //�൱���߹�
		if (IsMazeExit(m, cur, enter))
		{
			return;
		}
		//������
		next = cur;
		next.x-=1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//������
		next = cur;
		next.y -= 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//������
		next = cur;
		next.y += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//������
		next = cur;
		next.x += 1;
		if (IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}
		//����һ��˵������·
		//��ʼ��!
		m->map[cur.x][cur.y] = 3;
		StackPop(s);  //��ջ����Ϊ��
	}
}

int PassMaze_(Maze *m, Position enter, Position cur)
{
	if (IsPass(m, cur))
	{
		Position next;
		m->map[cur.x][cur.y] = 2;
		if (IsMazeExit(m, cur, enter))
		{
			return 1;
		}
		//������
		next = cur;
		next.x -= 1;
		if (PassMaze_(m, enter, next))
		{
			return 1;
		}
		//������
		next = cur;
		next.y -= 1;
		if (PassMaze_(m, enter, next))
		{
			return 1;
		}
		//������
		next = cur;
		next.y += 1;
		if (PassMaze_(m, enter, next))
		{
			return 1;
		}
		//������
		next = cur;
		next.x += 1;
		if (PassMaze_(m,enter, next))
		{
			return 1;
		}
		m->map[cur.x][cur.y] = 3;
		return 0;
	}
	return 0;
}

void TestMap1()
{
	Maze m;
	Stack s;
	Position enter;
	int map[ROW][COL] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 }
	};
	StackInit(&s);
	InitMap(&m, map);
	PrintMap(&m);
	enter.x = 5;
	enter.y = 2;
	PassMaze(&m, enter, &s);
	printf("\n");
	PrintMap(&m);
	PrintPath(&s);
	printf("\n");
}
void TestMap2()
{
	Maze m;
	Position enter;
	int map[ROW][COL] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 }
	};
	InitMap(&m, map);
	PrintMap(&m);
	enter.x = 5;
	enter.y = 2;
	PassMaze_(&m, enter, enter);
	printf("\n");
	PrintMap(&m);
	
	printf("\n");
}