#include"ConcurrentAlloc.h"
#include<vector>



void test()
{
	//test1 
	//thread t1(ConcurrentAlloc, 10);
	//thread t2(ConcurrentAlloc, 10);
	//t1.join();
	//t2.join();

	//test2�۲�
	vector<std::thread> v1;
	for (int i = 0; i < 11; i++)
	{
		//cout << ConcurrentAlloc(10) << endl;
		//void* p1 = ConcurrentAlloc(10);
		cout << sizeof(ConcurrentAlloc(10)) << endl;
	}


	//test3������10��
	/*vector<void*> v;
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
		cout << v.back() << endl;
	}
	cout << endl << endl;
	for (size_t i = 0; i < 10; i++)
	{
		ConcurrentFree(v[i], 10);
	}
	v.clear();
	for (size_t i = 0; i < 10; ++i)
	{
		v.push_back(ConcurrentAlloc(10));
		cout << v.back() << endl;
	}
	cout << endl << endl;
	for (size_t i = 0; i < 10; i++)
	{
		ConcurrentFree(v[i], 10);
	}
	v.clear();*/
}


int main()
{
	test();
	return 0;
}