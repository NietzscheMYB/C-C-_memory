#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void menu()
{
	printf("****************************\n");
	printf("********1.��Ϸ��ʼ**********\n");
	printf("********0.��Ϸ�˳�**********\n");
	printf("****************************\n");
}


void game()
{
	 	//int input=0;
	 	int my_mind=0;
	 	int practice=0;
	 	int flag=1;
	 	practice=rand()%100+1; //rand�����ķ���ֵΪ�������ֵ����Χ��0����RAND_MAX(RAND_MAX������stdlib.h,��ֵΪ2147473647)
		 //�ڵ� �ô˺���֮ǰ ����������srand�������ú�����������ӡ����δ������������ӣ�ϵͳĬ��Ϊ���������Ϊ1��ʹ��ÿ�����г���������������һ�� 
	 	while(flag)
		 {
		   printf("��������Ĵ�>:");
	 	   scanf("%d",&my_mind);
	 	   if(my_mind>practice)
	 	    {
	 	    	printf("�´���\n");
		    }
		     if(my_mind<practice){
		    	printf("��С��\n"); 
			}
			if(my_mind==practice)
			{
				printf("��ϲ��¶��ˣ�\n");
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
		printf("��ѡ��>:");
		scanf("%d",&input);
		switch(input)
		{	
		    case 1:game();
				break;
			case 0:
				break;
			default:printf("ѡ�����������ѡ��\n");
				break;
			}
	}while(input);
	return 0;
 } 
