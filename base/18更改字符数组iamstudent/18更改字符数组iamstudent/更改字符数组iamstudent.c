//#include <stdio.h>
//int my_stlen(char arr[])
//{
//	int count = 0;
//	int i = 0;
//	while (arr[i++] != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//void swap(char arr[],int count)
//{
//	int i = 0,j=0;
//	while (i >= 0)
//{	
//	for (i = count; i >= 0; i--)
//	{
//		if (arr[i] == ' ')
//		{		
//			break;
//		}
//	}
//	for (j = i+1; j <=count; j++)
//	{
//		printf("%c", arr[j]);
//	}
//	printf(" ");
//	count = i-1 ;
//}
//	
//}
//int main()
//{
////	char arr[] = { "student a am i" };
//	char arr[] = {"smaller getting are rooms The" }; 
//	int i, j;
//	int len;
//	len=my_stlen(arr);
//	swap(arr,len);
//	printf("\n");
//
//}
//******************************************************************8

/***字符串反转函数！！！！！
字符串跳出while \0！！！！！

这个题目是改变数组本身！！！！

student a am i
先换成
tenduts a ma i  局部反转
再换成
i am a student  整体反转
***/
#include <stdio.h>
#include <assert.h>

void ReverseString(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		/**start = *start^*end;
		*end = *start^*end;
		*start = *start^*end;*/
		start++;
		end--;
	}
}
void ChangeString(char arr[])
{ 
	assert(arr);
	char *p=arr;
	char *q=p;
	while (*p)     //用字符串\0作为跳出条件
	{
		if (*p == ' ')
		{
			ReverseString(q, p - 1);
			p++;
			q = p;
		}
		p++;
	}
	ReverseString(q, p - 1);
	ReverseString(arr, p - 1);
}
int main()
{
	char arr[] = { "student a am i" };
	printf("before : %s\n", arr);
	ChangeString(arr);
	printf("after : %s\n", arr);
	return 0;
}