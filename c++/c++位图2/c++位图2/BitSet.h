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
		//��1
		void set(size_t which)
		{
			if (which >= _bitCount)
			{
				return;
			}
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);//����8
			size_t pos = which % 8;

			_set[index] |= (1 << pos);
		}
		//��0
		void reset(size_t which)
		{
			if (which >= _bitCount)
			{
				return;
			}
			//�����Ӧ���ֽ�
			size_t index = which >> 3;
			size_t pos = which % 8;
			_set[index] &= ~(1 << pos);
		}
		//���which����λ�Ƿ�Ϊ1
		bool test(size_t which)
		{
			if (which >= _bitCount)
			{
				return false;
			}
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);
			size_t pos = which % 8;

			return 0 != (_set[index] & (1 << pos));

		}
		//���ر���λ�ܵĸ���
		size_t size()
		{
			return _bitCount;
		}

	private:
		std::vector<unsigned char>_set;
		size_t _bitCount;
	};
}

