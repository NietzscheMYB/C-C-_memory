#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//struct mooncake{
//	double store;//库存量
//	double sell;//总售价
//	double price;//单价
//}cake[1010];
//
//bool cmp(mooncake a, mooncake b)
//{
//	return a.price > b.price;
//}
//
//void test1()
//{
//	int n;
//	double D;
//	cin >> n >> D;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> cake[i].store;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> cake[i].sell;
//		cake[i].price = cake[i].sell / cake[i].store;
//	}
//	sort(cake, cake + n, cmp);
//	double ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (cake[i].store <= D)
//		{
//			D -= cake[i].store;
//			ans += cake[i].sell;
//		}
//		else{
//			ans += cake[i].price*D;//卖出剩余月饼！
//			break;
//		}
//	}
//	//cout << ans << endl;
//	printf("%.2f\n", ans);
//	//return 0;
//}
//
//void test2()
//{
//	int count[10];//记录数字0~9个数
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> count[i];
//	}
//	//从1~9中选择count不为0的最小数字
//	for (int i = 1; i < 10; i++)
//	{
//		if (count[i]>0)
//		{
//			count[i]--;
//			cout << i;
//			break;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = count[i]; j != 0; j--)
//		{
//			cout << i;
//		}
//	}
//}



const int maxn = 110;
struct Inteval
{
	int x, y;//开区间左右端点
}I[maxn];

bool cmp(Inteval a, Inteval b)
{
	if (a.x != b.x)
	{
		return a.x > b.x;//先按左端点从大到小排序
	}
	else{
		return a.y < b.y;//左端点相同的按右端点从小到大排序
	}
}

void test3()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> I[i].x >> I[i].y;
	}
	sort(I, I + n, cmp);//区间排序
	//ans记录不相交区间个数，lastx记录上一个被选中区间的左端点
	int ans = 1, lastx = I[0].x;
	for (int i = 1; i < n; i++)
	{
		if (I[i].y <= lastx)
		{
			lastx = I[i].x;
			ans++;
		}
	}
	cout << ans << endl;

}



int main()
{
	//test2();
	return 0;
}