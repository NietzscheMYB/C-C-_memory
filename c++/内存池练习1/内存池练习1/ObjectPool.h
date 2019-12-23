//����� ��������
#pragma once
#include <iostream>
using namespace std;

//�����Ķ����
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		//�ڴ�����char* ������
		//c++11��ȷ��ֵ�ͳ�ʼ����
		char* _start = nullptr;
		size_t _bytesize = 0;//���ٸ��ֽ�
		size_t _byteleft = 0;//ʣ���ֽ���
		Block* _next = nullptr;
		Block(size_t bytesize)
		{
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}
		~Block()
		{
			free(_start);
			_byteleft=_bytesize = 0;
			_next = nullptr;
		}
	};
public:
	ObjectPool(size_t initnum=8)//��һ��������ٸ�����
	{
		_head = _tail = new Block(initnum*sizeof(T));
	}

	~ObjectPool()
	{
		Destory();
	}
	Destroy()
	{
		Block* cur = _head;
		while (cur)
		{
			Block* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head = _tail = nullptr;
		_freelist = nullptr;
	}


	T*& OBJ_NEXT(T* obj)
	{
		//�����*(T*) obj;
		//�����ú��Ǹ����͵Ĵ�С��T**�����ú��Ǹ�����ָ��Ĵ�С�����ϵͳ�޹�
		return *(T**)obj;//�����͵�ָ��ǰ���ٸ��ֽ�
	}
	T* New()//���ṩһ������һ�ݿռ�
	{
		T* obj = nullptr;
		//�����������Ϊ��
		if (_freelist!=nullptr)
		{
			//������������ȥȡ�Ϳ���
			obj = _freelist;
			//�仯ͷָ��
			_freelist = OBJ_NEXT(_freelist);
		}
		else{
			//��������Ϊ��
			
			//�жϵ�ǰ���ڴ���Ƿ���ʣ��
			if (_tail->_byteleft == 0)
			{
				//û��ʣ�࣬���������ڴ��
				Block* newblock = new Block(_tail->_bytesize * 2);
				_tail->_next = newblock;
				_tail = newblock;
			}
			obj = (T*)(_tail->_start + (_tail->_bytesize - _tail->_byteleft));
			_tail->_byteleft -= sizeof(T);
		}
		//new(obj)T();//��λ���ʽ
		return obj;
	}
	void Delete(T* ptr)
	{
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			//(*(T**)ptr)=nullptr;
			OBJ_NEXT(ptr) = nullptr;        //��ptr�����ǰ�ĸ��ֽڵ�������Ϊ�գ�����
		}
		else{
			OBJ_NEXT(ptr) = _freelist;//��ptr����ǰ�ĸ��ֽڵ�������Ϊ_freelist!!!
			_freelist = ptr;
		}
	}
protected:
	//������������Ҫ�ǹ���飡����
	T* _freelist = nullptr;
	//�����
	Block* _head = nullptr;
	Block* _tail = nullptr;
};

void test()
{
	ObjectPool<int> pool;  //��Ϊ��int���ͣ�����ÿ�ηָ���ڴ���ƬΪ4���ֽڣ�����ÿ������ OBJ_NEXT �������еĴ�С(4���ֽ�) ��Ϊ��һ���ڴ���Ƭ�ĵ�ַ
	int* p1 = pool.New();
	int* p2 = pool.New();
	
	cout << p1 << endl;
	cout << p2 << endl;
	pool.Delete(p1);
	pool.Delete(p2);
	cout << pool.New() << endl;
	cout << pool.New() << endl;
}