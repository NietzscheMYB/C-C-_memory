//�󲿷ֺ� ��ǰ׺�͵�����
//1.ǰ׺�����飨��̬���ݣ�
//Ԥ����ʽ �½�һ������
//��ԭʼ���ݵ��ۼӣ�����


//2.�����и������
//��״������Ҫ
//ÿ��ȥ����ԭʼa����  ��״����c
//Ck�ĺ�����ĳ������ĺ�[k-lowbit(k),k]
//lowbit(k)��k�����������һ��1���������
//����lowbit(6) -��2
//C6  sum(4,6]  ��6����6����ƽ�2��


//index ���Ķ�  index+lowbit(index)
//101->110 ��5��Ӱ��6����
//110->1000��6Ӱ��8    ���ǵ�һ��������1�������


//C1 C3  C5 ��  ������ֻ�������Լ���ǰ�ƽ�һλ //a1�ƶ�Ӱ��c1
//C6
//2���� ��������

//S10=c10+c8

//4~6=getsum(6)-getsum(4)


#include <iostream>
using namespace std;

int lowbit(int n)
{
	return n - (n&(n - 1));
}
//ԭʼ����i��λ������v�� ����c����  n�Ǳ߽�
void updata(int n,int i, int v, int c[])
{
	//int lb = lowbit(i);
	for (int k = i; k <= n; k += lowbit(k))
	{
		c[k] += v;
	}
}

//��ǰ����֮��
int getSum(int c[], int i)
{
	int sum = 0;
	for (int k = i; k >= 1; k -= lowbit(k))
	{
		sum += c[k];
	}
	return sum;
}


//��Ŀ
//for��ÿһλ
//for(�Ҳ��С

//1.h������״������±�
//2.��˳��Ϊ��߼���
//��3 ����a[3]=1����ʱͳ��
//sum3=1,֤��<=3�������+1��1-1=0��˵����ǰ�����3��ĸ���Ϊ0
int main()
{
	int n;
	scanf("%d", &n);

}