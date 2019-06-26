#include"Menu.h"


void MainMenu()
{
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("*****************欢迎使用电话号码系统*****************\n");
	printf("***********************1.进入*************************\n");
	printf("***********************2.退出*************************\n");
	printf("******************************************************\n");
	printf("******************************************************\n");

}
void ViceMenu()
{

	printf("******************************************************\n");
	printf("*******************1.创建信息表***********************\n");
	printf("*******************2.显示信息表***********************\n");
	printf("*******************3.查找个人信息*********************\n");
	printf("*******************4.删除个人信息*********************\n");
	printf("*******************5.录入个人信息*********************\n");
	printf("*******************6.销毁信息表***********************\n");
	printf("*******************7.退出*****************************\n");
	printf("******************************************************\n");

}

void Function()
{
	printf("请选择->");
	HT ht;
	int key2 = 0;
	while (1)
	{
		scanf("%d", &key2);
		switch (key2)
		{
		case 1:{
				   printf("信息表创建成功！\n");
				   //ContactInit(&ct);
				   HashTableInit(&ht, MAX_CAPACITY, 1);
				   ViceMenu();
		}
			break;
		case 2:
		{
				  Show(&ht);
				  ViceMenu();
		}
			break;
		case 3:
		{
				  printf("请输入要查找人的电话号码->");
				  People x;
				  scanf("%s", &x.tel);
				  HashTableFind(&ht, x);
				  ViceMenu();
		}
			break;
		case 4:
		{
				  printf("请输入要删除人的电话号->");
				  People x;
				  scanf("%s", &x.tel);
				  HashTableDelete(&ht, x);
				  ViceMenu();
		}
			break;
		case 5:
		{
				  printf("请输入个人信息\n");
				  const  People x;
				  printf("请输入姓名->");
				  scanf("%s", &x.name);
				  printf("请输入电话号码->");
				  scanf("%s", &x.tel);
				  printf("请输入地址->");
				  scanf("%s", &x.addr);
				  HashTableInsert(&ht, x);
				  ViceMenu();
		}
			break;
		case 6:
		{
				  printf("销毁成功！\n");
				  HashTableDestroy(&ht);
		}
			break;
		case 7:
		{
				  save(&ht);
				  return;
		}
			break;
		default:
		{
				   printf("输入错误请重新输入->");
				   //ViceMenu();
		}
			break;
		}
	}

}
void Start()
{
	MainMenu();
	int key1 = 0;
	while (1)
	{
		printf("请选择->");
		scanf("%d", &key1);
		switch (key1)
		{
		case 1:
		{
				  system("cls");  ViceMenu(); Function(); MainMenu();
		}
			break;
		case 2:
		{
				  system("cls");  printf("再见！\n");
				  return;
		}
			break;
		default:
		{
				   printf("输入错误请重新输入");
		}
			break;
		}
	}


}