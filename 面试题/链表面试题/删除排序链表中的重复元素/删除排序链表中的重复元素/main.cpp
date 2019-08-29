#include<iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		int count = 0;
		ListNode* cur = head;
		ListNode* pre = head;
		while (cur)
		{
			cur = cur->next;
			count++;
		}
		cur = head;
		while (count&&cur->next&&cur)
		{
			if (cur->val == cur->next->val)
			{
				if (cur->next->next != nullptr)
				{
					cur->next = cur->next->next;
				}
				else
				{
					cur->next = nullptr;
					return head;
				}

			}
			pre = cur;
			cur = cur->next;
			if (cur->val == pre->val)
			{
				cur = pre;
			}
			count--;
		}
		return head;
	}
};