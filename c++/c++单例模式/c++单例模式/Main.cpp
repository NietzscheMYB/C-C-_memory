//#include <iostream>
//using namespace std;
//����ģʽ
//�ŵ㣺��
//ȱ�㣺���ܻᵼ�½�����������������ж������
//�����ʵ������˳��ȷ��
//class Singleton{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	//���캯��˽��
//	Singleton(){};
//
//	//c++98 ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	//or
//	//c++11
//	/*Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;*/
//
//	static Singleton m_instance;
//};
//
//Singleton Singleton::m_instance;//�ڳ������֮ǰ����ɵ�������ĳ�ʼ��
//
//int main()
//{
//	Singleton* ps = Singleton::GetInstance();
//}


//����ģʽ
//�ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��أ��������ʵ������˳��������ɿ���
//ȱ�㣺����
//#include<iostream>
//#include<mutex>
//#include<thread>
//using namespace std;
//
//class Singleton{
//public:
//	static Singleton* GetInstance()
//	{
//		//ע������һ��Ҫʹ��doule��check�ķ�ʽ���������ܱ�֤Ч�ʺ��̵߳İ�ȫ
//		if (nullptr == m_pInstance)
//		{
//			m_mtx.lock();
//			if (nullptr == m_pInstance)
//			{
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	//ʵ��һ����Ƕ����������
//	class CGarbo{
//	public:
//		~CGarbo()
//		{
//			if (Singleton::m_pInstance)
//			{
//				delete Singleton::m_pInstance;
//			}
//		}
//	};
//	
//	//����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//
//private:
//	//���캯��˽��
//	Singleton(){};
//
//	//������
//	Singleton(const Singleton&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance;//��������ָ��
//	static mutex m_mtx; //������
//};
//
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;

#include<iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];//4G=4*1024*1024*1024
	cout << "new:" << p << endl;
	return 0;
}




