#include"ConcurrenrAlloc.h"
#include<vector>
using namespace std;

void TestThreadCache()
{
	//thread t1(ConcurrentAlloc, 10);
	//thread t2(ConcurrentAlloc, 10);
	//t1.join();
	//t2.join();

	//test1  �۲����̣���
	//void* p1 = ConcurrentAlloc(10);
	//void* p2 = ConcurrentAlloc(10);


	//test2  �۲�ǰ10�����11��
	//for (size_t i = 0; i < 11; ++i)
	//{
		//cout << ConcurrentAlloc(10) << endl;
	//}

	//test3 ������10������
	//vector<void*> v;
	//for (size_t i = 0; i < 10; ++i)
	//{
	//	v.push_back(ConcurrentAlloc(10));
	//	cout <<v.back() << endl;
	//}
	//cout << endl << endl;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	ConcurrentFree(v[i],10);
	//}
	//v.clear();

	//for (size_t i = 0; i < 10; ++i)
	//{
	//	v.push_back(ConcurrentAlloc(10));
	//	cout << v.back() << endl;
	//}
	//for (size_t i = 0; i < 10; i++)
	//{
	//	ConcurrentFree(v[i],10);
	//}
	//v.clear();
}


int main()
{
	TestThreadCache();
	return 0;
}