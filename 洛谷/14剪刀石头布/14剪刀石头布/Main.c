#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr1[200], arr2[200];
	int n,n1,n2;
	scanf("%d %d %d", &n,&n1,&n2);
	//scanf("%d", &n1);
	//scanf("%d", &n2);
	
	int i = 0,j=0,sum1=0,sum2=0;
	
	int result[5][5] = {
		2,0,1,1,0,
		1,2,0,1,0,
		0,1,2,0,1,
		0,0,1,2,1,
		1,1,0,0,2
	};
	for (i = 0; i < n1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &arr2[i]);
	}
	i = 0, j = 0;
	while (n--)
	{
		if (result[arr1[i]][arr2[j]])
		{
			if (result[arr1[i]][arr2[j]] == 2)
			{
				i++;
				j++;
				if (i == n1)
				{
					i = 0;
				}
				if (j == n2)
				{
					j = 0;
				}
				continue;
			}
			else
			{
				sum1++;
			}
		}
		else
		{
			sum2++;
		}
		i++; 
		j++;
		if (i == n1)
		{
			i = 0;
		}
		if (j == n2)
		{
			j = 0;
		}
	}
	printf("%d %d\n", sum1, sum2);
	return 0;

}