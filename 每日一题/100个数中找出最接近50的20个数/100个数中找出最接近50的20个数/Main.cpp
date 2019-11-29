#include<iostream>
#include<queue>
#include<time.h>
#include<cstdio>
#include<functional>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//重新播种
	int arr[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 100;//rand 产生的随机数是伪随机数，产生的随机数是根据一个数值(我们称之为种子)，按照一定的函数式子算出来，
		//种子和随机数之间服从正太分布
		//每次计算机启动，产生的种子是不一样的，但是计算机一旦启动，rand()出来的随机数就是确定的
		//所以需要srand进行重新播种，因为时间是时时刻刻发生变化，所以我们用time作为参数
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