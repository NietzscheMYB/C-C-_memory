#include "stdio.h"

int main()
{
	int i,key=0;
	int mid=0;
	int arr[10];
	int left,right;
	left=0;
	right=sizeof(arr)/sizeof(arr[0])-1;
	for(i=0;i<10;i++)
	{
		arr[i]=i;
	}
	printf("������Ҫ���ҵ�ֵ��");
	scanf("%d",&key); 
	while(left<=right)
	{
		mid=(left+right)/2;
		if(arr[mid]>key) 
		{
			right=mid-1;
		}
		if(arr[mid]<key)
		{
			left=mid+1;
		}
		if(arr[mid]==key)
		{
			printf("�ҵ���!\n");
			break;
		}

	}
	
	if(right<left)
	{
	
		printf("-1\nû�ҵ�");
	}
		
	
	return 0;

}
