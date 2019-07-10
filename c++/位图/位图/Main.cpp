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
	//把x对应的位置置1
	void Set(size_t x)
	{
		if (x > _bitCount)    //大于位图的存储个数返回
		{
			return;//不考虑扩容 
		}
		size_t index = x >> 5;//确定下标
		size_t BitNum = x % 32;//确定在哪一位
		_bits[index] |= 1 << BitNum;// 将1左移 进行或运算
	}
	//把x对应的位置置0
	void Rest(size_t x)
	{
		if (x > _bitCount)
		{
			return;//不考虑扩容
		}
		size_t indxe = x >> 5;//确定下标
		size_t BitNum = x % 32;//确定在哪一位
		_bits[indxe] &= (~(1<<BitNum));//将1 左移 取反 进行与
	}
	bool TestExist(size_t x)
	{
		if (x > _bitCount)
		{	
			return false;//不考虑扩容
		}
		size_t index = x >> 5;
		size_t BitNum = x % 32;
		if (_bits[index] & (1 << BitNum))
		{
			return true;
		}
		return false;
	}
	//获取位图中比特位的总个数
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


