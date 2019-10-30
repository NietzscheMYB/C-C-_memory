#pragma once
#include<vector>
#include<iostream>
using namespace std;
namespace bite
{
	class bitset
	{
	public:
		bitset(size_t bitCount)
			:_set(bitCount/8+1)
			, _bitCount(bitCount)
		{}
		//置1
		void set(size_t which)
		{
			if (which >= _bitCount)
			{
				return;
			}
			//计算对应的字节
			size_t index = (which >> 3);//除以8
			size_t pos = which % 8;

			_set[index] |= (1 << pos);

		}

		//置0
		void reset(size_t which)
		{
			if (which >= _bitCount)
				return;
			//计算对应的字节
			size_t index = (which >> 3);
			size_t pos = which % 8;

			_set[index] &= ~(1 << pos);
		}

		//检查which比特位是否为1
		bool test(size_t which)
		{
			if (which >= _bitCount)
			{
				return false;
			}

			//计算对应的字节
			size_t index = (which >> 3);
			size_t pos = which % 8;

			return 0 != (_set[index] & (1 << pos));
		}

		//返回比特位总的个数
		size_t size()
		{
			return _bitCount;
		}

		//返回为1比特位的总数
		size_t count()
		{}

	public:
		std::vector<unsigned char> _set;
		size_t _bitCount;
	};
}

void test()
{
	bite::bitset bt(100);
	bt.set(10);
	bt.set(20);
	bt.set(30);
	bt.set(40);
	bt.set(41);
	cout << bt.size() << endl;

	if (bt.test(40))
	{
		cout << "40存在" << endl;
	}
	bt.reset(40);
	if (!bt.test(40))
	{
		cout << "40不存在" << endl;
	}

}