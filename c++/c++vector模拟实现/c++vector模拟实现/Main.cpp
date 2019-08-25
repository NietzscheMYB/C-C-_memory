#include<iostream>
#include<algorithm>
#include<assert.h>
#include<string>
using namespace std;

namespace bit{
	template<class T>
	class Vector
	{
	public:
		//Vector的迭代器是一个原生的指针
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Iterator Begin(){ return _start; }//第一个元素的位置
		Iterator End(){ return _finish; }//最后一个元素的位置
		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }

		size_t Size(){ return _finish - _start; }
		size_t Capacity(){ return _endOfStorage - _start; }

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		Vector(int n,const T& value=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}

		//这里如果使用Iterator做迭代器，就会导致初始化迭代器区间[first,last]只能是Vectord 迭代器
		//这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间
		template<class InputIterator>
		Vector(InputIterator first,InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}
		Vector( Vector<T>&v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{

			Reserve(v.Capacity());//重新申请空间，进行深拷贝
			Iterator it = Begin();
			Iterator vit = v.Begin();
			//ConstIterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			size_t xx = v.Size();
			_finish = _start + xx;
			_endOfStorage = _start + v.Capacity();
		}

		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n,const T& value=T())//const T& value=T()默认参数值
		{
			//1.如果n小于当前的size，则数据个数缩小到n
			if (n < Size())
			{
				_finish = _start + n;
				return;
			}
			//2.空间不够则增容
			if (n>Capacity())
			{
				Reserve(n);
			}
			//先扩容然后给值
			//3.将size扩大到n
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		void PushBack(const T&x)
		{
			Insert(End(), x);
		}
		void PopBack()
		{
			Erase(--End());
		}
		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);
			//空间不够先增容
			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);

				//如果发生了增容，就需要重置pos
				pos = _start + size;
			}

			//搬移
			Iterator end = _finish - 1;//此时end为最后一个元素
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;

		}
		//返回删除数据的下一个数据
		//方便解决：一遍一遍删除迭代器失效问题
		Iterator Erase(Iterator pos)
		{
			//挪动数据进行删除
			Iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			--_finish;
			return pos;
		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}

	private:
		Iterator _start;//指向数据块的开始
		Iterator _finish;//指向有效数据的尾
		Iterator _endOfStorage;//指向存储容量的尾
	};
}


void TestVector1()
{
	bit::Vector<int> first;
	bit::Vector<int> second(4, 100);
	bit::Vector<int> third(second);
	bit::Vector<int> fourth(third);
	cout << second[1] << endl;

	int myints[] = {16,2,77,29};
	bit::Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));//数组转vector
	cout << "The contents of fifth are:"<<endl;
	for (bit::Vector<int>::Iterator it = fifth.Begin(); it != fifth.End(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//测试T是string时，拷贝问题
	bit::Vector<string> strV;

	strV.PushBack("1111");
	strV.PushBack("2222");
	strV.PushBack("3333");
	strV.PushBack("4444");
	for (size_t i = 0; i < strV.Size();i++)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
}

//vector iterator的使用
void PrintVector(const bit::Vector<int>& v)
{
	//使用const迭代器进行遍历打印
	bit::Vector<int>::ConstIterator it = v.CBegin();
	while (it != v.CEnd())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void TestVector2()
{
	//使用push_back插入4个元素
	bit::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	//使用迭代器进行遍历打印
	bit::Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//使用迭代器进行修改
	it = v.Begin();
	while (it != v.End())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);
}
//capacity/vector::reserve/resize
void TestVector3()
{
	size_t sz;
	bit::Vector<int> foo;
	sz = foo.Size();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.PushBack(i);
		if (sz != foo.Capacity())
		{
			sz = foo.Capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}

	//resize
	bit::Vector<int> myvector;
	//set some inital content:
	for (int i = 1; i < 10; i++)
	{
		myvector.PushBack(i);
	}
	myvector.Resize(5);
	myvector.Resize(8, 100);
	myvector.Resize(12);

	cout << "myvector contains:";
	for (size_t i = 0; i < myvector.Size(); i++)
	{
		cout << myvector[i] << " ";
	}
	cout << "\n";
}
void TestVector4()
{
	int a[] = { 1, 2, 3, 4 };
	bit::Vector<int> v(a, a + sizeof(a) / sizeof(int));

	//使用find查找3所在的位置
	bit::Vector<int>::Iterator pos = find(v.Begin(), v.End(),3);

	//删除pos位置的数据
	v.Erase(pos);
	//发现可以进行访问
	//因为编写代码的时候进行了处理，返回了pos下一个元素的值
	cout << *pos << endl;

}
int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	TestVector4();

	return 0;
}