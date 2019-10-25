#include<iostream>
using namespace std;
#if 0
namespace a{
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~auto_ptr(){
			if (_ptr)
			{
				delete _ptr;
			}
		}
		auto_ptr(auto_ptr<T>& p)
		{
			_ptr = p._ptr;
			p._ptr = nullptr;
		}
		//ʵ��RAII ˼�룬��ָ��һ���������ǳ��������
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};
}

struct Date{
	int _year;
	int _month;
	int _day;
};
int main()
{
	a::auto_ptr<int> p1(new int(1));
	*p1=2;
	a::auto_ptr<int> p2(p1);
	//auto_ptr �Ŀ������죬�ǽ���Դ����ת�ƣ����´μ�����p1����* ����ʱ���ͻ����
	*p1 = 2;
	a::auto_ptr<Date> p3(new Date);
	return 0;
}
#endif

#if 0
namespace b{
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
		//��ָ��һ��
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		//c++11�з�ֹ�����ķ�ʽ
		//�����������delete
		//��˼�ǽ�ֹ�ú������ɣ���Ĭ�ϳ�Ա����ɾ��
		unique_ptr(const unique_ptr<T> &) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&)=delete
	private:
		//��ֹ�������ֹ���������
		//c++98��˽����ֻ����������
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator = (unique_ptr<T> p);

	private:
		T* _ptr;
	};
}
struct Data{
	int _date;
	int _year;
	int _month;
};

int main()
{
	b::unique_ptr<int> p1(new int(1));
	 //b::unique_ptr<int> p2(p1);
	 //b::unique_ptr<int> p3(new int(3));
	 //p1 = p3;
	b::unique_ptr<Data> p2(new Data);
	p2->_date = 1;
	p2->_month = 2;
	p2->_year = 3;

	return 0;
}
#endif

//�������͵���Դ�ܹ����й���
//���裺��Դ����new��malloc �ļ�ָ�룬�׽���
//����ɾ����


//���new����Դ
template<class T>
struct DFDel
{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr == nullptr;
		}
	}
};



//�����ļ���Դ
struct FClose{
	void operator()(FILE* pf)
	{
		if (pf)
		{
			fclose(pf);
		}
	}
};

//���free����Դ
template<class T>
struct Free
{
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};
namespace b{

	template<class T, class DF = DFDel<T>>
	class unique_ptr{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			DF(_ptr);
		}
		//��ָ��һ��
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		//c++11�з�ֹ�����ķ�ʽ
		//�����������delete
		//��˼�ǽ�ֹ�ú������ɣ���Ĭ�ϳ�Ա����ɾ��
		unique_ptr(const unique_ptr<T> &) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&) = delete
	private:
		//��ֹ�������ֹ���������
		//c++98��˽����ֻ����������
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator = (unique_ptr<T> p);

	private:
		T* _ptr;
	};
}
struct Data{
	int _date;
	int _year;
	int _month;
};

int main()
{
	b::unique_ptr<int> p1(new int(1));
	//b::unique_ptr<int> p2(p1);
	//b::unique_ptr<int> p3(new int(3));
	//p1 = p3;
	b::unique_ptr<Data> p2(new Data);
	p2->_date = 1;
	p2->_month = 2;
	p2->_year = 3;
	b::unique_ptr<Data,Free<Data>> p4((Data*)malloc(sizeof(Data)));
	b::unique_ptr<char, Free<char>> p5((char*)malloc(sizeof(char)));

	return 0;
}



#if 0
#include<mutex>
namespace c{
	template<class T>
	class share_ptr{
	public:
		share_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
			, _mt(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(0);
				_mt = new mutex;
				++*_pCount;
			}
		}
		~share_ptr()
		{
			_mt->lock();
			if (_ptr&&--*_pCount==0)
			{
				delete _ptr;
			}
			_mt->unlock();
		}
		share_ptr(const share_ptr<T>& p)
			:_ptr(p._ptr)
			, _pCount(p._pCount)
		{
			*_pCount++;
		}
		share_ptr<T>& operator=(share_ptr<T>& p)
		{
			//��ֵ�����
			if (this != &p)
			{
				_mt->lock();
				//����ֵ�Ķ���
				if (_ptr)
				{
					if (_ptr&&--*_pCount == 0)
					{
						delete _ptr;
						delete _pCount;
					}
				}
				_ptr = p._ptr;
				_pCount = p._pCount;
				++*_pCount;
				_mt->unlock();
			}
			return *this;
		}
		//��ָ��һ��
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}


	private:
		T* _ptr;
		int* _pCount;
		mutex* _mt;
	};
}
struct Date{
	int _day;
	int _year;
	int _month;
};

int main()
{
	c::share_ptr<int> p1(new int(1));
	c::share_ptr<int> p2(new int(2));
	c::share_ptr<int> p3;
	p3 = p1;
	p2 = p1;

	return 0;
}
#endif



