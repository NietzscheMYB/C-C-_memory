//����  �����е�λ��  num.>>5 
//��λ�����е�λ�õ�bitλ��num%32
//bitλ��1   ��table[λ��] |=1<<bitsλ


//ɾ�� bitλ��0
//��0������&����  ����λ����Ӱ��
//table[λ��] &=~(1<<bits)

//bloomfilter
#include <iostream>
#include<vector>
using namespace std;

class bitSet
{
public:
	bitSet(size_t range)
		:_bitCount(range)
	{
		_bits.resize((range >> 5) + 1);
	}
	//��x��Ӧ��λ����1
	void Set(size_t x)
	{
		if (x > _bitCount)    //����λͼ�Ĵ洢��������
		{
			return;//���������� 
		}
		size_t index = x >> 5;//ȷ���±�
		size_t BitNum = x % 32;//ȷ������һλ
		_bits[index] |= 1 << BitNum;// ��1���� ���л�����
	}
	//��x��Ӧ��λ����0
	void Rest(size_t x)
	{
		if (x > _bitCount)
		{
			return;//����������
		}
		size_t indxe = x >> 5;//ȷ���±�
		size_t BitNum = x % 32;//ȷ������һλ
		_bits[indxe] &= (~(1 << BitNum));//��1 ���� ȡ�� ������
	}
	bool TestExist(size_t x)
	{
		if (x > _bitCount)
		{
			return false;//����������
		}
		size_t index = x >> 5;
		size_t BitNum = x % 32;
		if (_bits[index] & (1 << BitNum))
		{
			return true;
		}
		return false;
	}
	//��ȡλͼ�б���λ���ܸ���
	size_t Size()const
	{
		return _bitCount;
	}


private:
	vector<int> _bits;
	size_t _bitCount;
};

template <class K,class HashFun1,class HashFun2,class HashFun3>
class BloomFilter{
public:
	/*
		k=m*ln2/n
		k:��ϣ����������
		n��range
		m����Ҫbitλ�ĸ���
		m=k*n/102------> k*range/0.7
	*/
	BloomFilter(size_t range)
		:bs(range*5)
	{}
	void Set(const K& key)
	{
		//���Ƚ�keyת����
		size_t index1 = HashFun1()(key)%_bitCount;  //�ϲ��ڷ�Χ�� ����Ҫ%
		size_t index2 = HashFun2()(key) % _bitCount;
		size_t index3 = HashFun3()(key) % _bitCount;
		bs.Set(index1);
		bs.Set(index2);
		bs.Set(index3);

	}
	bool Test(const K& key)
	{
		size_t index1 = HashFun1()(key) % _bitCount;
		if (!bs.TestExist(index1))
		{
			return false;
		}
		size_t index2 = HashFun2()(key) % _bitCount;
		if (!bs.TestExist(index2))
		{
			return false;
		}
		size_t index3 = HashFun3()(key) % _bitCount;
		if (!bs.TestExist(index3))
		{
			return false;
		}

		return true;//����
	}

	//һ�㲻�ṩɾ�� ���ܴ�����ɾ


private:
	bitSet bs;
	size_t _bitCount;
};

struct HF1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 65599 + e;
		}
	}
};

struct HF2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 65599 + e;
		}
	}
};
struct HF3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& e : str)
		{
			hash = hash * 65599 + e;
		}
	}
};


int main()
{
	bitSet myb(10);
	myb.Set(5);
	myb.Set(7);
	myb.Set(37);
	myb.Rest(7);
	bool ret = myb.TestExist(5);
	ret = myb.TestExist(7);
	myb.TestExist(37);

	return 0;
}

















