#include <stdio.h>
#include <assert.h>
void Exchange(int arr[], int sz)
{
	assert(arr);
	assert(sz > 0);
	int start = 0;
	int end = sz - 1;
	while (start<end){
		while ((start>end)&&(arr[start] & 1) == 1){
			start++;
		}
		while ((end<start)&&(arr[end]) & 1 == 0){
			end--;
		}
		if (start < end)
		{arr[start] ^= arr[end];
		arr[end] ^= arr[start];
		arr[start] ^= arr[end];
		start++;
		end--;
		}
		
	}
	return;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Exchange(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}