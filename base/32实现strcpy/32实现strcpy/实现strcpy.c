#include <stdio.h>
#include <assert.h>
void My_strcpy(char arr1[], char arr2[],int sz1,int sz2)
{
	assert(arr1);
	assert(arr2);
	int i = 0;
	while (arr1[i] != '\0')
	{
		arr2[i] = arr1[i];
		i++;
	}
	arr2[i] = '\0';

}
int main()
{
	char arr1[] = { "abcde" };
	char arr2[50] = { "0" };
	int sz1 = sizeof(arr1) / sizeof(arr1[0])-1;
	int sz2 = sizeof(arr2) / sizeof(arr2[0])-1;
	My_strcpy(arr1, arr2,sz1,sz2);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
}