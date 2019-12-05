#include<iostream>
using namespace std;


struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* ps = new ListNode(0);
		ListNode* pb = new ListNode(0);
		ListNode* pcur1 = ps;
		ListNode* pcur2 = pb;
		while (pHead)
		{
			if (pHead->val<x)
			{
				pcur1->next = pHead;
				pHead = pHead->next;
				pcur1 = pcur1->next;
			}
			else{
				pcur2->next = pHead;
				pHead = pHead->next;
				pcur2 = pcur2->next;
			}
		}
		pcur2->next = nullptr;
		pcur1->next = pb->next;
		return ps->next;
	}
};

int main()
{
	return 0;
}