//求部分和 或前缀和的需求
//1.前缀和数组（静态数据）
//预处理方式 新建一个数组
//存原始数据的累加！！！


//2.数据有更改情况
//树状数组重要
//每次去更新原始a数组  树状数组c
//Ck的含义是某个区间的和[k-lowbit(k),k]
//lowbit(k)是k二进制中最后一个1代表的整数
//例如lowbit(6) -》2
//C6  sum(4,6]  从6包含6向后推进2个


//index 处改动  index+lowbit(index)
//101->110 动5会影响6！！
//110->1000动6影响8    还是第一个二进制1代表的数


//C1 C3  C5 ！  奇数向只包含它自己往前推进一位 //a1移动影响c1
//C6
//2的幂 囊括多少

//S10=c10+c8

//4~6=getsum(6)-getsum(4)


#include <iostream>
using namespace std;

int lowbit(int n)
{
	return n - (n&(n - 1));
}
//原始数组i的位置增加v后 跟新c数组  n是边界
void updata(int n,int i, int v, int c[])
{
	//int lb = lowbit(i);
	for (int k = i; k <= n; k += lowbit(k))
	{
		c[k] += v;
	}
}

//算前几项之和
int getSum(int c[], int i)
{
	int sum = 0;
	for (int k = i; k >= 1; k -= lowbit(k))
	{
		sum += c[k];
	}
	return sum;
}


//题目
//for对每一位
//for(右侧更小

//1.h对于数状数组的下标
//2.按顺序为身高计数
//如3 加入a[3]=1，此时统计
//sum3=1,证明<=3的身高数+1，1-1=0，说明此前加入比3大的个数为0
int main()
{
	int n;
	scanf("%d", &n);

}