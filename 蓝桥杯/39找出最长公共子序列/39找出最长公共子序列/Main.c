//#include <stdio.h>
//#pragma warning(disable:4996)
//#include <string.h>
//int main()
//{
//	char arr1[1000] = { '0' };
//	char arr2[1000] = { '0' };
//	int k = 0;
//	scanf("%d", &k);
//	scanf("%s", &arr1);
//	scanf("%s", &arr2);
//	int len1 = strlen(arr1), len2 = strlen(arr2);
//	int i = 0, j = 0,count=0,flag=0;
//	if (len1 < len2)
//	{
//		for (i = 0; i < len1; i++)
//		{
//			for (j = flag; j < len2; j++)
//			{
//				j = flag + 1;
//				if (arr1[i] == arr2[j])
//				{
//					count++;
//					flag = j+1;
//					break;
//				}
//			}
//		}
//		printf("%d\n", count);
//		return 0;
//	}
//	if (len1 >=len2)
//	{
//		for (i = 0; i < len2; i++)
//		{
//			for (j = flag; j < len1; j++)
//			{
//				j = flag + 1;
//				if (arr2[i] == arr1[j])
//				{
//					count++;
//					flag = j + 1;
//					break;
//				}
//			}
//		}
//		printf("%d\n", count);
//		return 0;
//	}
//
//}

#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int k = 0,count=0,j=0,flag=0;
	scanf("%d", &k);
	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };
	int i = 0;
	for (i = 0; i < k; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < k; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (i = 0; i < k; i++)
	{
			for (j = flag; j < k; j++)
			{
			
				if (arr2[i] == arr1[j])
				{
					count++;
					flag = j + 1;
					break;
				}
			}
	}
	printf("%d\n", count);
	return 0;
			
}