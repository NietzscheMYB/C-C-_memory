/*注意芯片是标号的
每列求和 ，总数大于一半是真，少于一半是假



*/

#include "stdio.h"
#include <windows.h>
#pragma warning(disable:4996)
#define MAXS 20 

int main()
{
	int n, text[20][20], i, j, s;
	scanf("%d", &n);

	if (n >= 2 && n <= 20)
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				scanf("%d", &text[i][j]);
			}
		}
	}
	for (j = 0; j<n; j++)
	{
		s = 0;
		for (i = 0; i<n; i++)
		{
			s += text[i][j];

		}
		if (s>n / 2)  printf("%d ", j + 1);

	}
	system("pause");
	return 0;
}