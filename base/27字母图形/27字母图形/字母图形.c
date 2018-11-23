
/*二维数组赋值！！！！
内循环中for(j=0;j<n;j++)
if(j<flag){}
if(j>=flag){}

*/

#include <stdio.h>
#pragma warning(disable:4996)
#include <windows.h>


int main()
{char *code= { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
char arr[100][100] = { '0' };
char *init = code;
char *code1 = code;
int n = 0, m = 0;
int i, j;
int flag=0;
printf("请输入行与列>");
scanf("%d%d", &n, &m);
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
	{
		if (j>=flag)
		{
			//code = init;
			arr[i][j] = *code++;
		}
		if (j < flag)
		{
		//	code = init;
		
			arr[i][j] = *code1--;
		}
		
	}
	code = init;
	code1 = init;
	flag++;	
	code1 = code1 + flag;
}
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
	{
		printf("%c", arr[i][j]);
	}
	printf("\n");
}

	

	system("pause");
	return 0;
}