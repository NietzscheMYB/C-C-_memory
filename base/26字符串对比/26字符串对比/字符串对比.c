#include <stdio.h>
#include <string.h>
#include <windows.h>
int Judge_string( char *arr1, char* arr2, int sz1, int sz2)
{
	int i;
	if (sz1 != sz2)
	{
		return 1;
	}
	if (sz1 == sz2)
	{
		if ((strncmp(arr1, arr2,sz1)) == 0)
			return 2;
		for (i = 1; i <= sz1; i++)
		{
			if ((*arr1 - *arr2 == 32) || (*arr1 - *arr2 == -32))
			{
				arr1 + i;
				arr2 + i;
				return 3;
			}
			
			else
			return 4;
		}
		
		
		/*if (strncmp(arr1, arr2, sz1) != 0)
			return 3;*/
	}
	return 0;
}
int main()
{
	const char *arr1 = { "HELLOwarD" };
	const char *arr2 = { "hellowarD" };
	//const char *arr2 = { "HELLOward" };
	int sz1 = strlen(arr1);
	int sz2 = strlen(arr2);
	int ret=Judge_string(arr1, arr2, sz1, sz2);
	printf("%d\n", ret);
	system("pause");
}