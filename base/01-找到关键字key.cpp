#include<stdio.h>
int main()
{
	int a[9]={3,2,5,8,4,7,6,9,1};
	int key;
	int i;
	printf("请输入你想找的值:");
	scanf("%d",&key);
	for(i=0;i<9;i++)
	{
		if(key==a[i]) { printf("你想找到数的位置为a[%d]值为%d",i,a[i]);break;}
		
	}
	if(i==9)
	printf("-1\n要找的值不存在\n请重新输入");
	return 0;
 } 
