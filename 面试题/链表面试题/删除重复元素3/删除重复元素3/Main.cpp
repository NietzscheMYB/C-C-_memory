#include<iostream>
using namespace std;

 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* pCur = head->next;
		if(head->val == pCur->val)
		{
			while (pCur&&pCur->val == head->val)
			{
				pCur = pCur->next;
			}
			head = deleteDuplicates(pCur);
		}
		else{
			head->next = deleteDuplicates(pCur);
		}
		return head;
	}
};

int main()
{
	return 0;
}