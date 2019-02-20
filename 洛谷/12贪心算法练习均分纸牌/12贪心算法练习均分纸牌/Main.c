#include <stdio.h>
#pragma warning(disable:4996)
int count(int arr[], int size,int ave)
{
	int i = 0,count=0,k=0;
	for (i = 0; i < size; i++)
	{
		////k = 0;
		//if (arr[i] < ave)
		//{
		//	k = ave - arr[i];
		//	if (k>arr[i + 1])
		//	{
		//		arr[i] += arr[i + 1];
		//		count++;
		//		continue;
		//	}
		//	arr[i] += k;
		//	arr[i + 1]= arr[i+1]-k;
		//	count++;
		//	continue;
		//}
		//if (arr[i] == ave)
		//{
		//	continue;
		//}
		//if (arr[i]>ave)
		//{
		//	k = arr[i] - ave;
		//	arr[i] = arr[i] - k;
		//	arr[i + 1] += k;
		//	count++;
		//}
		if (arr[i] == ave)
		{
			continue;
		}
		else
		{
			arr[i + 1] += arr[i] - ave;    //arr[i] - ave值的正负一起处理！
			count++;
		}


	}
	return count;
}
int main()
{
	int n;
	scanf("%d", &n);
	int arr[100] = {0};
	int i = 0, sum = 0, step = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int ave = sum / n;
	step = count(arr, n, ave);
	printf("%d\n",step);
	return 0;
}