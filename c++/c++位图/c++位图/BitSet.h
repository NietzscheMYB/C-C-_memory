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
				return;
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);
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

		//����Ϊ1����λ������
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
		cout << "40����" << endl;
	}
	bt.reset(40);
	if (!bt.test(40))
	{
		cout << "40������" << endl;
	}

}