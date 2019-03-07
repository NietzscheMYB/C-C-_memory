//X ������һ���ع����⡣�� n x m �����ӵľ���ÿ�����ӷ�һ��������ÿ���������ż�ֵ��ǩ��
//�ع�����������Ͻǣ����������½ǡ�
//С���������ع�����ڣ�����Ҫ����ֻ�����һ��������ߡ�
//�߹�ĳ������ʱ������Ǹ������еı�����ֵ��С���������ⱦ����ֵ����С���Ϳ�������������Ȼ��Ҳ���Բ��ã���
//��С���ߵ�����ʱ����������еı���ǡ����k��������Щ�����Ϳ����͸�С����
//�����С����һ�㣬�ڸ����ľ����£����ж����ֲ�ͬ���ж������ܻ����k��������
//�����ݸ�ʽ��
//����һ��3���������ÿո�ֿ���n m k(1 <= n, m <= 50, 1 <= k <= 12)
//�������� n �����ݣ�ÿ���� m ������ Ci(0 <= Ci <= 12)������������ϵı���ļ�ֵ
//Ҫ�����һ����������ʾ����ȡk���������ж��������������ֿ��ܴܺ�������� 1000000007 ȡģ�Ľ����
//���磬���룺
//2 2 2
//1 2
//2 1
//����Ӧ�������
//2
//�����磬���룺
//2 3 2
//1 2 3
//2 1 5
//����Ӧ�������
//14


#include <iostream>
#include <cstring>
using namespace std;
int arr[50][50] = { 0 };
int n, m, k;
int count = 0;
//int ans = 0;
int MOD = 1000000007;
//void dfs(int x, int y, int max, int count)    //�����������
//{
//	if (x == n || y == m)
//	{
//		return;
//	}
//	int cur = arr[x][y];
//	if (x == n - 1 && y == m - 1) //�����յ�
//	{
//		if (count == k)
//		{
//			ans++;
//			if (ans > MOD)
//			{
//				ans %= MOD;
//			}
//
//		}
//		if (count == k - 1&&cur>max)
//		{
//			ans++;
//			if (ans > MOD)
//			{
//				ans %= MOD;
//			}
//		}
//	}
//
//	if (cur > max) //�ñ���
//	{
//		dfs(x + 1, y, cur, count + 1);
//		dfs(x, y + 1, cur, count + 1);
//	}
//	//�����ñ�������cur<max
//	dfs(x + 1, y, max, count );
//	dfs(x, y + 1, max, count );
//}
long long cachae[50][50][14][13];

long long dp(int x, int y, int max, int count)//��̬�滮 �����Եݹ�
{
	if (cachae[x][y][max+1][count] != -1)
	{
		return cachae[x][y][max + 1][count];
	}
	if (x == n || y == m)
	{
		return 0;
	}
	
	
	long long  ans = 0;
	int cur = arr[x][y];
	if (x == n - 1 && y == m - 1)   //�������һ��Ϊ��
	{
		if (count == k)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return ans;
		}
		if (count == k - 1 && cur > max)
		{
			ans++;
			if (ans > MOD)
			{
				ans %= MOD;
			}
			return ans;
		}
	}
	
	if (cur > max)             //��ǰλ�ñ����� ����
	{
		ans+=dp(x + 1, y, cur, count + 1);
		ans+=dp(x, y + 1, cur, count + 1);
	}
	//�����ñ��� ���� λ�ñ�����ֵС
	ans+=dp(x + 1, y, max, count);
	ans+=dp(x, y + 1, max, count);
	cachae[x][y][max+1][count] = ans%MOD;
	return ans;

}
int main()
{
	cin >> n;
	cin >> m;
	cin >> k;
	int i = 0,j=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(cachae, -1, sizeof(cachae));
	cout <<dp(0, 0, -1, 0)<< endl;
}