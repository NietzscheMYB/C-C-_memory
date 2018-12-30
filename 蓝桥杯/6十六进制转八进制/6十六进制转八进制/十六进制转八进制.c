
#pragma warning(disable:4996)


#include<stdio.h>
#include<string.h>

char h[100002], b[400002], e[1000][400002];
int main()
{
	//char h[100002], b[400002], e[1000][400002];
//	char h[100002] = { '0' }, b[400002] = { '0' }, e[1000][400002] = {'0'};
	int n;
	int q = 0;
	int k = 0,w=0;
	int flag = 0;
	scanf("%d", &n);
	while (q<n){
		scanf("%s", h);
		int i, len = 0;
		/*先把16进制化成二进制——从后往前展开 */
		for (i = strlen(h) - 1; i >= 0; i--){
			int v;
			if (h[i] >= '0' && h[i] <= '9')
				v = h[i] - '0';
			else v = h[i] - 'A' + 10;
			for (int j = 0; j<4; j++){
				b[len++] = v % 2 + '0';
				v /= 2;
			}
		}
		b[len] = '\0';
		int x = 0, cnt = 1;
		int l = 0;
		for (i = 0; i<len; i++){
			/*每三位二进制转成一位8进制,最后不足三位补0*/
			if (cnt == 4 || i == len - 1){
				x = cnt*(b[i] - '0') + x;
				cnt = 1;
				e[q][l++] = x + '0';
				x = 0;
			}
			else{
				x = cnt*(b[i] - '0') + x;
				cnt *= 2;
			}
		}
		e[q][l] = '\0';
		i = l - 1;
		while (i >= 0 && e[q][i] == '0')
			/*去掉前导0*/
			i--;
		/*if (i<0)
			printf("0");
		for (; i >= 0; i--){
			printf("%c", e[i]);
		}
		printf("\n");*/
		q++;
	}
	int len3 = 0;
	for (k = 0; k < q; k++)
	{
		for (; e[k][w] != '\0'; w++,len3++);
		
			//flag = len3-1;
			//w = w - 1;
			len3--;
			flag = len3;
			for (; len3>=0; len3--)
			{
				if (e[k][flag] =='0')
				{
					flag = 100000;//相当于解放flag
					len3--;
				}
				printf("%c", e[k][len3]);

			}
			//printf("%c", e[k][w]);

		
		w = 0;
		printf("\n");
	}
	return 0;
}