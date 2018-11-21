#include <stdio.h>
#pragma warning(disable:4996)
#include <windows.h>
char code[] = { "0123456789ABCDEF" };
void Change(int a)
{
    char arr[20] = { "0" };
	int i,j=0;
	while (a){
		for (i = 0; i < 16; i++)
		{
			if (a % 16 == i)
			{
				arr[j++] = code[i];
			}
		}
		a = a / 16;

	}
	for (i = j-1; i >=0; i--)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}
int main()
{
	
	int a = 0, ret = 0;
	printf("请输入一个十进制的数>");
	scanf("%d", &a);
    Change(a);
	system("pause");
	return 0;
}