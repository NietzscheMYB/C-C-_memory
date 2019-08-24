//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it!=v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it!=v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//使用find插找3所在位置的iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	//在pos位置之前插入30
//	v.insert(pos,30);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	//通过[]读写第0个位置
//	v[0] = 10;
//	cout << v[0] << endl;
//
//	//通过[i]的方式遍历vector
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int> swapv;
//	swapv.swap(v);
//	cout << "v data:";
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "swapv data:";
//
//	for (size_t i = 0; i < swapv.size(); i++)
//	{
//		cout << swapv[i] << " ";
//	}
//	cout << endl;
//
//	//c++11支持的新的遍历
//	for (auto x : swapv)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	for (auto x : swapv)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	//swapv.resize(100);
//	swapv.reserve(100);
//	cout << "capacity:" << swapv.capacity() << endl;
//	cout << "size:" << swapv.size() << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	//使用find找到3所在的位置
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	
	//1.
	//删除pos位置的数据，导致pos迭代器失效。
	//v.erase(pos);
	//cout << *pos << endl;//此时会非法访问


	//2.
	//在pos位置插入数据，导致pos迭代器失效
	//insert会导致迭代器失效，是因为insert可能会导致增容，
	//增容后pos还指向原来的空间，而原来的空间已经被释放掉
	//pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 30);
	//cout << *pos << endl;//此处非法访问


	return 0;
}