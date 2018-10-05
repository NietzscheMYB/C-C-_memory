#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void menu()
{
	printf("****************************\n");
	printf("********1.游戏开始**********\n");
	printf("********0.游戏退出**********\n");
	printf("****************************\n");
}


void game()
{
	 	//int input=0;
	 	int my_mind=0;
	 	int practice=0;
	 	int flag=1;
	 	practice=rand()%100+1; //rand（）的返回值为以随机数值，范围在0——RAND_MAX(RAND_MAX定义在stdlib.h,其值为2147473647)
		 //在调 用此函数之前 必须先利用srand（）设置好随机数的种子。如果未设置随机数种子，系统默认为随机数种子为1，使得每次运行程序产生的随机数都一样 
	 	while(flag)
		 {
		   printf("请输入你的答案>:");
	 	   scanf("%d",&my_mind);
	 	   if(my_mind>practice)
	 	    {
	 	    	printf("猜大了\n");
		    }
		     if(my_mind<practice){
		    	printf("猜小了\n"); 
			}
			if(my_mind==practice)
			{
				printf("恭喜你猜对了！\n");
				flag=0;
			 } 
		 }
}



int main()
{
    srand((unsigned)time(NULL));   
	int input=0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch(input)
		{	
		    case 1:game();
				break;
			case 0:
				break;
			default:printf("选择错误请重新选择\n");
				break;
			}
	}while(input);
	return 0;
 } 
