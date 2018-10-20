#include "stdio.h"
int main()
{
	int i,j,k;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
		{
			printf("%d*%d=%d  ",j,i,i*j);
			if(i==j) {printf("\n");
			break;
			}
			
		}
	return 0;
 } 
