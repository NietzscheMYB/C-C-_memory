#include"Menu.h"


void MainMenu()
{
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("*****************��ӭʹ�õ绰����ϵͳ*****************\n");
	printf("***********************1.����*************************\n");
	printf("***********************2.�˳�*************************\n");
	printf("******************************************************\n");
	printf("******************************************************\n");

}
void ViceMenu()
{

	printf("******************************************************\n");
	printf("*******************1.������Ϣ��***********************\n");
	printf("*******************2.��ʾ��Ϣ��***********************\n");
	printf("*******************3.���Ҹ�����Ϣ*********************\n");
	printf("*******************4.ɾ��������Ϣ*********************\n");
	printf("*******************5.¼�������Ϣ*********************\n");
	printf("*******************6.������Ϣ��***********************\n");
	printf("*******************7.�˳�*****************************\n");
	printf("******************************************************\n");

}

void Function()
{
	printf("��ѡ��->");
	HT ht;
	int key2 = 0;
	while (1)
	{
		scanf("%d", &key2);
		switch (key2)
		{
		case 1:{
				   printf("��Ϣ�����ɹ���\n");
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
				  printf("������Ҫ�����˵ĵ绰����->");
				  People x;
				  scanf("%s", &x.tel);
				  HashTableFind(&ht, x);
				  ViceMenu();
		}
			break;
		case 4:
		{
				  printf("������Ҫɾ���˵ĵ绰��->");
				  People x;
				  scanf("%s", &x.tel);
				  HashTableDelete(&ht, x);
				  ViceMenu();
		}
			break;
		case 5:
		{
				  printf("�����������Ϣ\n");
				  const  People x;
				  printf("����������->");
				  scanf("%s", &x.name);
				  printf("������绰����->");
				  scanf("%s", &x.tel);
				  printf("�������ַ->");
				  scanf("%s", &x.addr);
				  HashTableInsert(&ht, x);
				  ViceMenu();
		}
			break;
		case 6:
		{
				  printf("���ٳɹ���\n");
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