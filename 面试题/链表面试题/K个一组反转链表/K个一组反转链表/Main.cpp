#include<iostream>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode dummy(0);
		ListNode* pre = &dummy;
		ListNode* cur = head;
		ListNode* next = nullptr;
		dummy.next = head;
		int size = 0;
		while (cur != nullptr)
		{
			size++;
			cur = cur->next;
		}
		cur = head;
		for (int i = 0; i<size / k; i++)
		{
			for (int j = 0; j<k - 1; j++)
			{
				next = cur->next;
				cur->next = next->next;
				next->next = pre->next;
				pre->next = next;
			}
			pre = cur;
			cur = pre->next;
		}
		return dummy.next;



	}
};