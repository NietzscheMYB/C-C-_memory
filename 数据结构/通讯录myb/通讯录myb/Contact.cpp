#include"Contact.h"


//ͨѶ¼��ʼ��
void ContactInit(Contact* ct)
{
	assert(ct);

	//if (fp == NULL)
	//{
	//	ct->_arr = (People*)malloc(sizeof(People)*MAX_CAPCAITY);
	//	ct->_capacity = MAX_CAPCAITY;
	//	ct->_size = 0;
	//	return;
	//}
	//Contact x;

	//fread(&x, sizeof(x), 1, fp);
	/*memcpy(ct, &x, sizeof(x));
	fread(ct->_arr, sizeof(People)*ct->_size, 1, fp);

	fclose(fp);*/
	ct->_arr = (People*)malloc(sizeof(People)*MAX_CAPCAITY);
	ct->_capacity = MAX_CAPCAITY;
	ct->_size = 0;


	FILE *fp1 = fopen("contact.txt", "rb");  //��¼��Ϣ
	FILE *fp2 = fopen("x.txt", "rb");    //��¼size��capacity
	fread(&ct->_capacity, sizeof(int), 1, fp2);
	fread(&ct->_size, sizeof(int), 1, fp2);
	fread(ct->_arr, sizeof(People)* ct->_size, 1, fp1);

	fclose(fp1);
	fclose(fp2);

}

//����
void DealCapacity(Contact* ct)
{
	int NewCapacity = ct->_capacity * 2;
	People* arr = (People*)malloc(sizeof(NewCapacity));
	for (int i = 0; i < ct->_size; i++)
	{
		strcpy(arr[i].City, ct->_arr[i].City);
		strcpy(arr[i].Eip , ct->_arr[i].Eip);
		strcpy(arr[i].Name , ct->_arr[i].Name);
		strcpy(arr[i].State , ct->_arr[i].State);
		strcpy(arr[i].Street , ct->_arr[i].Street);
	}
	People* del = ct->_arr;
	ct->_arr = arr;
	free(del);
}
//ͨѶ¼������Ϣ
void ContactAdd(Contact* ct, People data)
{
	assert(ct);
	if (ct->_capacity == ct->_size)
	{
		DealCapacity(ct);
	}
	strcpy(ct->_arr[ct->_size].City, data.City);
	strcpy(ct->_arr[ct->_size].Eip , data.Eip);
	strcpy(ct->_arr[ct->_size].Name ,data.Name);
	strcpy(ct->_arr[ct->_size].State , data.State);
	strcpy(ct->_arr[ct->_size].Street, data.Street);
	ct->_size++;
}

//��ʾͨѶ¼
void ContactShow(Contact* ct)
{
	int i = 0;
	printf("����             �ֵ�                ����       �ʱ�        ����\n");
	for (i = 0; i < ct->_size; i++)
	{
		printf("%s                %s                  %s          %s          %s          \n", ct->_arr[i].Name, ct->_arr[i].Street, ct->_arr[i].City, ct->_arr[i].Eip, ct->_arr[i].State);
		//printf("%s\n", ct->_arr[i].State);
	}
	
}
//ɾ����ϵ��
void ContactDelete(Contact* ct, char* name)
{
	assert(ct);
	for (int i = 0; i < ct->_size; i++)
	{
		if (!(strcmp(ct->_arr[i].Name, name)))
		{
			memcpy(&(ct->_arr[i]), &(ct->_arr[i+1]), \
				sizeof(People));
			ct->_size--;
			printf("�Ѿ�ɾ����\n");
			return;
		}
	}
	printf("δ�ҵ�Ҫɾ������ϵ�ˣ�\n");
}
//������ϵ��
void ContactSearch(Contact* ct,const char* name)
{
	assert(ct);
	for (int i = 0; i < ct->_size; i++)
	{
		if ((strcmp(ct->_arr[i].Name, name))==0)
		{
			printf("�ҵ���!\n");
			printf("����             �ֵ�                ����       �ʱ�        ����\n");
			//printf("|%s              |%s                 |%s        |%s         |%s \n", ct->_arr[i].Name, ct->_arr[i].Street, ct->_arr[i].City, ct->_arr[i].Eip, ct->_arr[i].State);
			printf("%s                %s                  %s          %s          %s          \n", ct->_arr[i].Name, ct->_arr[i].Street, ct->_arr[i].City, ct->_arr[i].Eip, ct->_arr[i].State);
		}
	}
}
//����ͨѶ¼
void ContactDestroy(Contact* ct)
{
	People* del = ct->_arr;
	ct->_arr = nullptr;
	free(del);
}

void save(Contact* ct)
{

	FILE *fp1 = fopen("contact.txt", "wb");
	for (int i = 0; i < ct->_size; i++)
	{
		fwrite(&ct->_arr[i], sizeof(People), 1, fp1);
	}

	FILE *fp2 = fopen("x.txt", "wb");
	fwrite(&ct->_capacity, sizeof(int), 1, fp2);
	fwrite(&ct->_size, sizeof(int), 1, fp2);


	fclose(fp1);
	fclose(fp2);

}