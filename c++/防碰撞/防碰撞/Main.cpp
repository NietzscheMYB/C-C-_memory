#include<iostream>
#include<stdio.h>
using namespace std;
int SNR[4][9] = {
	{ 1, 1, 1, 1, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 1, 0, 1, 1 }
};
//�Ƚ��Ա�����ȫ���趨Ϊ1
int SNRMAX[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };

int main()
{
	cout << "ԭ����Ϊ:" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << SNR[i][j];
		}
		cout<< endl;
	}
	cout << endl;


	//�����ײλ
	bool flag = false;   //��ʱ������޳�ͻ
	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			for (int k = j + 1; k<4; k++) 
			{
				if (SNR[k][i] - SNR[j][i] != 0) 
				{
					SNRMAX[i] = 0;
					flag = true;//��־�Ƿ�˴μ�����ײ
				}
			}
		}

		//if (flag) 
		//{
		//	printf("��ײ�����SNRMAX=");
		//	for (int i = 0; i<8; i++) {
		//		printf("%d", SNRMAX[i]);
		//	}
		//	printf("\n");
		//	flag = false;
		//}
	}

	int count = 1;
	//ʶ���ǩ�Ĺ���
	while (1)
	{
		int k = 0;
		if (SNR[0][8] == 0 && SNR[1][8] == 0 && SNR[2][8] == 0 && SNR[3][8] == 0)
			break;
		//ÿ�θı�Ա�SNRMAX[]�е����ݺ������ű�ǩ�Աȣ�ɸѡ�����������ı�ǩ
		for (int j = 0; j<4; j++) 
		{
			//����k�����ǩ��8λ���ݵ�ÿһλȻ����б����Ա�
			//k<8����SNR[j][k]��SNRMAX[k]���жԱȣ���С�ڣ�ѡ�����������ı�ǩ
			for (k = 0; k<8 && SNR[j][k] <= SNRMAX[k]; k++);
			//�����������ұ�־λΪ1����ǩ������Ӧģʽ 
			if (k == 8 && SNR[j][8])
			{
				//for (int i = 0; i<8; i++) {
				//	printf("%d", SNRMAX[i]);
				//}
				printf("��%d���ҵ���\n", count);
				count++;
				for (int m = 0; m<8; m++) {
					printf("%d", SNR[j][m]);
				}
				printf("\n");
				SNR[j][8] = 0;//�������ݽ���������־λ��0
			}
		}
		for (int a = 7; a>-1; a--)
		{
			if (SNRMAX[a] == 0)
			{
				SNRMAX[a] = 1;//��SNRMAX8λ���������ĩλ��0��1�� 
				break;
			}
		}
	}

	return 0;
}