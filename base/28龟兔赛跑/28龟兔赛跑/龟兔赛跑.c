#include "stdio.h"

int main()
{
	int l, v1, v2, t, s, s1 = 0, s2 = 0, i = 0;  //v1 v2分别表示乌龟和兔子的均匀速度，s1，s2代表乌龟和兔子走的路程
	//i表示时间
	//===========================================
	//记得赋初值！！！！ 
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	while (s1<l&&s2<l)
	{
		s1 += v1;
		s2 += v2;
		i++;
		if (s1 == l || s2 == l) break;
		if (s1 - s2 >= t)s1 -= v1*s;

	}
	if (s1>s2)
	{
		printf("R\n");
		printf("%d", i);
	}
	if (s1<s2)
	{
		printf("T\n");
		printf("%d", i);
	}
	if (s1 == s2)
	{
		printf("D\n");
		printf("%d", i);
	}
	return 0;
}


/*#include<stdio.h>
int main()
{
int v1,v2,t,s,l,s1=0,s2=0,i=0;
scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l);
while(s1<l&&s2<l)
{
s1+=v1;
s2+=v2;
i++;
if(s1==l||s2==l) break;
if(s1-s2>=t)s1-=v1*s;

}
if(s1>s2)
{
printf("R\n");
printf("%d",i);
}
if(s1<s2)
{
printf("T\n");
printf("%d",i);
}
if(s1==s2)
{
printf("D\n");
printf("%d",i);
}
return 0;
}*/
