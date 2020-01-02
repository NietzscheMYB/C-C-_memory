#include<iostream>
#include<stdio.h>
using namespace std;
int SNR[4][9] = {
	{ 1, 1, 1, 1, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 1, 0, 1, 1 }
};
//先将对比数据全部设定为1
int SNRMAX[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };

int main()
{
	cout << "原数据为:" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << SNR[i][j];
		}
		cout<< endl;
	}
	cout << endl;


	//检测碰撞位
	bool flag = false;   //此时最初是无冲突
	for (int i = 0; i<8; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			for (int k = j + 1; k<4; k++) 
			{
				if (SNR[k][i] - SNR[j][i] != 0) 
				{
					SNRMAX[i] = 0;
					flag = true;//标志是否此次检测出碰撞
				}
			}
		}

		//if (flag) 
		//{
		//	printf("碰撞检测结果SNRMAX=");
		//	for (int i = 0; i<8; i++) {
		//		printf("%d", SNRMAX[i]);
		//	}
		//	printf("\n");
		//	flag = false;
		//}
	}

	int count = 1;
	//识别标签的过程
	while (1)
	{
		int k = 0;
		if (SNR[0][8] == 0 && SNR[1][8] == 0 && SNR[2][8] == 0 && SNR[3][8] == 0)
			break;
		//每次改变对比SNRMAX[]中的数据后，与四张标签对比，筛选出符合条件的标签
		for (int j = 0; j<4; j++) 
		{
			//定义k代表标签的8位数据的每一位然后进行遍历对比
			//k<8并且SNR[j][k]与SNRMAX[k]进行对比，若小于，选出符合条件的标签
			for (k = 0; k<8 && SNR[j][k] <= SNRMAX[k]; k++);
			//符合条件并且标志位为1，标签处在响应模式 
			if (k == 8 && SNR[j][8])
			{
				//for (int i = 0; i<8; i++) {
				//	printf("%d", SNRMAX[i]);
				//}
				printf("第%d次找到了\n", count);
				count++;
				for (int m = 0; m<8; m++) {
					printf("%d", SNR[j][m]);
				}
				printf("\n");
				SNR[j][8] = 0;//处理数据结束，将标志位置0
			}
		}
		for (int a = 7; a>-1; a--)
		{
			if (SNRMAX[a] == 0)
			{
				SNRMAX[a] = 1;//将SNRMAX8位数字中最靠近末位的0置1， 
				break;
			}
		}
	}

	return 0;
}