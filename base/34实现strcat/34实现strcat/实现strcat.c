/*sizeof运算的是数组的大小不是字符串的大小！！！*/


#include <stdio.h>
#include <assert.h>
void My_strcpy(char arr1[], char arr2[],int sz1,int sz2)
{
	assert(arr1);
	assert(arr2);
	int i = 0,j=0;
	int start1 = sz1+1;
	int len2 = sz2;
	for (i = 0; arr1[i] != '\0'; i++)
	{
		start1 = i;
	}
	for (i = 0; i < sz2; i++)
	{
		arr1[start1 + i] = arr2[i];
	}
	arr1[start1 + i] = '\0';
	printf("%s\n", arr1);
		
}
int main()
{
	char arr1[20] = { "abcdef" };
	char arr2[] = { "cainm" };
	int sz1 = sizeof(arr1)/sizeof(arr1[0]) - 1;
	int sz2 = sizeof(arr2)/sizeof(arr2[0]) - 1;
	//printf("%d", sz2);
	My_strcpy(arr1, arr2,sz1,sz2);
	return 0;
}