#include "Hash.h"

#if 0
int HashFunc(DateType data)
{
	return data%MAX_SIZE;
}

int DectectiveLine(int hashAddr)
{
	hashAddr++;
	if (hashAddr == MAX_SIZE)
	{
		hashAddr = 0;
	}
	return hashAddr;
}
int Dectective2(int hashAddr,int i)
{
	hashAddr = hashAddr + 2 * i + 1;
	if (hashAddr >= MAX_SIZE)
	{
		hashAddr %= MAX_SIZE;
	}
	return hashAddr;
}
void HashTableInit(HT* ht,int IsLineDetective)
{
	int i = 0;
	for (; i < MAX_SIZE; ++i)
	{
		ht->_array[i]._state = EMPTY;
	}
	ht->_size = 0;
	ht->_total = 0;
	ht->_IsLineDetective = IsLineDetective;
}
void HashTableInsert(HT* ht, DateType data)
{
	int hashAddr = 0;
	int i = 0;
	assert(ht);
	if (ht->_total == MAX_SIZE)
	{
		return;
	}
	//计算哈希地址
	 hashAddr = HashFunc(data);
	while (EMPTY != ht->_array[hashAddr]._state)
	{
		if (EXIST == ht->_array[hashAddr]._state)
		{
			if (data == ht->_array[hashAddr]._data)
			{
				return;
			}

		}
		if (1==ht->_IsLineDetective)
		{
			hashAddr=DectectiveLine(hashAddr);
		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
		}
	}
	//插入元素
	ht->_array[hashAddr]._data = data;
	ht->_array[hashAddr]._state = EXIST;
	ht->_size++;
	ht->_total++;
}
void HashTableDelete(HT* ht, DateType data)
{
	int ret = -1;
	assert(ht);
	ret=HashTableFind(ht, data);
	if (-1 != ret)
	{
		ht->_array[ret]._state = DELETE;
		ht->_size--;
	}
}
int HashTableFind(HT* ht, DateType data)
{
	int hashAddr = -1;
	int startAddr = -1;
	int i = 0;
	assert(ht);
	hashAddr = HashFunc(data);
	startAddr = hashAddr;
	while (EMPTY != ht->_array[hashAddr]._state)
	{
		if (EXIST == ht->_array[hashAddr]._state)
		{
			if (data == ht->_array[hashAddr]._data)
			{
				return hashAddr;
			}
		}
		
		if (1 == ht->_IsLineDetective)
		{
			hashAddr = DectectiveLine(hashAddr);
			//找了一圈都没有找到
			if (hashAddr == startAddr)
			{
				return -1;
			}
		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
		}
	}
	return -1;
}
int HashTableSize(HT* ht)
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(HT* ht)
{
	assert(ht);
	return 0 == ht->_size;
}
#endif
void Swap(HT* lht, HT* rht)
{
	int temp = 0;
	assert(lht);
	assert(rht);
	//array
	temp = (int)lht->_array;
	lht->_array = rht->_array;
	rht->_array = (HTElem*)temp;
	//capacity
	temp = lht->_capacity;
	lht->_capacity = rht->_capacity;
	rht->_capacity = temp;
	//size
	temp = lht->_size;
	lht->_size = rht->_size;
	rht->_size = temp;
	//lsLineDetective
	temp = lht->_IsLineDetective;
	lht->_IsLineDetective = rht->_IsLineDetective;
	rht->_IsLineDetective = temp;

}
void HashTableDestroy(HT* ht)
{
	assert(ht);
	if (ht->_array)
	{
		free(ht->_array);

	}
}
int CheckCapacity(HT*ht)
{
	assert(ht);
	if (ht->_size*10/ht->_capacity>=7)
	{
		//开辟新空间
		int newCapacity = ht->_capacity * 2;
		HT newHt;
		int i = 0;
		HashTableInit(&newHt, newCapacity, ht->_IsLineDetective);
		//拷贝元素
		for (; i < ht->_size; ++i)
		{
			if (EXIST == ht->_array[i]._state)
				HashTableInsert(&newHt, ht->_array[i]._data);
		}
		Swap(ht, &newHt);
		//释放旧空间
		HashTableDestroy(&newHt);

	}

	return 1;
}

int HashFunc(DateType data)
{
	return data%MAX_SIZE;
}

int DectectiveLine(int hashAddr)
{
	hashAddr++;
	if (hashAddr == MAX_SIZE)
	{
		hashAddr = 0;
	}
	return hashAddr;
}
int Dectective2(int hashAddr, int i)
{
	hashAddr = hashAddr + 2 * i + 1;
	if (hashAddr >= MAX_SIZE)
	{
		hashAddr %= MAX_SIZE;
	}
	return hashAddr;
}
void HashTableInit(HT* ht,int _capacity, int IsLineDetective)
{
	int i = 0;
	ht->_array=(HTElem*)malloc(_capacity*sizeof(HTElem));
	if (NULL==ht->_array)
	{
		assert(0);
		return;
	}
	for (; i < _capacity; ++i)
	{
		ht->_array[i]._state = EMPTY;
		
	}
	ht->_size = 0;
	ht->_capacity = _capacity;
	ht->_IsLineDetective = IsLineDetective;
}
void HashTableInsert(HT* ht, DateType data)
{
	int hashAddr = 0;
	int i = 0;
	assert(ht);
	if (CheckCapacity(ht))
	{
		return;
	}
	//计算哈希地址
	hashAddr = HashFunc(data);
	while (EMPTY != ht->_array[hashAddr]._state)
	{
		if (EXIST == ht->_array[hashAddr]._state)
		{
			if (data == ht->_array[hashAddr]._data)
			{
				return;
			}

		}
		if (1 == ht->_IsLineDetective)
		{
			hashAddr = DectectiveLine(hashAddr);
		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
		}
	}
	//插入元素
	ht->_array[hashAddr]._data = data;
	ht->_array[hashAddr]._state = EXIST;
	ht->_size++;
	ht->_total++;
}
void HashTableDelete(HT* ht, DateType data)
{
	int ret = -1;
	assert(ht);
	ret = HashTableFind(ht, data);
	if (-1 != ret)
	{
		ht->_array[ret]._state = DELETE;
		ht->_size--;
	}
}
int HashTableFind(HT* ht, DateType data)
{
	int hashAddr = -1;
	int startAddr = -1;
	int i = 0;
	assert(ht);
	hashAddr = HashFunc(data);
	startAddr = hashAddr;
	while (EMPTY != ht->_array[hashAddr]._state)
	{
		if (EXIST == ht->_array[hashAddr]._state)
		{
			if (data == ht->_array[hashAddr]._data)
			{
				return hashAddr;
			}
		}

		if (1 == ht->_IsLineDetective)
		{
			hashAddr = DectectiveLine(hashAddr);
			//找了一圈都没有找到
			if (hashAddr == startAddr)
			{
				return -1;
			}
		}
		else
		{
			hashAddr = Dectective2(hashAddr, ++i);
		}
	}
	return -1;
}
int HashTableSize(HT* ht)
{
	assert(ht);
	return ht->_size;
}
int HashTableEmpty(HT* ht)
{
	assert(ht);
	return 0 == ht->_size;
}