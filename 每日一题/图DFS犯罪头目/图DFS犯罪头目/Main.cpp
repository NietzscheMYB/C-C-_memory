#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 2010;//������
const int INF = 1000000000;//�����

map<int, string> intToString;//���->����
map<string, int> stringToInt;//����->���
map<string, int> Gang;//head->����

int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//�ڽӾ���G����Ȩweight
int n, k, numPerson = 0;//����n������k��������numPerson
bool vis[maxn] = { false };//��� �Ƿ񱻷���

//DFS�������ʵ�����ͨ�飬nowVisitΪ��ǰ���ʵı��
//headΪͷĿ��numMemberΪ��Ա��ţ�totalValueΪ��ͨ����ܱ�Ȩ
void DFS(int nowVisit,int&head,int&numMember,int& totalValue)
{
	numMember++; //��Ա����+1
	vis[nowVisit] = true;//���nowVisit�ѷ���
	if (weight[nowVisit] > weight[head])
	{
		head = nowVisit;//��ǰ���ʽڵ�ĵ�Ȩ����ͷĿ�ĵ�Ȩ�������ͷĿ
	}
	for (int i = 0; i < numPerson; i++)//ö��������
	{
		if (G[nowVisit][i]>0) //�����nowVisit�ܵ���i
		{
			totalValue += G[nowVisit][i];//��ͨ����ܱ�Ȩ���Ӹñ�Ȩ
			G[nowVisit][i] = G[i][nowVisit] = 0;//ɾ�������ߣ���ֹ��ͷ
			if (vis[i] == false)
			{
				//���iδ�����ʣ���ݹ����i
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

//DFSTrave ������������ͼ����ȡÿ����ͨ�����Ϣ
void DFSTrave()
{
	for (int i = 0; i < numPerson; i++) //ö��������
	{
		if (vis[i] == false)//���iδ������
		{
			int head = i, numMember = 0, totalValue = 0;//ͷĿ����Ա�����ܱ�Ȩ
			DFS(i, head, numMember, totalValue);//����i���ڵ���ͨ��
			if (numMember>2 && totalValue > k)//��Ա������2���ܱ�Ȩ����k
			{
				//head����ΪnumMember
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

//change������������str��Ӧ�ı��
int change(string str)
{
	if (stringToInt.find(str) != stringToInt.end())
	{
		//���str�Ѿ����ֹ�
		return stringToInt[str];//���ر��
	}
	else{
		stringToInt[str] = numPerson;//str�ı��ΪnumPerson
		intToString[numPerson] = str;//numPerson��Ӧstr
		return numPerson++;//������+1
	}
}

int main()
{
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;//����ߵ������˵�͵�Ȩ
		int id1 = change(str1);//��str1ת��Ϊ���id1
		int id2 = change(str2);//��str2תΪ���id2
		weight[id1] += w;//id1�ĵ�Ȩ����w
		weight[id2] += w;//id2�ĵ�Ȩ����w
		G[id1][id2] += w;//��id1->id2�ı�Ȩ����w
		G[id2][id1] += w;//��id2->id1�ı�Ȩ����w
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}