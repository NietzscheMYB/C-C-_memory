#include"Hash.h"

int Dectective(int hashAddr)//线性探测
{
	hashAddr++;
	if (hashAddr == MAX_CAPACITY)
	{
		hashAddr = 0;
	}
	return hashAddr;
}
int Dectective2(int hashAddr, int i)//二次探测
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
		//开辟新空间
		int newCapacity = ht->capacity * 2;
		HT newht;
		int i = 0;
		HashTableInit(&newht, newCapacity, ht->IsLineDetective);
		//拷贝元素
		for (i = 0; i < ht->size; i++)
		{
			if (EXIST == ht->arr[i].state)
			{
				HashTableInsert(&newht, ht->arr[i].p);
			}
		}
		Swap(ht, &newht);
		//释放旧空间
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


	FILE *fp1 = fopen("tel.txt", "rb");  //读信息
	FILE *fp2 = fopen("x.txt", "rb");    //读size，capacity  
	//FILE *fp3 = fopen("s.txt", "rb");//读状态
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
	
	//开辟新空间
	int newCapacity = ht->capacity;
	HT newht;
	int i = 0;
	Init(&newht, newCapacity, ht->IsLineDetective);
	//拷贝元素
	for (i = 0; i < ht->size; i++)
	{
		if (EXIST == ht->arr[i].state)
		{
			HashTableInsert(&newht, ht->arr[i].p);
		}
	}
	Swap(ht, &newht);
	//释放旧空间
	HashTableDestroy(&newht);

	fclose(fp1);
	fclose(fp2);


}
void HashTableInsert(HT* ht, People x)
{
	int hashAddr = 0;
	int i = 0;
	assert(ht);
	if (ht->size * 10 / ht->capacity >= 7)//检查哈希因子
	{
		CheckCapacity(ht);
	}
	//计算哈希地址
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
	//插入元素
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
				printf("删除成功！！\n");
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
			//找了一圈没找到
			if (hashAddr == startAddr)
			{
				printf("没有找到！\n");
				return;
			}

		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
			if (hashAddr == startAddr)
			{
				printf("没有找到！\n");
				return;
			}
		}
		printf("没有找到！\n");
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
				printf("找到了！\n");
				printf("%-12s%-12s%-12s\n", ht->arr[hashAddr].p.name, ht->arr[hashAddr].p.tel, ht->arr[hashAddr].p.addr);
				return;
			}
		}
		if (1 == ht->IsLineDetective)
		{
			hashAddr = Dectective(hashAddr);
			//找了一圈没找到
			if (hashAddr == startAddr)
			{
				printf("没有找到！\n");
				return;
			}

		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
			if (hashAddr == startAddr)
			{
				printf("没有找到！\n");
				return;
			}
		}
	
	}
	printf("没有找到！\n");
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
	printf("姓名        电话号码               地址\n");
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