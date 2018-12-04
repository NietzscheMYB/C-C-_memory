/*因为是高精度加法 所以必须用到数组 将每一位存 到数组里 准备5个数组 先向2个数组里存放数字，并计算两个数组 的长度，因为要相加有进位的现象，所以最好是反的存放

将前两个数组的数字 导入另外两个数组里（倒序）*****注意两个要加的数的长度不一样！！！****

r为　　计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。


将所加的值存放在最后一个数组
*/

#include "stdio.h"
#include "string.h"


int main()
{
	char m[100], n[100];
	int i, len_m, len_n, len_max, r;
	int a[100] = { 0 }, b[100] = { 0 }, c[500] = { 0 };
	gets(m);
	gets(n);
	len_m = strlen(m);
	len_n = strlen(n);
	for (i = 0; i <= len_m - 1; i++)
		a[i] = m[len_m - 1 - i] - '0';
	for (i = 0; i <= len_n - 1; i++)
		b[i] = n[len_n - 1 - i] - '0';
	if (len_m>len_n)
		len_max = len_m;
	else
		len_max = len_n;
	r = 0;
	for (i = 0; i <= len_max - 1; i++)
	{
		c[i] = (a[i] + b[i] + r) % 10;
		r = (a[i] + b[i] + r) / 10;
	}
	if (r != 0)  c[len_max] = 1; //两个最高位相加会有溢出 
	if (c[len_max] == 1) printf("1");
	for (i = len_max - 1; i >= 0; i--)
		printf("%d", c[i]);
	return 0;
}
