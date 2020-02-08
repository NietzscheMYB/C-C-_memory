#include<iostream>
using namespace std;
const int N = 110;
int father[N];//��Ÿ��׽ڵ�
bool isRoot[N];//ͳ�Ƹ��ڵ�ĸ���


int findFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}

	//·��ѹ��
	while (a != father[a])
	{
		int k = a;
		a = father[a];
		father[k] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		father[faA] = faB;
		
	}
}
void Init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	Init(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] == true)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
