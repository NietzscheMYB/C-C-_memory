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
		_bits[indxe] &= (~(1<<BitNum));//��1 ���� ȡ�� ������
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


