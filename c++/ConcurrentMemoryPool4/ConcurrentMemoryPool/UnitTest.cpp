#include"ConcurrenrAlloc.h"
#include<vector>
using namespace std;

void TestThreadCache()
{
	//thread t1(ConcurrentAlloc, 10);
	//thread t2(ConcurrentAlloc, 10);
	//t1.join();
	//t2.join();

	//test1  观察流程！！
	//void* p1 = ConcurrentAlloc(10);
	//void* p2 = ConcurrentAlloc(10);


	//test2  观察前10个与第11个
	//for (size_t i = 0; i < 11; ++i)
	//{
		//cout << ConcurrentAlloc(10) << endl;
	//}

	//test3 反复用10个！！
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

void TestPageCache()
{
	void* ptr = VirtualAlloc(NULL, (NPAGES - 1) << PAGE_SHIFT, MEM_RESERVE, PAGE_READWRITE);
	
	//malloc 不行 
	//void* ptr=malloc((NPAGES-1)<<PAGE_SHIFT);
	
	cout << ptr << endl;
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}
	
	PageID _pageid = (PageID)ptr >> PAGE_SHIFT;
	cout << _pageid << endl;

	void* shiftptr = (void*)(_pageid << PAGE_SHIFT);
	cout << shiftptr << endl;
}

void TestConcurrentAlloc()
{
	//void* p1=ConcurrentAlloc(10);


	for (size_t i = 0; i < 10; ++i)
	{
		cout << ConcurrentAlloc(10) << endl;
	}

}


int main()
{
	//TestThreadCache();
	//TestPageCache();
	TestConcurrentAlloc();
	return 0;
}