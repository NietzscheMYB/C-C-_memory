#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int Judge(char *p)
{
	int i = 0;
	int flag1 = 0,flag2=0;
	int count = 0;
	for (i = 0; i < 4; i++)
	{
		if (*(p + i) >= 'A' && *(p + i) <= 'Z')
		{
			flag1 = 1;
			count++;
		}
		if (*(p + i) >= '0' && *(p + i) <= '9')
		{
			flag2 = 1;
		}
	}
	if (count == i)
		return 0;
	if (flag1 || flag2)
		return 1;
}
int Limit(char *p)
{
	int i = 4;
	for (i = 4; i >= 0; i--)
	{
		if (*(p + i) >= '0'&&*(p + i) <= '9')
		{
			if (*(p + i)== '1'||*(p + i) == '9')
				return 1;
			if (*(p + i)== '2'||*(p + i) == '8')
				return 2;
			if (*(p + i)=='3'||*(p + i) == '7')
				return 3;
			if (*(p + i)=='4'||*(p + i) == '5')
				return 4;
			if (*(p + i)=='5'||*(p + i) == '0')
				return 5;
		}
	}
	
}
int main()
{
	int ret = 0;
	int data = 0;
	char arr1[1000] = { "0" };
	char arr2[1000][10] = { "0" };
	scanf("%s", &arr1);
	scanf("%d", &data);
	int i = 0, j = 0,k=0,l=0,flag=0;
	for (i = 0; i < strlen(arr1); i++)
	{

		if ((arr1[i] == ','))
		{
			if ((i) % 5 == 0)
			{
				for (j = i; j < strlen(arr1); j++)
				{
					arr1[j] = arr1[j + 1];
				}
				flag--;
			}
			else
			{
				printf("error\n");
				return 0;
			}
		}
		if ((arr1[i] != ','))
		{
			flag++;
		}
	}
	if ((flag == i)&&(strlen(arr1)>5))
	{
		printf("error\n");
		return 0;
	}
	j = 0;
	for (i = 0; i < strlen(arr1); i++)
	{
		arr2[j][l++] = arr1[i];
		if ((i + 1) % 5 == 0)
		{
			j++;
			l = 0;
		}
	}
	for (i = 0; i < j; i++)  //j表示几行
	{
		ret = Judge(&arr2[i]);
		if (ret == 0)
		{
			printf("error\n");
			return 0;
		}
	}
	//if (ret == 0)
	//{
	//	printf("error\n");
	//	return 0;
	//}
	for (i = 0; i < j; i++)
	{
		if (data == 6 || data == 7)
		{
			for (i = 0; i < j; i++)
			{
				for (k = 0; k < 5; k++)
				{
					printf("%c", arr2[i][k]);
					if (k == 4)
						printf("\n");
				}
			}
			return 0;
		}
		if (data == Limit(&arr2[i]))
		     printf("%s\n", arr2[i]);
	}

	//for (i = 0; i < j; i++)
	//{
	//	for (k = 0; k < 5; k++)
	//	{
	//		printf("%c", arr2[i][k]);
	//		if (k == 4)
	//			printf("\n");
	//	}
	//}
	return 0;

}