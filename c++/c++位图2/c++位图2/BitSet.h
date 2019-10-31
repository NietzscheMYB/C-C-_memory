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
			{
				return;
			}
			//计算对应的字节
			size_t index = which >> 3;
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

	private:
		std::vector<unsigned char>_set;
		size_t _bitCount;
	};
}

