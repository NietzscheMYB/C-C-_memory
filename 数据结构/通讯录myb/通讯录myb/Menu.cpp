#include"Menu.h"


void MainMenu()
{
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("*****************欢迎使用通讯录系统*******************\n");
	printf("***********************1.进入*************************\n");
	printf("***********************2.退出*************************\n");
	printf("******************************************************\n");
	printf("******************************************************\n");

}
void ViceMenu()
{
	
	printf("******************************************************\n");
	printf("*******************1.创建通讯录***********************\n");
	printf("*******************2.显示通讯录信息*******************\n");
	printf("*******************3.查找个人信息*********************\n");
	printf("*******************4.删除个人信息*********************\n");
	printf("*******************5.录入个人信息*********************\n");
	printf("*******************6.销毁通讯录***********************\n");
	printf("*******************7.退出*****************************\n");
	printf("******************************************************\n");

}

void Function()
{
	printf("请选择->");
	Contact ct;
	int key2 = 0;
	while (1)
	{
		scanf("%d", &key2);
		switch (key2)
		{
		case 1:{
				   printf("通讯录创建成功！\n");
				   ContactInit(&ct);
				   ViceMenu();
		}
			break;
		case 2:
		{
				  ContactShow(&ct);
				  ViceMenu();
		}
			break;
		case 3:
		{
				  printf("请输入要查找人的姓名->");
				  char name[10];
				  scanf("%s",&name);
				  ContactSearch(&ct, name);
				  ViceMenu();
		}
			break;
		case 4:
		{
				  printf("请输入要删除人的姓名->");
				  char name[10];
				  scanf("%s",&name);
				  ContactDelete(&ct, name);
				  printf("删除成功！\n");
				  ViceMenu();
		}
			break;
		case 5:
		{
				  printf("请输入个人信息\n");
				const  People p;
				  printf("请输入姓名->");
				  scanf("%s", &p.Name);
				  printf("请输入街道->");
				  scanf("%s", &p.Street);
				  printf("请输入城市->");
				  scanf("%s", &p.City);
				  printf("请输入邮政->");
				  scanf("%s", &p.Eip);
				  printf("请输入国家->");
				  scanf("%s", &p.State);
				  ContactAdd(&ct,p);
				  ViceMenu();
		}
			break;
		case 6:
		{
				  printf("通讯录销毁成功！\n");
				  ContactDestroy(&ct);
		}
			break;
		case 7:
		{
				  save(&ct);
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