#include <iostream>
using namespace std;
//int main()
//{
//	int *p = new int(10);
//	int *p2 = new int[10];
//	delete p;
//	delete[]p2;
//}

//new delete �ǲ�������new��ʹ�û����ȫ�ֺ���operate new
//operate new�ڵײ�����malloc�������������ʧ�ܣ�����һ��
//���룬�����ʧ�ܷ��ؿ�
//delet ��ʹ�û����ȫ�ֺ���operatr delete 
//operate delete�ڵײ�����free

//�������Զ������͵Ŀռ�ʱ��new����ù��캯��
//delete�����������������
//new---mallco---����
//delete-----����-----free

//��inline���εĺ�������������������c++�������������
//���������ĵط�չ����û�к���ѹջ�Ŀ���
//�������������������е�Ч��

//ֱ��չ����û�к���ѹջ�Ŀ���


//NULLʵ����һ���꣬���ܱ�����Ϊ���泣��0�����߱�����Ϊ
//������ָ�루void*���ĳ���

//c++11�ṩ��nullptr����nullptr����һ��ָ���ֵ����
//nullptr�������͵ģ�������Ϊnullptr_t
//��ʹ��nullptr��ʾָ���ֵʱ������Ҫ����ͷ�ļ�
//��Ϊnullptr��c++11��Ϊ�µĹؼ�������

//�����������������͵Ŀռ䣬new��malloc��delete free
//�������ƣ���ͬ���� new/delete ������ͷŵĵ���
//Ԫ�صĿռ䣬new[]��delete[]���� ���������ռ�
//����new������ռ�ʧ��ʱ�����쳣
//malloc�᷵��NULL

//new T[N]��ԭ��
//����operator new[]��������operator new[]����ʵ�ʵ���
//operator new�������N������ռ������
//������Ŀռ���ִ��N�ι��캯��

//delete[]��ԭ��
//���ͷŵĶ���Ŀռ���ִ��N���������������N�������е���Դ����
//����operator delete[]�ͷſռ䣬ʵ����operator delete[]
//�е���operator delete���ͷſռ�


//��λnew���ʽ�����ѷ����ԭʼ�ڴ�ռ���
//���ù��캯����ʼ��һ������
#include <malloc.h>
//class Test
//{
//public:
//	Test()
//		:_data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void Test1()
//{
//	Test*pt=(Test*)malloc(sizeof(Test));
//	new(pt)Test;
//}
//int main()
//{
//	Test1();
//	return 0;
//}

//���һ���࣬����ֻ���ڶ��ϴ�������

//����1
//1.�����๹�캯��˽�У���������������˽�У����ڱ��˵��ÿ�����ջ�����ɶ���
//2.�ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶѶ���Ĵ���
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(const HeapOnly&);

};


