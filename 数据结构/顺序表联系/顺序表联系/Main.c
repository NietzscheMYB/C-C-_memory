#include "SeqList.h"

void TestSeqList1() {
	SeqList seqlist;
	SeqListInit(&seqlist,5);
	SeqListPushBack(&seqlist, 51);
	SeqListPrint(&seqlist);
	SeqListPushBack(&seqlist, 15);
	SeqListPrint(&seqlist);

	SeqListPushBack(&seqlist, 52);
	SeqListPrint(&seqlist);


	SeqListPushBack(&seqlist, 56);

	SeqListPrint(&seqlist);
	SeqListPushBack(&seqlist, 55);
	SeqListPrint(&seqlist);

	SeqListPushBack(&seqlist, 54);
	SeqListPrint(&seqlist);

	SeqListPushBack(&seqlist, 52);
	SeqListBubbleSort(&seqlist);
	SeqListPrint(&seqlist);


}


int main()
{
	TestSeqList1();
	return 0;
}