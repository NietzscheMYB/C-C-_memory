#include"Menu.h"


void MainMenu()
{
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("*****************��ӭʹ��ͨѶ¼ϵͳ*******************\n");
	printf("***********************1.����*************************\n");
	printf("***********************2.�˳�*************************\n");
	printf("******************************************************\n");
	printf("******************************************************\n");

}
void ViceMenu()
{
	
	printf("******************************************************\n");
	printf("*******************1.����ͨѶ¼***********************\n");
	printf("*******************2.��ʾͨѶ¼��Ϣ*******************\n");
	printf("*******************3.���Ҹ�����Ϣ*********************\n");
	printf("*******************4.ɾ��������Ϣ*********************\n");
	printf("*******************5.¼�������Ϣ*********************\n");
	printf("*******************6.����ͨѶ¼***********************\n");
	printf("*******************7.�˳�*****************************\n");
	printf("******************************************************\n");

}

void Function()
{
	printf("��ѡ��->");
	Contact ct;
	int key2 = 0;
	while (1)
	{
		scanf("%d", &key2);
		switch (key2)
		{
		case 1:{
				   printf("ͨѶ¼�����ɹ���\n");
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
				  printf("������Ҫ�����˵�����->");
				  char name[10];
				  scanf("%s",&name);
				  ContactSearch(&ct, name);
				  ViceMenu();
		}
			break;
		case 4:
		{
				  printf("������Ҫɾ���˵�����->");
				  char name[10];
				  scanf("%s",&name);
				  ContactDelete(&ct, name);
				  printf("ɾ���ɹ���\n");
				  ViceMenu();
		}
			break;
		case 5:
		{
				  printf("�����������Ϣ\n");
				const  People p;
				  printf("����������->");
				  scanf("%s", &p.Name);
				  printf("������ֵ�->");
				  scanf("%s", &p.Street);
				  printf("���������->");
				  scanf("%s", &p.City);
				  printf("����������->");
				  scanf("%s", &p.Eip);
				  printf("���������->");
				  scanf("%s", &p.State);
				  ContactAdd(&ct,p);
				  ViceMenu();
		}
			break;
		case 6:
		{
				  printf("ͨѶ¼���ٳɹ���\n");
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
				   printf("�����������������->");
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
		printf("��ѡ��->");
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
				  system("cls");  printf("�ټ���\n");
				  return;
		}
			break;
		default:
		{
				   printf("�����������������");
		}
			break;
		}
	}
	
	
}