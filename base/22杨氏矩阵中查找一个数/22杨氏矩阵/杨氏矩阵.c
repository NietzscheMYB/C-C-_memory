#include <stdio.h>
void Find_data(int arr[][4],int sz,int data)
{
	int row = 0;
	int lin = sz-1;
	while ((0<row<4) && (4>lin>0))
	{
		if (data < arr[row][lin])
		{
			lin--;
		}
		if (data>arr[row][lin])
		{
			row++;
		}
		if (data == arr[row][lin])
		{
			printf("data : %d\n", data);
			printf("row=%d lin=%d\n", row+1, lin+1);
			break;
		}
	}
}
int main()
{
	int arr[][4] = { 1,2,3,4,2,3,4,5,3,4,5,6,4,5,6,7 };
	int sz = sizeof(arr)/sizeof(arr[1]);
	int data = 2;
	data = 3;
	Find_data(arr,sz,data);
	return 0;
}