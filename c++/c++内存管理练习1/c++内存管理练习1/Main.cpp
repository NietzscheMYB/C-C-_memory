#include <iostream>
//ͨ��new��delete���������ж�̬�ڴ����
//void Test()
//{
//	int* ptr4 = new int;
//	//��̬����һ��int���͵Ŀռ�
//
//	int* ptr5 = new int(10);
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//
//	int* ptr6 = new int[10];
//	//��̬����10��int���͵Ŀռ�
//
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//new delete �ǲ�����������

//������ͷŵ���Ԫ�صĿռ䣬��new��delete������
//������ͷ������Ŀռ�ʹ��new[],delete[]
//using namespace std;
//
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
//
//private:
//	int _data;
//};
//
//void Test2()
//{
//	//���뵥��Test���͵Ŀռ�
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	//����10��Test���͵Ŀռ�
//	Test* p2 = (Test*)malloc(sizeof(Test)*10);
//	free(p2);
//
//	//���뵥��Test���͵Ķ���
//	Test* p3 = new Test;
//	delete p3;
//	//����10��Test���͵Ķ���
//	Test* p4 = new Test[10];
//	delete[] p4;
//}
//
////�������Զ������͵Ŀռ�ʱ��new����ù��캯��
////delete ���������������
////��malloc��free����
//
//int main()
//{
//	Test2();
//	return 0;
//}

//new ��delete���û����ж�̬�ڴ�������ͷŵ������
//operator new��operator delete��ϵͳ�ṩ��ȫ�ֺ���
//new�ڵײ����operator newȫ�ֺ���������ռ�
//delete�ڵײ�ͨ��operator deleteȫ�ֺ������ͷſռ�


//operator new:�ú���ʵ��ͨ��malloc ������ռ�
//��malloc����ռ�ɹ�ʱ��ֱ�ӷ��أ�����ռ�ʧ�ܣ�
//������ִ�У������Ӧ�Դ�ʩ�û����ã���������룬�����׳��쳣

//operator delete �ú���������ͨ��free���ͷſռ�


