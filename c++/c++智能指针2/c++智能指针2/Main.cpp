#include<iostream>
#include<memory>
using namespace std;

//int main()
//{
//	unique_ptr<int> up1(new int);
//	//������ֹ��������
//	//unique_ptr<int> up2(up1);
//	unique_ptr<int> up2;
//	//Ҳ���ܸ�ֵ����ֹ�������������
//	//up2 = up1;
//
//	//����ǰ�����׵�ַ��ӡ
//	cout << up1.get() << endl;
//	up1.release();//�������ͷ�
//
//	//����ǰ�����׵�ַ��ӡ
//	cout << up1.get() << endl;
//	up1.reset(new int);
//	
//	//����ǰ�����׵�ַ��ӡ
//	cout << up1.get() << endl;
//
//	return 0;
//}

//unique_ptr:ʵ��ԭ��һ����Դ��
//һ�������ռ
//RAII + operator*()/operator->()  +   ��ֹ���ÿ�������
namespace bite{
	template<class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
	private:
		//c++98; ֻ���������壡����
		//unique_ptr(const unique_ptr<T>& p);
		//unique_ptr<T>& operator=(unique_ptr<T>& p);
		//c++11 delete ��ֹ���ɸú���
		unique_ptr(const unique_ptr<T>& p) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>&p) = delete;
	private:
		T* _ptr;
	};

	
}
namespace x{
	//share_ptr
	//RAII operator*()/operator->() +֧�ֿ�������+֧�ָ�ֵ��������� +  ���ü���
	//ȱ�ݣ����ܹ����������͵�ָ�룬
	//�̲߳���ȫ ����++
	//ѭ������


	template<class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}
		~shared_ptr()
		{
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr; //
				delete _pCount;
			}
		}
		////////////////////////////////////////////
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		///////////////////////////////////////
		//�������ü����ķ�ʽ���ǳ��������
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			++*_pCount;
		}
		//sp2=sp1;
		//sp2�Ƿ�����Դ----->û��----->ֱ�ӹ���
		//sp2�Ƿ�����Դ----->�У�
		//1.��Դ�ļ�����1   
		//2.����>1    
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//��this����Դ�з��뿪
				if (_ptr && 0 == --*_pCount)
				{
					delete _ptr;
					delete _pCount;
				}
				//������Դ
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				++*_pCount;
			}
			return *this;
		}
		size_t use_count() const
		{
			return *_pCount;
		}
	private:
		T* _ptr;
		int* _pCount;
	};

}

int main()
{
	x::shared_ptr<int> p1(new int);
	bite::unique_ptr<int> p2(new int);
	return 0;
}













