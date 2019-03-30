#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a+sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test2()
{
	int a[] = { 1, 2, 3, 4 };
	vector <int> v(a, a + sizeof(a) / sizeof(int));
	//使用find查找3所在的位置的iteator
	vector<int>::iterator pos =find(v.begin(), v.end(), 3);
	//删除pos位置的数据，导致pos迭代器失效
	v.erase(pos);
	cout << *pos << endl;//此次导致非法访问

	//在pos位置插入数据，到这种pos迭代器失效
	//insert会导致迭代器失效，是因为insert
	//可能会增容，增容后pos还指向原来的空间
	//而原来的空间已经释放掉了
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl;//此处导致非法访问


}
int main()
{
	/*size_t sz;
	std::vector <int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}*/

	/*size_t sz;
	std::vector <int> foo;
	sz = foo.capacity();
	foo.reserve(100);
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}*/
	test1();
	return 0;
}