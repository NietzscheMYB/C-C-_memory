#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include<math.h>
using namespace std;
#define n 10
#define x1 5  //分治的规模
int b[100][2];
int count;
int source[100];
double sum = 0;
double min = 5000;
void Init0(int arr[n][n])
{
	srand(time(NULL));
	int xx[n][2];
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < 2; j++)
		{
			b[i][j]=xx[i][j] = rand() % 10 + 1;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j>i) arr[i][j] = sqrt(xx[j][0]*xx[j][1]+xx[i][0]*xx[i][0]);
			else if (i>j) arr[i][j] = arr[j][i];
			//	else arr[i][j] = rand() % 3 + 1;
			if (i == j)
			{
				arr[i][j] = 100;
			}
		}
	}
}


void Init(int arr[n][n])
{
	srand(time(NULL));
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j>i) arr[i][j] = rand() % 10 + 1;
			else if (i>j) arr[i][j] = arr[j][i];
		//	else arr[i][j] = rand() % 3 + 1;
			if (i == j)
			{
				arr[i][j] = 100;
			}
		}
	}
}



int tx(int D[n][n])
{
	int S[n];//用于存储已访问过的城市
	S[0] = 0;
	int i=1, j=0, k=0, l=0,flag=0;
	int sumx = 0;//用于记算已访问过的城市的最小路径长度
	int Dtemp = 0;//保证Dtemp比任意两个城市之间的距离都大（其实在算法描述中更准确的应为无穷大）
	do{
		k = 1; Dtemp = 10000;
		do{
			l = 0; flag = 0;
			do{
				if (S[l] == k){//判断该城市是否已被访问过，若被访问过，
					flag = 1;//则flag为1
					break;//跳出循环，不参与距离的比较
				}
				else
					l++;
			} while (l < i);
			if (flag == 0 && D[k][S[i - 1]] < Dtemp){/*D[k][S[i - 1]]表示当前未被访问的城市k与上一个已访问过的城市i-1之间的距离*/
				j = k;//j用于存储已访问过的城市k
				Dtemp = D[k][S[i - 1]];//Dtemp用于暂时存储当前最小路径的值
			}
			k++;
		} while (k < n);
		S[i] = j;//将已访问过的城市j存入到S[i]中
		i++;
		sumx += Dtemp;//求出各城市之间的最短距离，注意：在结束循环时，该旅行商尚未回到原出发的城市
	} while (i < n);
	//sum += D[0][j];//D[0][j]为旅行商所在的最后一个城市与原出发的城市之间的距离
	for (j = 0; j < n; j++){ //输出经过的城市的路径
		cout << S[j] << " ";
	}
	return sumx;
}

int fz(int D[n][n])
{
	//分成两部分
	int arr1[n][n];
	int arr2[n][n ];
	int i = 0, j = 0,k=0,l=0;

	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j>i) arr1[i][j] = 100;
			else if (i>j) arr1[i][j] = arr1[j][i];
			else arr1[i][j] = 100;
			if (i == j)
			{
				arr1[i][j] = 100;
			}
		}
	}

	for (i = 0; i < x1; i++)
	{
		for (j = 0; j < x1; j++)
		{
			arr1[i][j] = D[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j>i) arr2[i][j] = 100;
			else if (i>j) arr2[i][j] = arr2[j][i];
			else arr2[i][j] = 100;
			if (i == j)
			{
				arr2[i][j] = 100;
			}
		}
	}


	for (i = 0, k =  x1-2; i < n&&k<n; i++, k++)
	{
		for (j = 0, l =  x1-2; j < n&&l<n; j++, l++)
		{

			arr2[i][j] = D[k][l];

		}
	}
	int sum1=tx(arr1)-x1*100;
	cout << endl;

	int sum2 = tx(arr2)-(n-x1-2)*100;

	/*cout << endl;
	for (i = 0; i<n; ++i)
	{
		for (j = 0; j < n; ++j)
			printf("%4d", arr1[i][j]);
		printf("\n");
	}

	cout << endl;
	for (i = 0; i<n; ++i)
	{
		for (j = 0; j < n; ++j)
			printf("%4d", arr2[i][j]);
		printf("\n");
	}*/
	cout << endl;

	cout << "sum1=" << sum1 << endl;
	cout << "sum2=" << sum2 << endl;
	cout << "分治后最短路径为" << sum1+sum2 << endl;
	return i;
}



void Swap(int *lhs, int *rhs)
{
	int t = *lhs;
	*lhs = *rhs;
	*rhs = t;
}

void distance()
{
	sum = 0;
	for (int i = 0; i<n; i++)
	{

		sum += sqrt((b[source[i + 1]][0] - b[source[i]][0])*(b[source[i + 1]][0] - b[source[i]][0]) + (b[source[i + 1]][1] - b[source[i]][1])*(b[source[i + 1]][1] - b[source[i]][1]));

	}

}
void FullPermutation(int source[], int begin, int end)
{
	int i;

	if (begin >= end)
	{
		distance();

		/*for (i = 0; i < count; i++)
		{
		printf("%d", source[i]);
		}
		printf("  %lf ",sum);*/
		if (sum<min){
			min = sum;
		}
		//	printf("\n");
	}
	else
	{
		for (i = begin; i < end; i++)
		{
			if (begin != i)
			{
				Swap(&source[begin], &source[i]); // ??
			}


			FullPermutation(source, begin + 1, end);

			if (begin != i)
			{
				Swap(&source[begin], &source[i]);
			}
		}
	}
}



int main()
{
	int i, j, k, l;
	int D[n][n];//用于存储两个城市之间的距离
	Init0(D);

	for (i = 0; i<n; ++i)
	{
		for (j = 0; j < n; ++j)
			printf("%4d", D[i][j]);
		printf("\n");
	}

	sum=tx(D); //贪心算法
	cout << "\n贪心结果为" << sum << endl;//求出最短路径的值

	//分治
	int xx = fz(D);

	for (i = 0; i < n; i++)
	{
		source[i] = i;
	}

	FullPermutation(source, 1, n - 1);
	printf("穷举法最短为%d\n", (int)min);
	return 0;
		
	
}
