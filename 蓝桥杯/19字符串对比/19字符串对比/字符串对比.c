#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	char arr1[10];
	char arr2[10];
	int flag=0, i, j=0;
	scanf("%s", &arr1);
	scanf("%s", &arr2);
	if (strlen(arr1) != strlen(arr2))
	{
	printf("1\n");
	}
	if (strlen(arr1) == strlen(arr2))
	{
		i = 0;
		while (arr1[i] != '\0')
		{
			if (arr1[i] == arr2[i])
			{
				j++;
			}
			i++;
		}
		if (i == j)
		{
			printf("2\n");
		}
	}
	if (strlen(arr1) == strlen(arr2))
	{
		i = 0;
		while (arr1[i] != '\0')
		{
			if ((arr1[i] - arr2[i])==0||(arr1[i]-arr2[i])==32||(arr1[i]-arr2[i])==-32)
			{
				j++;
			}
			i++;
		}
		if (i == j)
		{
			printf("3\n");

		}
	}
	if (strlen(arr1) == strlen(arr2))
	{
		i = 0;
		while (arr1[i] != '\0')
		{
			if ((arr1[i]-arr2[i])!=0 || (arr1[i] - arr2[i]) != 32 || (arr1[i] - arr2[i]) != -32)
			{
				j++;
			}
			i++;
		}
		if (i == j)
		{
			printf("4\n");
		}
	}
	//switch (flag)
	//{
	//case 1:printf("1\n"); 
	//	break;
	//case 2:printf("2\n");
	//	break;
	//case 3:printf("3\n");
	//	break;
	//case 4:printf("4\n");
	//	break;

	
	return 0;
}