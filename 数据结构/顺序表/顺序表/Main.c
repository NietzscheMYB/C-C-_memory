#include "SeqList.h"

void TestSeqList()
{
	SeqList  seqList;
	SeqListInit(&seqList,100);
	SeqListDestroy(&seqList);

}
int main()
{
	TestSeqList();
}