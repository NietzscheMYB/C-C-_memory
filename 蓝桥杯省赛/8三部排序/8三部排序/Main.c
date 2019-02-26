#include <stdio.h>
void sort3p(int arr[], int len)
{
	int p = 0;
	int left = 0;
	int right = len-1;
	while (p <=right)
	{
		if (arr[p] < 0)
		{
			int t = arr[left];
			arr[left] = arr[p];
			arr[p] = t;
			p++;
			left++;
		}
		else if (arr[p]>0)
		{
			int t = arr[right];
			arr[right] = arr[p];
			arr[p] = t;
			right--;
		}
		else
		{
			p++;
		}
	}
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 25, 18, -2, 0, 16, -5, 33, 21, 0, 19, -16, 25, -3, 0 };
	sort3p(arr, 14);
	return 0;
}