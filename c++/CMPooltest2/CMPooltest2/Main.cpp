#include"ThreadCache.h"
#include"ConcurrentAlloc.h"

int main()
{
	vector<void*> v;
	void* p = nullptr;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(Alloc(10));
		cout << v.back() << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		p = v[i];
		Delloc(p,10);
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(Alloc(10));
		cout << v.back() << endl;
	}

	return 0;
}