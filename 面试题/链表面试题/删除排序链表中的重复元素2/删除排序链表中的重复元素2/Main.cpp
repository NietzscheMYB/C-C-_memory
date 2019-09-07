#include<stdio.h>
#include<iostream>
// Definition for singly-linked list.
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
		ListNode* p = new ListNode(0);
		p->next = head;

		ListNode* h = p;
		ListNode* p1 = head;
		ListNode* p2 = p1->next;
		ListNode* p3 = head;
		int flag = 0;
		while (p2->next&&p2)
		{
			if (p1->val == p2->val)
			{
				p3 = p2;
				p2 = p2->next;
				flag = 1;
			}
			else{
				if (flag == 0)
				{
					h->next = p1;
					p1 = p1->next;
					p2 = p1->next;
					h = h->next;
				}
				else{
					p1 = p2;
					p2 = p1->next;
					flag = 0;
				}

			}
		}
		if (p3->val == p1->val)
		{
			h->next = nullptr;
			return p->next;
		}
		else
		{
			h->next = p1;
		}
		 h->next->next=nullptr;
		return p->next;

	}
};