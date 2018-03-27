/*#include <stdio.h>
#define weishu 4000
int main()
 {
  int cun[weishu]={0};
  int a, b;
  int zhishu, dishu;
  for (a = 0; a < weishu; a++)
    cun[a] = 0 ;
  cun[weishu - 1] = 1;
  printf("输入底数:");
  scanf("%d", &dishu);
  printf("输入指数:");
  scanf("%d", &zhishu);

 for (b = 0; b < zhishu; b++) 
 {
      for (a = weishu - 1; a >= 0; a--) 
        cun[a] *= dishu;
      for (a = weishu - 1; a >= 0; a--)
        if (cun[a] >=10)
		{
          cun[a - 1] += cun[a] / 10;
          cun[a] %= 10;
        }
    }
 
  for (a = 0; a < weishu; a++)
    if (cun[a] != 0)
      break;
  for (a; a < weishu; a++)
    printf("%d", cun[a]);
}	*/

/*****计算13的N次幂*****/

#include <stdio.h>

#define N 1000

int main()
{
	int a[N];
	int s,i,j,x,cp,M;
	printf ("请输入指数大小：\n");
	scanf ("%d",&M);
	a[N-1]=1;
	s=N-2;
	for (i=1;i<M+1;i++)
	{
		cp=0;
		for (j=N-1;j>s;j--)
		{
			x=a[j]*13+cp;
			a[j]=x%10;
			cp=x/10;
		}
		/*a[s--]=cp;此处有可能溢出，需要处理*/ 
		
		//升华代码
		while (cp)
		{
			a[s--]=cp%10;
			cp=cp/10;
		}
		//升华代码
		
	}
	for (j=s+1;j<N;j++)
		printf ("%d",a[j]);
	return 0;
}

