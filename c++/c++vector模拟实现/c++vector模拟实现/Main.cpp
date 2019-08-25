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
		//Vector�ĵ�������һ��ԭ����ָ��
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Iterator Begin(){ return _start; }//��һ��Ԫ�ص�λ��
		Iterator End(){ return _finish; }//���һ��Ԫ�ص�λ��
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

		//�������ʹ��Iterator�����������ͻᵼ�³�ʼ������������[first,last]ֻ����Vectord ������
		//������������������������������[first,last]���������������ĵ���������
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

			Reserve(v.Capacity());//��������ռ䣬�������
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

		void Resize(size_t n,const T& value=T())//const T& value=T()Ĭ�ϲ���ֵ
		{
			//1.���nС�ڵ�ǰ��size�������ݸ�����С��n
			if (n < Size())
			{
				_finish = _start + n;
				return;
			}
			//2.�ռ䲻��������
			if (n>Capacity())
			{
				Reserve(n);
			}
			//������Ȼ���ֵ
			//3.��size����n
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
			//�ռ䲻��������
			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);

				//������������ݣ�����Ҫ����pos
				pos = _start + size;
			}

			//����
			Iterator end = _finish - 1;//��ʱendΪ���һ��Ԫ��
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;

		}
		//����ɾ�����ݵ���һ������
		//��������һ��һ��ɾ��������ʧЧ����
		Iterator Erase(Iterator pos)
		{
			//Ų�����ݽ���ɾ��
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
		Iterator _start;//ָ�����ݿ�Ŀ�ʼ
		Iterator _finish;//ָ����Ч���ݵ�β
		Iterator _endOfStorage;//ָ��洢������β
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
	bit::Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));//����תvector
	cout << "The contents of fifth are:"<<endl;
	for (bit::Vector<int>::Iterator it = fifth.Begin(); it != fifth.End(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����T��stringʱ����������
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

//vector iterator��ʹ��
void PrintVector(const bit::Vector<int>& v)
{
	//ʹ��const���������б�����ӡ
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
	//ʹ��push_back����4��Ԫ��
	bit::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);

	//ʹ�õ��������б�����ӡ
	bit::Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//ʹ�õ����������޸�
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

	//ʹ��find����3���ڵ�λ��
	bit::Vector<int>::Iterator pos = find(v.Begin(), v.End(),3);

	//ɾ��posλ�õ�����
	v.Erase(pos);
	//���ֿ��Խ��з���
	//��Ϊ��д�����ʱ������˴���������pos��һ��Ԫ�ص�ֵ
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