#include"Hash.h"

int Dectective(int hashAddr)//����̽��
{
	hashAddr++;
	if (hashAddr == MAX_CAPACITY)
	{
		hashAddr = 0;
	}
	return hashAddr;
}
int Dectective2(int hashAddr, int i)//����̽��
{
	hashAddr = hashAddr + 2 * i + 1;
	if (hashAddr >= MAX_CAPACITY)
	{
		hashAddr %= MAX_CAPACITY;
	}
	return hashAddr;
}



int HashFunc(People x)
{
	int len = strlen(x.tel);
	char arr[5] = { '0' };
	int count = 0,sum=0,j=0;
	for (int i = 0; i < len; i++)
	{
		arr[j++] = x.tel[i];
		count++;
		if (count == 3)
		{
			int y = atoi(arr);
			count = 0;
			j = 0;
			sum += y;
		}
	}
	return sum % 23;
}



void Swap(HT* lht, HT* rht)
{
	int temp = 0;
	assert(lht);
	assert(rht);

	//array
	temp = (int)lht->arr;
	lht->arr = rht->arr;
	rht->arr = (HTElem*)temp;

	//capacity
	temp = lht->capacity;
	lht->capacity = rht->capacity;
	rht->capacity = temp;
	//size
	temp = lht->size;
	lht->size = rht->size;
	rht->size = temp;
	//IslineDectective
	temp = lht->IsLineDetective;
	lht->IsLineDetective = rht->IsLineDetective;
	rht->IsLineDetective = temp;
}
void CheckCapacity(HT*ht)
{
	assert(ht);
	if (ht->size * 10 / ht->capacity >= 7)
	{
		//�����¿ռ�
		int newCapacity = ht->capacity * 2;
		HT newht;
		int i = 0;
		HashTableInit(&newht, newCapacity, ht->IsLineDetective);
		//����Ԫ��
		for (i = 0; i < ht->size; i++)
		{
			if (EXIST == ht->arr[i].state)
			{
				HashTableInsert(&newht, ht->arr[i].p);
			}
		}
		Swap(ht, &newht);
		//�ͷžɿռ�
		HashTableDestroy(&newht);
	}
}
void Init(HT* ht, int capacity, int IsLineDetective)
{
	assert(ht);
	ht->arr = (HTElem*)malloc(sizeof(HTElem)* MAX_CAPACITY);
	if (NULL == ht->arr)
	{
		assert(0);
		return;
	}
	ht->capacity = capacity;
	for (int i = 0; i < ht->capacity; i++)
	{
		ht->arr[i].state = EMPTY;
	}
	ht->size = 0;
	ht->IsLineDetective = IsLineDetective;
}
void HashTableInit(HT* ht, int capacity,int IsLineDetective)
{
	assert(ht);
	ht->arr = (HTElem*)malloc(sizeof(HTElem)* MAX_CAPACITY);
	if (NULL == ht->arr)
	{
		assert(0);
		return;
	}
	ht->capacity = capacity;
	for (int i = 0; i < ht->capacity; i++)
	{
		ht->arr[i].state = EMPTY;
	}
	ht->size = 0;
	ht->IsLineDetective = IsLineDetective;


	FILE *fp1 = fopen("tel.txt", "rb");  //����Ϣ
	FILE *fp2 = fopen("x.txt", "rb");    //��size��capacity  
	//FILE *fp3 = fopen("s.txt", "rb");//��״̬
	fread(&ht->capacity, sizeof(int), 1, fp2);
	fread(&ht->size, sizeof(int), 1, fp2);
	fread(ht->arr, sizeof(HTElem)* ht->size, 1, fp1);



	/*HTElem xy;
	for (int i = 0; i < ht->capacity; i++)
	{
		int hashAddr = 0;
		if (ht->arr[i].state == EXIST)
		{
			memcpy(&xy, &ht->arr[i], sizeof(HTElem));
			ht->arr[i].state = EMPTY;
			hashAddr = HashFunc(xy.p);
			if (EXIST == ht->arr[hashAddr].state)
			{
				if (1 == ht->IsLineDetective)
				{
					hashAddr = Dectective(hashAddr);
				}
				else
				{
					hashAddr = Dectective2(hashAddr, ++i);
				}
			}
			
			memcpy(&ht->arr[hashAddr], &xy, sizeof(HTElem));
		}
		
	}*/
	
	//�����¿ռ�
	int newCapacity = ht->capacity;
	HT newht;
	int i = 0;
	Init(&newht, newCapacity, ht->IsLineDetective);
	//����Ԫ��
	for (i = 0; i < ht->size; i++)
	{
		if (EXIST == ht->arr[i].state)
		{
			HashTableInsert(&newht, ht->arr[i].p);
		}
	}
	Swap(ht, &newht);
	//�ͷžɿռ�
	HashTableDestroy(&newht);

	fclose(fp1);
	fclose(fp2);


}
void HashTableInsert(HT* ht, People x)
{
	int hashAddr = 0;
	int i = 0;
	assert(ht);
	if (ht->size * 10 / ht->capacity >= 7)//����ϣ����
	{
		CheckCapacity(ht);
	}
	//�����ϣ��ַ
	hashAddr = HashFunc(x);
	while (EMPTY != ht->arr[hashAddr].state)
	{
		if (EXIST == ht->arr[hashAddr].state)
		{
			if (strcmp(x.tel, ht->arr[hashAddr].p.tel) == 0)
			{
				return;
			}
		}
		if (1 == ht->IsLineDetective)
		{
			hashAddr = Dectective(hashAddr);
		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
		}
	}
	//����Ԫ��
	/*strcpy(ht->arr[hashAddr].p.addr, x.addr);
	strcpy(ht->arr[hashAddr].p.name, x.name);
	strcpy(ht->arr[hashAddr].p.tel, x.tel);*/
	
	memcpy(&ht->arr[hashAddr], &x, sizeof(People));
	
	ht->arr[hashAddr].state = EXIST;
	ht->size++;

}
void HashTableDelete(HT* ht, People x)
{
	int hashAddr = -1;
	int startAddr = -1;
	int i = 0;
	assert(ht);
	hashAddr = HashFunc(x);
	startAddr = hashAddr;
	while (EMPTY != ht->arr[hashAddr].state)
	{
		if (EXIST == ht->arr[hashAddr].state)
		{
			if (strcmp(x.tel, ht->arr[hashAddr].p.tel) == 0)
			{
				printf("ɾ���ɹ�����\n");
				//printf("%s         %s        %s", ht->arr[hashAddr].p.name, ht->arr[hashAddr].p.tel, ht->arr[hashAddr].p.addr);
				//memcpy(&ht->arr[hashAddr], &x, sizeof(People));
				ht->size--;
				ht->arr[hashAddr].state = DELET;
				return;
			}
		}
		if (1 == ht->IsLineDetective)
		{
			hashAddr = Dectective(hashAddr);
			//����һȦû�ҵ�
			if (hashAddr == startAddr)
			{
				printf("û���ҵ���\n");
				return;
			}

		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
			if (hashAddr == startAddr)
			{
				printf("û���ҵ���\n");
				return;
			}
		}
		printf("û���ҵ���\n");
		return;
	}
}
void HashTableFind(HT* ht, People x)
{
	int hashAddr = -1;
	int startAddr = -1;
	int i = 0;
	assert(ht);
	hashAddr = HashFunc(x);
	startAddr = hashAddr;
	while (EMPTY != ht->arr[hashAddr].state)
	{
		if (EXIST == ht->arr[hashAddr].state)
		{
			if (strcmp(x.tel, ht->arr[hashAddr].p.tel) == 0)
			{
				printf("�ҵ��ˣ�\n");
				printf("%-12s%-12s%-12s\n", ht->arr[hashAddr].p.name, ht->arr[hashAddr].p.tel, ht->arr[hashAddr].p.addr);
				return;
			}
		}
		if (1 == ht->IsLineDetective)
		{
			hashAddr = Dectective(hashAddr);
			//����һȦû�ҵ�
			if (hashAddr == startAddr)
			{
				printf("û���ҵ���\n");
				return;
			}

		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
			if (hashAddr == startAddr)
			{
				printf("û���ҵ���\n");
				return;
			}
		}
	
	}
	printf("û���ҵ���\n");
	return;
}
int HashTableSize(HT* ht)
{
	assert(ht);
	return ht->size;
}
int HashTableEmpty(HT* ht)
{
	assert(ht);
	return 0 == ht->size;
}
void HashTableDestroy(HT* ht)
{
	assert(ht);
	if (ht->arr)
	{
		free(ht->arr);
	}
	
}

void Show(HT* ht)
{
	assert(ht);
	printf("����        �绰����               ��ַ\n");
	for (int i = 0; i < ht->capacity; i++)
	{
		if (ht->arr[i].state == EXIST)
		{
			printf("%-12s%-22s%-22s\n", ht->arr[i].p.name, ht->arr[i].p.tel, ht->arr[i].p.addr);

		}

	}
}
void save(HT* ht)
{

	FILE *fp1 = fopen("tel.txt", "wb");
	for (int i = 0; i < ht->capacity; i++)
	{
		if (ht->arr[i].state == EXIST)
		{
			fwrite(&ht->arr[i], sizeof(HTElem), 1, fp1);
		}
	}

	FILE *fp2 = fopen("x.txt", "wb");
	fwrite(&ht->capacity, sizeof(int), 1, fp2);
	fwrite(&ht->size, sizeof(int), 1, fp2);


	fclose(fp1);
	fclose(fp2);

}