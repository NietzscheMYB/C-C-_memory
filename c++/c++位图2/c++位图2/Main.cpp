#include"BitSet.h"

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
		cout << "40 ´æÔÚ" << endl;
	}
	bt.reset(40);
	if (!bt.test(40))
	{
		cout << "40²»´æÔÚ" << endl;
	}
}

int main()
{
	test();
	return 0;
}