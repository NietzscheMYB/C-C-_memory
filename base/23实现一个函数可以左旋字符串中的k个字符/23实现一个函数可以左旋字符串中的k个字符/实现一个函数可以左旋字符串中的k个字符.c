#include <stdio.h>
#include <string.h>
#include <assert.h>
void Left_Move(char arr[], int len, int step)
{
	assert(arr);
	assert(len >0);
	assert(step >= 0);

	int num = step%len;
	while (num--){
		int temp = arr[0];
		int i;
		for (i = 1; i < len; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[i - 1] = temp;
	}
	printf("after : %s\n", arr);
}

void ReverseString(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start<end){
		*start ^= *end;
			*end ^= *start;
			*start ^= *end;
			start++;
			end--;
	}
}
int main()
{
	char arr[] = { "abcd1234" };
	printf("before : %s", arr);
	printf("\n请输入要旋转的次数>");
	int step;
	scanf("%d", &step);
	int len = strlen(arr);
	Left_Move(arr,len, step);
}


//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//int Judge_string(char arr1[], char arr2[], int sz1, int sz2)
//{
//	assert(arr1);
//	assert(arr2);
//	int temp, i;
//	int flag = 0;
//	while (sz2--)
//	{
//		temp = arr2[0];
//		for (i = 1; i < sz2; i++)
//		{
//			arr2[i - 1] = arr2[i];
//		}
//		arr2[i - 1] = temp;
//		/*for (i = 0; i < sz1; i++)
//		{
//		if (arr1[i] == arr2[i])
//
//		}*/
//		if (strncmp(arr1, arr2, sz1) == 0)
//		{
//			flag++;
//		}
//	}
//
//	if (flag > 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	char arr1[] = { "ABCDabc123" };
//	char arr2[] = { "abc123ABCD" };
//	int sz1 = strlen(arr1);
//	int sz2 = strlen(arr2);
//	printf("%s\n", arr2);
//	int ret = 0;
//	ret = Judge_string(arr1, arr2, sz1, sz2);
//	printf("%d\n", ret);
//	return 0;
//}