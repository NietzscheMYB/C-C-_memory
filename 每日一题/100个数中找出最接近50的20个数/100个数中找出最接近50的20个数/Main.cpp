#include<iostream>
#include<queue>
#include<time.h>
#include<cstdio>
#include<functional>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//���²���
	int arr[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 100;//rand �������������α�������������������Ǹ���һ����ֵ(���ǳ�֮Ϊ����)������һ���ĺ���ʽ���������
		//���Ӻ������֮�������̫�ֲ�
		//ÿ�μ���������������������ǲ�һ���ģ����Ǽ����һ��������rand()���������������ȷ����
		//������Ҫsrand�������²��֣���Ϊʱ����ʱʱ�̷̿����仯������������time��Ϊ����
	}
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] - 50>0)
		{
			q.push(arr[i]);
		}
	}
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}

}