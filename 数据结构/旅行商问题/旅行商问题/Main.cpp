#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include<math.h>
using namespace std;
#define n 10
#define x1 5  //���εĹ�ģ
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
	int S[n];//���ڴ洢�ѷ��ʹ��ĳ���
	S[0] = 0;
	int i=1, j=0, k=0, l=0,flag=0;
	int sumx = 0;//���ڼ����ѷ��ʹ��ĳ��е���С·������
	int Dtemp = 0;//��֤Dtemp��������������֮��ľ��붼����ʵ���㷨�����и�׼ȷ��ӦΪ�����
	do{
		k = 1; Dtemp = 10000;
		do{
			l = 0; flag = 0;
			do{
				if (S[l] == k){//�жϸó����Ƿ��ѱ����ʹ����������ʹ���
					flag = 1;//��flagΪ1
					break;//����ѭ�������������ıȽ�
				}
				else
					l++;
			} while (l < i);
			if (flag == 0 && D[k][S[i - 1]] < Dtemp){/*D[k][S[i - 1]]��ʾ��ǰδ�����ʵĳ���k����һ���ѷ��ʹ��ĳ���i-1֮��ľ���*/
				j = k;//j���ڴ洢�ѷ��ʹ��ĳ���k
				Dtemp = D[k][S[i - 1]];//Dtemp������ʱ�洢��ǰ��С·����ֵ
			}
			k++;
		} while (k < n);
		S[i] = j;//���ѷ��ʹ��ĳ���j���뵽S[i]��
		i++;
		sumx += Dtemp;//���������֮�����̾��룬ע�⣺�ڽ���ѭ��ʱ������������δ�ص�ԭ�����ĳ���
	} while (i < n);
	//sum += D[0][j];//D[0][j]Ϊ���������ڵ����һ��������ԭ�����ĳ���֮��ľ���
	for (j = 0; j < n; j++){ //��������ĳ��е�·��
		cout << S[j] << " ";
	}
	return sumx;
}

int fz(int D[n][n])
{
	//�ֳ�������
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
	cout << "���κ����·��Ϊ" << sum1+sum2 << endl;
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
	int D[n][n];//���ڴ洢��������֮��ľ���
	Init0(D);

	for (i = 0; i<n; ++i)
	{
		for (j = 0; j < n; ++j)
			printf("%4d", D[i][j]);
		printf("\n");
	}

	sum=tx(D); //̰���㷨
	cout << "\n̰�Ľ��Ϊ" << sum << endl;//������·����ֵ

	//����
	int xx = fz(D);

	for (i = 0; i < n; i++)
	{
		source[i] = i;
	}

	FullPermutation(source, 1, n - 1);
	printf("��ٷ����Ϊ%d\n", (int)min);
	return 0;
		
	
}
