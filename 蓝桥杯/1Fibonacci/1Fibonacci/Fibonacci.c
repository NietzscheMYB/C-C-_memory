//#include <stdio.h>
//#include <Windows.h>
#pragma warning(disable:4996)
//#define MAXN 1000
//int main()
//{
//	int n = 0;
//	int i;
//	int Fib[MAXN];
//	Fib[1] = 1;
//	Fib[2] = 1;
//	scanf("%d", &n);
//	for (i = 3; i < MAXN; i++)
//	{
//		Fib[i] = (Fib[i - 1] + Fib[i - 2])%10007;
//	}
//	printf("%d\n",Fib[n]);
//	system("pause");
//	return 0;
//}

#include <stdlib.h>
#include <stdio.h>
#define MOD 10007
#define MAXN 1000001
int n, i, F[MAXN];
int main()
{
	scanf("%d", &n);
	F[1] = 1;
	F[2] = 1;
	for (i = 3; i <= n; ++i)
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	printf("%d\n", F[n]);
	return 0;
}
