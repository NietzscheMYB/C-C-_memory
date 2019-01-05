#pragma once

//typedef struct SeqList{
//	int array[100];  //�ܴ�100�����ľ�̬˳���
//	int size; //��ʾ��ǰ˳������ж��ٸ���
//	          //˳��Ҳ��ʾ�˼���������±�
//			
//}SeqList;
typedef int SDataType;

typedef struct SeqList{
	SDataType *array;  //ָ����Ͽռ�  ���Ͽ��ٿռ�     //��������
 	int size; //��ʾ��ǰ˳������ж��ٸ���
	//˳��Ҳ��ʾ�˼���������±�

	int capacity;  //����
}SeqList;

//��ʼ��
//seqlist ��һ�������ĵ�ַ
//capacity�ǳ�ʼ���� 
void SeqListInit(SeqList *seqlist, int capacity);

//����
void SeqListDestroy(SeqList *seqlist);

//���Ӳ���
//β��
void SeqListPushBack(SeqList *seqlist, SDataType value);
//ͷ��
void SeqListPushFront(SeqList *seqlist, SDataType value);
//�м���룬��pos���ڵ��±���� value
void SeqListInsert(SeqList *seqlist,int pos,SDataType value);




//ɾ��
//βɾ
void SeqListPopBack(SeqList *seqlist);
//ͷɾ
void SeqListPopFront(SeqList *seqlist);

//ɾ��pos�����±�����
void SeqListErase(SeqList *seqlist, int pos);
//��
//����


//����Ƿ���Ҫ���ݣ������Ҫ���ݾͽ�������
//��֤��������������һ������

static void CheckCapacity(SeqList *seqlist);


//��ӡ

void SeqListPrint(const SeqList*seqlist);

//�޸�pos���ڵ��±������Ϊvalue
void SeqListModify(SeqList *seqlist, int pos, SDataType value);

//����  �ҵ����ص�һ���±� û�ҵ�����-1
int SeqListFind(const SeqList *seqlist, int value);