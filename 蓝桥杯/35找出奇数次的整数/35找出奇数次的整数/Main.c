//ֻ��һ����������������
//һ�����������������ɸ�����������Χ��1��100������98��������������ż���Σ�ֻ���������������������Σ�����1,1,2,2,3,4,5,5��������ҵ�������������ε�������
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int arr[5] = { 0 };
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num = 0;
	for (i = 0; i < 5; i++)
	{
		 num=num^arr[i];
	}
	//num = arr[i];
	printf("%d\n", num);

}