#include <iostream>
using namespace std;
int glo = 1;
static int staticglo = 1;
//void test()
//{
//	static int staticvar = 1;
//	int localval = 1;
//
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pchar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	free(ptr1);
//	free(ptr3);
//}

void test()
{
	//��̬����һ��int���͵Ŀռ�
	int* ptr4 = new int;
	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* ptr5 = new int(10);
	//��̬����һ��ʮ��int���͵Ŀռ�
	int* ptr6 = new int[10];
	delete ptr4;
	delete ptr5; 
	delete[] ptr6;

}

int main()
{
	test();
	return 0;
}