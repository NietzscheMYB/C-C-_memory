#include"hash.h"


void test()
{
	HashTable<int, int>  xx;
	xx.Insert(pair<int,int>(1,2));
	xx.Insert(pair<int, int>(1, 2));
	xx.Insert(pair<int, int>(2, 2));

	xx.Erase(1);

	/*xx.Insert(pair<int, int>(4, 2));
	xx.Insert(pair<int, int>(5, 2));*/

}

int main()
{
	test();
	return 0;
}