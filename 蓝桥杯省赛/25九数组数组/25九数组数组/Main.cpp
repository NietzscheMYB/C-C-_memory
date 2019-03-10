#include <stdio.h>

void test(int x[])
{
	int a = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
	int b = x[4] * 10000 + x[5] * 1000 + x[6] * 100 + x[7] * 10 + x[8];

	if (a * 3 == b) printf("%d / %d\n", a, b);
}

void f(int x[], int k)
{
	int i, t;
	if (k >= 9){
		//test(x);
		for (i = 0; i <= 9; i++)
		{
			printf("%d", x[i]);
		}
		printf("\n");
		return;
	}
	for (i = k; i<9; i++){
		{ t = x[k]; x[k] = x[i]; x[i] = t; }//交换，确定这一位
		f(x, k + 1);
		//_____________________________________________ // 填空处
		{t = x[k], x[k] = x[i], x[i] = t; }//回溯，恢复到下探之前的状态；

	}
}

int main()
{
	int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	f(x, 0);
	return 0;
}