#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << sz << endl;
//	cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			cout << "capacity changed: " << sz << "\n";
//		}
//	}
//
//	cout << "---------------" << endl;
//	vector<int> bar;
//	sz = bar.capacity();
//	cout << sz << endl;
//
//	bar.reserve(100);
//	int sz1 = bar.capacity();
//
//	cout << sz1 << endl;
//
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		bar.push_back(i);
//		if (sz != bar.capacity())
//		{
//			sz = bar.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//
//
//	return 0;
//}

int main()
{
	vector<int> myvector;
	cout << myvector.size() << endl;
	for (int i = 1; i < 10; i++)
	{
		myvector.push_back(i);
	}
	cout << myvector.size() << endl;
	myvector.resize(5);
	cout << myvector.size() << endl;

	myvector.resize(8, 100);
	myvector.resize(12);
	cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
	{
		cout << " " << myvector[i];
	}
	cout << '\n';
	return 0;
}