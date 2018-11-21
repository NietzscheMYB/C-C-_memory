#include <stdio.h>
#include <windows.h>
#include <assert.h>

int Judge_string(char arr1[], char arr2[], int sz1, int sz2)
{
		assert(arr1);
		assert(arr2);
		int temp, i;
		int flag = 0;
		while (sz2--)
		{
			temp = arr2[0];
			for (i = 1; i < sz1; i++)
			{
				arr2[i - 1] = arr2[i];
			}
			arr2[i - 1] = temp;
			
			if (strncmp(arr1, arr2, sz1) == 0)
			{
			printf("%s\n", arr2);
				return 1;
			}
		}
		
		return 0;
}
	
		


int main()
{


		
			char arr1[] = { "ABCDabc123" };
			char arr2[] = { "abc123ABCD" };
			int sz1 = strlen(arr1);
			int sz2 = strlen(arr2);
			printf("%s\n", arr2);
			int ret = 0;
			ret = Judge_string(arr1, arr2, sz1, sz2);
			printf("%d\n", ret);
		



	system("pause");	return 0;
}