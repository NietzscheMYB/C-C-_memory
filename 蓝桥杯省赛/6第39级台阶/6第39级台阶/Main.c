//小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级!
//
//站在台阶前，他突然又想着一个问题：
//如果我每一步只能迈上1个或2个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？
//请你利用计算机的优势，帮助小明寻找答案。


#include <stdio.h>
int count = 0;
void f(int n, int step)
{
	if (n < 0)
	{
		return;
	}
	if (n == 0&&step%2==0)     //n=0说明已经走完了，，，count++即可
	{
		count++;
		return;
	}
	f(n - 1, step+1);
	f(n - 2, step+1);
}
int main()
{
	int n = 39;
	int step = 0;
	f(n, step);
	printf("%d\n", count);
}