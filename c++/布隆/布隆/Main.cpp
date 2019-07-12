//插入  数组中的位置  num.>>5 
//定位数组中的位置的bit位：num%32
//bit位置1   ：table[位置] |=1<<bits位


//删除 bit位置0
//与0进行与&运算  其他位不受影响
//table[位置] &=~(1<<bits)

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
		_bits[indxe] &= (~(1 << BitNum));//将1 左移 取反 进行与
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

template <class K,class HashFun1,class HashFun2,class HashFun3>
class BloomFilter{
public:
	/*
		k=m*ln2/n
		k:哈希函数的数量
		n：range
		m：需要bit位的个数
		m=k*n/102------> k*range/0.7
	*/
	BloomFilter(size_t range)
		:bs(range*5)
	{}
	void Set(const K& key)
	{
		//首先将key转整数
		size_t index1 = HashFun1()(key)%_bitCount;  //肯不在范围内 所以要%
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

		return true;//误判
	}

	//一般不提供删除 可能存在误删


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

















